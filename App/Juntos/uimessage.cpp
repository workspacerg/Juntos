#include "uimessage.h"
#include "ui_uimessage.h"


#include <QDebug>
#include <QColor>
#include <QSize>
#include <QFont>

QString uiMessage::getLogin() const
{
    return login;
}

void uiMessage::setLogin(const QString &value)
{
    login = value;
}

QString uiMessage::getCurrentUserFocus() const
{
    return currentUserFocus;
}

void uiMessage::setCurrentUserFocus(const QString &value)
{
    currentUserFocus = value;
}
uiMessage::uiMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uiMessage)
{
    ui->setupUi(this);
    ui->User->setStyleSheet("QListView {selection-Background-color: rgb(45, 186, 166); }");

    ui->sendMessage->setEnabled(false);

}

uiMessage::~uiMessage()
{
    delete ui;
}

void uiMessage::loadParticipant(vector<cUser> usr)
{

    ui->User->clear();


    for(cUser item : usr)
    {
        if (item.getLogin() == login)
            continue;

        ui->User->addItem(item.getLogin());
    }


}

void uiMessage::loadMessage(vector<cMessage> msg)
{

    ui->Messages->clear();

    for(cMessage item : msg)
    {
        ui->Messages->addItem(item.getDateMessage().toString("HH:mm dd-MM"));
        int LastRow = ui->Messages->count()-1;
        ui->Messages->item(LastRow)->setTextColor(Qt::gray);

        QFont f = ui->Messages->item(LastRow)->font();
        f.setPointSize(10);
        ui->Messages->item(LastRow)->setFont(f);


        ui->Messages->addItem(item.getMessage());
        LastRow = ui->Messages->count()-1;

        if(item.getSender() != login){


            //ui->Messages->item(LastRow)->setBackground(col);
            //ui->Messages->item(LastRow-1)->setBackground(col);

        }
        else{
            QColor col ;
            col.setRgb(45,186,166);
            ui->Messages->item(LastRow)->setTextColor(col);
            ui->Messages->item(LastRow-1)->setTextColor(col);
            ui->Messages->item(LastRow-1)->setTextAlignment(Qt::AlignRight);
            ui->Messages->item(LastRow)->setTextAlignment(Qt::AlignRight);
        }

    }

    ui->Messages->scrollToBottom();
}

void uiMessage::redColor(QString user)
{
    for (int i = 0 ; i < ui->User->count() ; i++ )
    {
        if(ui->User->item(i)->text() == user){
            ui->User->item(i)->setBackgroundColor(Qt::red);
        }
    }

}

void uiMessage::on_User_itemDoubleClicked(QListWidgetItem *item)
{
    ui->Messages->clear();

    for (int i = 0 ; i < ui->User->count() ; i++ )
    {
        if(ui->User->item(i)->text() == item->text()){
            ui->User->item(i)->setBackgroundColor(Qt::white);
        }
    }

    ui->Messages->addItem(item->text());
    int LastRow = ui->Messages->count()-1;
    ui->Messages->item(LastRow)->setTextAlignment(Qt::AlignCenter);

    emit changeListMessage(item->text());

    currentUserFocus = item->text();

}

void uiMessage::on_sendMessage_clicked()
{

    if (ui->myMessage->text() == ""){
        return ;
    }

    emit sendMessageTo(ui->myMessage->text(), ui->User->currentItem()->text());
    emit on_User_itemDoubleClicked(ui->User->currentItem());
    ui->myMessage->setText("");

}

void uiMessage::on_User_itemSelectionChanged()
{
    if(ui->User->selectedItems().size()==0)
        ui->sendMessage->setEnabled(false);
    else
        ui->sendMessage->setEnabled(true);
}
