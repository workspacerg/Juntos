#include "uifile.h"
#include "ui_uiFile.h"
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <QFileDialog>
#include <sstream>
#include <map>
#include <QMessageBox>

uiFile::uiFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uiFile)
{
    ui->setupUi(this);
    ui->tableWidgetShare->verticalHeader()->setVisible(false);
    ui->tableWidgetShare->setShowGrid(false);

    QStringList test ;
    test <<"id"<<"Posté par"<<"Fichier"  ;
    ui->tableWidgetShare->setColumnCount(3);
    ui->tableWidgetShare->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetShare->setColumnHidden(0,true);
    ui->tableWidgetShare->setColumnWidth(1, 200);
    ui->tableWidgetShare->setHorizontalHeaderLabels(test);
    ui->tableWidgetShare->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetShare->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");
}

uiFile::~uiFile()
{
    delete ui;
}

void uiFile::loadTable(std::map<Share, QString> Source)
{
    map = Source;

    while (ui->tableWidgetShare->rowCount() > 0)
    {
        ui->tableWidgetShare->removeRow(0);
    }

    for (std::map<Share,QString>::iterator it=map.begin(); it!=map.end(); ++it)
    {
        int LastRow = ui->tableWidgetShare->rowCount();
        ui->tableWidgetShare->insertRow(LastRow);
        ui->tableWidgetShare->setItem(LastRow,0,new QTableWidgetItem(QString::number(it->first.getId())));
        ui->tableWidgetShare->setItem(LastRow, 1, new QTableWidgetItem(it->second));
        ui->tableWidgetShare->setItem(LastRow, 2, new QTableWidgetItem(QString::fromStdString(it->first.getFilename())));
    }

    ui->DownloadButton->setEnabled(false);
}

void uiFile::on_BrowseButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open file"),"C://","All files (*.*)");
    if(!filename.isEmpty())
        ui->lineEdit->setText(filename);
}

void uiFile::on_uploadButton_clicked()
{
    std::string filepath = ui->lineEdit->text().toStdString();
    if(!filepath.empty() && fileExists(filepath))
        uploadFile(filepath);
    else
        QMessageBox::information(this,"Fichier manquant","Veuillez séléctionner un fichier éxistant");

    ui->lineEdit->clear();
}

void uiFile::on_DownloadButton_clicked()
{
    int id = ui->tableWidgetShare->item( current_item->row() , 0)->text().toInt();
    QString filename = ui->tableWidgetShare->item( current_item->row() , 2)->text();
    QString extension = QFileInfo(filename).suffix();
    QByteArray content;
    for (std::map<Share,QString>::iterator it=map.begin(); it!=map.end(); ++it)
    {
        if(id == it->first.getId()){
            content = it->first.getContent();
            break;
        }
    }

    downloadFile(content,extension);
}

bool uiFile::fileExists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}

void uiFile::uploadFile(const std::string& filepath){
    std::ifstream inputFile(filepath, std::ios::binary | std::ios::ate);

    inputFile.seekg(0, std::ios::end);
    int length = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);
    std::string fileContents;
    fileContents.resize(length);
    inputFile.read(&fileContents[0], length);
    inputFile.close();

    QByteArray array = QByteArray(fileContents.c_str(),length);
    QFileInfo fi(QString::fromStdString(filepath));
    emit add_share(fi.fileName().toStdString(),array);
}

void uiFile::downloadFile(QByteArray content,QString extension){
    QString filepath = QFileDialog::getSaveFileName(this,tr("Sauvegarder en tant que..."),"C://","."+extension);
    QFileInfo fi(filepath);
    if(fi.suffix().isEmpty())
        filepath += "."+extension;

    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    file.write(content);
    file.close();
}


void uiFile::on_tableWidgetShare_itemClicked(QTableWidgetItem *item)
{
    current_item = item;
}

void uiFile::on_tableWidgetShare_itemSelectionChanged()
{
    if(ui->tableWidgetShare->selectedItems().size()==0)
        ui->DownloadButton->setEnabled(false);
    else
        ui->DownloadButton->setEnabled(true);
}
