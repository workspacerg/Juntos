#include "addpeopledialog.h"
#include "ui_addpeopledialog.h"
#include <QDebug>

addPeopleDialog::addPeopleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPeopleDialog)
{
    ui->setupUi(this);


    QStringList test            ;
    test <<"login"<<"mail"  ;
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->setHorizontalHeaderLabels(test);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");

}


addPeopleDialog::~addPeopleDialog()
{
    delete ui;
}

void addPeopleDialog::loadParticipant(vector<cUser> usr)
{

    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }

    for(cUser item : usr)
    {

        int LastRow = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(LastRow);
        ui->tableWidget->setItem(LastRow, 0, new QTableWidgetItem(item.getLogin()));
        ui->tableWidget->setItem(LastRow, 1, new QTableWidgetItem(item.getMail()));

    }




}

void addPeopleDialog::disableModification()
{
    ui->modCenter->setEnabled(false);
    ui->add->hide();
    ui->dell->hide();
    ui->lineEdit->hide();
}

void addPeopleDialog::on_add_clicked()
{
     if(ui->lineEdit->text() != ""){
          emit sigAddUserToProject(ui->lineEdit->text());
     }

}

void addPeopleDialog::on_dell_clicked()
{
    QString content = ui->lineEdit->text() ;
    if(!content.isEmpty()){
        emit sigDelUserToProject(ui->lineEdit->text());
    }

}
