#include "formaddtodo.h"
#include "ui_formaddtodo.h"

formAddTodo::formAddTodo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formAddTodo)
{
    ui->setupUi(this);
}

formAddTodo::~formAddTodo()
{
    delete ui;
}

void formAddTodo::loadComboBox(vector<cUser> usr, vector<QString> avc)
{

    ui->usrComboBox->addItem("");
    for(cUser item : usr)
    {
        ui->usrComboBox->addItem(item.getLogin());
    }


    for(QString item : avc)
    {
        ui->etatComboBox->addItem(item);
    }

}

void formAddTodo::on_save_clicked()
{

    emit savetodatabase( ui->titleTicket->text() , ui->description->toPlainText() , ui->usrComboBox->currentText() , ui->etatComboBox->currentText() , ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss") );

}

void formAddTodo::closeEvent(QCloseEvent *event)
{
    delete this;
}
