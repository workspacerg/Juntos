#include "uimessage.h"
#include "ui_uimessage.h"


#include <QDebug>
#include <QColor>
#include <QSize>

QString uiMessage::getLogin() const
{
    return login;
}

void uiMessage::setLogin(const QString &value)
{
    login = value;
}
uiMessage::uiMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uiMessage)
{
    ui->setupUi(this);
    ui->User->setStyleSheet("QListView {selection-Background-color: rgb(45, 186, 166); }");


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

void uiMessage::loadMessage(vector<cMessage> msg)
{

    for(cMessage item : msg)
    {
        ui->Messages->addItem(item.getMessage() + "\n" + item.getDateMessage().toString("HH:mm dd-MM"));
        int LastRow = ui->Messages->count()-1;

        if(item.getSender() != login){

            ui->Messages->item(LastRow)->setTextColor(Qt::white);
            QColor col ;
            col.setRgb(45,186,166);
            ui->Messages->item(LastRow)->setBackground(col);
        }
        else{
            ui->Messages->item(LastRow)->setTextAlignment(Qt::AlignRight);
        }



    }
}

void uiMessage::on_User_itemDoubleClicked(QListWidgetItem *item)
{
    ui->Messages->addItem(item->text());
    item->setTextAlignment(Qt::AlignCenter);

    emit changeListMessage(item->text())

}
