#ifndef CMESSAGE_H
#define CMESSAGE_H

#include <qstring.h>
#include <QDateTime>

class cMessage
{

    QString receiver;
    QString sender;
    QString message;
    QDateTime dateMessage;


public:
    cMessage();
    cMessage(QString sender, QString _receiver , QString _Message, QDateTime _dateMessage);

    QString getReceiver() const;
    void setReceiver(const QString &value);
    QString getSender() const;
    void setSender(const QString &value);
    QString getMessage() const;
    void setMessage(const QString &value);
    QDateTime getDateMessage() const;
    void setDateMessage(const QDateTime &value);
};

#endif // CMESSAGE_H
