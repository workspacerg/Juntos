#include "cmessage.h"


QString cMessage::getReceiver() const
{
    return receiver;
}

void cMessage::setReceiver(const QString &value)
{
    receiver = value;
}

QString cMessage::getSender() const
{
    return sender;
}

void cMessage::setSender(const QString &value)
{
    sender = value;
}

QString cMessage::getMessage() const
{
    return message;
}

void cMessage::setMessage(const QString &value)
{
    message = value;
}

QDateTime cMessage::getDateMessage() const
{
    return dateMessage;
}

void cMessage::setDateMessage(const QDateTime &value)
{
    dateMessage = value;
}
cMessage::cMessage()
{
}

cMessage::cMessage(QString _receiver, QString _sender, QString _Message, QDateTime _dateMessage)
{
    receiver = _receiver;
    sender = _sender;
    message = _Message;
    dateMessage = _dateMessage;

}
