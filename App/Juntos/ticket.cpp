#include "ticket.h"



QString Ticket::getIdTicket() const
{
    return idTicket;
}

void Ticket::setIdTicket(const QString &value)
{
    idTicket = value;
}

QString Ticket::getNameTicket() const
{
    return nameTicket;
}

void Ticket::setNameTicket(const QString &value)
{
    nameTicket = value;
}

QString Ticket::getDescrTicket() const
{
    return descrTicket;
}

void Ticket::setDescrTicket(const QString &value)
{
    descrTicket = value;
}

QString Ticket::getCreateName() const
{
    return createName;
}

void Ticket::setCreateName(const QString &value)
{
    createName = value;
}

QString Ticket::getCreateDt() const
{
    return createDt;
}

void Ticket::setCreateDt(const QString &value)
{
    createDt = value;
}


QString Ticket::getSetUserDate() const
{
    return setUserDate;
}

void Ticket::setSetUserDate(const QString &value)
{
    setUserDate = value;
}

QString Ticket::getDev() const
{
    return dev;
}

void Ticket::setDev(const QString &value)
{
    dev = value;
}

QString Ticket::getEtat() const
{
    return etat;
}

void Ticket::setEtat(const QString &value)
{
    etat = value;
}

QString Ticket::getEndDate() const
{
    return endDate;
}

void Ticket::setEndDate(const QString &value)
{
    endDate = value;
}
Ticket::Ticket()
{

}

Ticket::Ticket(QString idT, QString nameT, QString descrT, QString createUser, QString dtCreate, QString setUserDt, QString devName, QString etatTk)
{

    idTicket = idT ;
    nameTicket = nameT ;
    descrTicket = descrT ;
    createName = createUser;
    createDt =  dtCreate ;
    setUserDate = setUserDt ;
    dev = devName ;
    etat = etatTk ;

}
