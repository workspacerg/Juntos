#include "formupdbug.h"
#include "ui_formupdbug.h"

formUpdBug::formUpdBug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formUpdBug)
{
    ui->setupUi(this);
}

formUpdBug::~formUpdBug()
{
    delete ui;
}

void formUpdBug::loadParticipant(vector<cUser> usr)
{
    for(cUser item : usr)
    {
        ui->usrComboBox->addItem(item.getLogin());
    }

    for(cUser item : usr)
    {
        ui->createComboBox->addItem(item.getLogin());
    }


}

void formUpdBug::loadInfoTicket(Ticket source)
{

idTk = source.getIdTicket();
    ui->titleTicket->setText(source.getNameTicket());
    ui->description->setText(source.getDescrTicket());
    ui->dateCrea->setDateTime(QDateTime::fromString(source.getCreateDt(),"yyyy-MM-ddTHH:mm:ss"));
    ui->dateAssign->setDateTime(QDateTime::fromString(source.getSetUserDate(),"yyyy-MM-ddTHH:mm:ss"));
    ui->dateEnd->setDateTime(QDateTime::fromString(source.getEndDate(),"yyyy-MM-ddTHH:mm:ss"));
    ui->etatComboBox->setCurrentIndex(ui->etatComboBox->findText(source.getEtat()));
    ui->usrComboBox->setCurrentIndex(ui->usrComboBox->findText(source.getDev()));
    ui->createComboBox->setCurrentIndex(ui->createComboBox->findText(source.getCreateName()));


}

void formUpdBug::on_save_clicked()
{
    Ticket bug;

    bug.setIdTicket(idTk);
    bug.setNameTicket(ui->titleTicket->text());
    bug.setDescrTicket(ui->description->toPlainText());
    bug.setCreateName(ui->createComboBox->currentText());
    bug.setDev(ui->usrComboBox->currentText());
    bug.setEtat(ui->etatComboBox->currentText());

    emit save_upd_ticket(bug);

}









