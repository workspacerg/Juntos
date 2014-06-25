#include "formaddbug.h"
#include "ui_formaddbug.h"

formAddBug::formAddBug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formAddBug)
{
    ui->setupUi(this);
}

formAddBug::~formAddBug()
{
    delete ui;
}

void formAddBug::loadParticipant(vector<cUser> usr)
{


//    while (ui->tableWidget->rowCount() > 0)
//    {
//        ui->tableWidget->removeRow(0);
//    }

    for(cUser item : usr)
    {

//        int LastRow = ui->tableWidget->rowCount();
//        ui->tableWidget->insertRow(LastRow);
//        ui->tableWidget->setItem(LastRow, 0, new QTableWidgetItem(item.getLogin()));
//        ui->tableWidget->setItem(LastRow, 1, new QTableWidgetItem(item.getMail()));

        ui->usrComboBox->addItem(item.getLogin());

    }


}

void formAddBug::on_save_clicked()
{

    emit savetodatabase( ui->titleTicket->text(), ui->description->toPlainText() , ui->usrComboBox->currentText() , ui->etatComboBox->currentText() );
}
