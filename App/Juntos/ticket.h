#ifndef TICKET_H
#define TICKET_H


#include <QString>

#include <QDateTime>


class Ticket
{

    QString idTicket;
    QString nameTicket;
    QString descrTicket;
    QString createName;

public:

    Ticket(QString idT, QString nameT, QString descrT , QString createUser);

    QString getIdTicket() const;
    void setIdTicket(const QString &value);
    QString getNameTicket() const;
    void setNameTicket(const QString &value);
    QString getDescrTicket() const;
    void setDescrTicket(const QString &value);
    QString getCreateName() const;
    void setCreateName(const QString &value);
};

#endif // TICKET_H
