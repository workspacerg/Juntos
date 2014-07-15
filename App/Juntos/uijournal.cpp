#include "uijournal.h"
#include "ui_uijournal.h"
#include <QDebug>

uiJournal::uiJournal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uiJournal)
{
    ui->setupUi(this);


    QStringList head ;
    head <<"login"<<"Impact" << "Date" << "Evenement" ;
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->setHorizontalHeaderLabels(head);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");


}

uiJournal::~uiJournal()
{
    delete ui;
}

void uiJournal::loadJournal(vector<cJournal> j)
{

    // Vide la table
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }

    // Charge la table
    for(cJournal& item : j)
    {
        int LastRow = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(LastRow);
        ui->tableWidget->setItem(LastRow, 0, new QTableWidgetItem(item.getUsr()));
        ui->tableWidget->setItem(LastRow, 1, new QTableWidgetItem(item.getUsr2()));
        ui->tableWidget->setItem(LastRow, 2, new QTableWidgetItem(item.getDate().toString("HH:mm dd-MM")));
        ui->tableWidget->setItem(LastRow, 3, new QTableWidgetItem(item.getMsg()));
     }




}

void uiJournal::closeEvent(QCloseEvent *event)
{
    delete this;
}
