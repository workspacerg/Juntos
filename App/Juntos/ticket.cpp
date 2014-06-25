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
Ticket::Ticket(QString idT, QString nameT, QString descrT, QString createUser, QString dtCreate, QString setUserDt)
{

    idTicket = idT ;
    nameTicket = nameT ;
    descrTicket = descrT ;
    createName = createUser;
    createDt =  dtCreate ;
    setUserDate = setUserDt ;

}
