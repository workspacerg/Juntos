#include "uimessage.h"
#include "ui_uimessage.h"

uiMessage::uiMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uiMessage)
{
    ui->setupUi(this);

    ui->Messages->addItem("Je suis un Message");
    ui->Messages->addItem("Je suis un Message 2");

    ui->Messages->itemAt(1,0)->setTextAlignment(Qt::AlignRight);



}

uiMessage::~uiMessage()
{
    delete ui;
}

void uiMessage::loadParticipant(vector<cUser> usr)
{
    for(cUser item : usr)
    {
        ui->User->addItem(item.getLogin());
    }
}
