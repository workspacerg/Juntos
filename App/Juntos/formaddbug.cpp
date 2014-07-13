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

    ui->usrComboBox->addItem("");
    for(cUser item : usr)
    {
        ui->usrComboBox->addItem(item.getLogin());
    }

}

void formAddBug::on_save_clicked()
{

    emit savetodatabase( ui->titleTicket->text() , ui->description->toPlainText() , ui->usrComboBox->currentText() , ui->etatComboBox->currentText() );
}

void formAddBug::closeEvent(QCloseEvent *event)
{
    delete this;
}
