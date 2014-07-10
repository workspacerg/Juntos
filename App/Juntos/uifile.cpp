#include "uifile.h"
#include "ui_uiFile.h"
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

uiFile::uiFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uiFile)
{
    ui->setupUi(this);
}

uiFile::~uiFile()
{
    delete ui;
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
}

void uiFile::on_DownloadButton_clicked()
{
    QString filepath = QFileDialog::getSaveFileName(this,tr("Sauvegarder en tant que..."),"C://",".docx");
    QFileInfo fi(filepath);
    if(fi.suffix().isEmpty())
        filepath += ".docx";

    /*std::ofstream outputFile(filepath, std::ios::app | std::ios::binary);
    outputFile.write(&fileContents[0], length);
    outputFile.close();*/
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
    std::ifstream inputFile(filepath, std::ios::in | std::ios::binary);
    inputFile.seekg(0, std::ios::end);
    int length = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);
    std::string fileContents;
    fileContents.resize(length);
    inputFile.read(&fileContents[0], length);
    inputFile.close();


    // SAUVEGARDER LE SHARED
    /*QMessageBox::information(this,"blah",fileContents.c_str());
    qDebug()<< fileContents.c_str();*/

    /*std::ofstream outputFile("C:\\Users\\Rayane\\Desktop\\TestCopy.docx", std::ios::app | std::ios::binary);
    outputFile.write(&fileContents[0], length);
    outputFile.close();*/
}

void uiFile::downloadFile(const std::string& filename, std::string contents){
    /*std::ofstream file(filename.c_str(), std::ios::binary);
        for ( std::size_t byte = 0; byte < contents.size(); byte += 8 ) {
            file.put( std::bitset< 8 >( contents, byte, // convert one byte
              std::min( (std::size_t) 8, contents.size() - byte ) // or as many bits as are left
              .to_ulong() ); // to two's complement representation
        }*/
}
