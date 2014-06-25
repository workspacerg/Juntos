#include "cticket.h"


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

QString CTicket::getIdTicket() const
{
    return idTicket;
}

void CTicket::setIdTicket(const QString &value)
{
    idTicket = value;
}

QString CTicket::getIdProject() const
{
    return idProject;
}

void CTicket::setIdProject(const QString &value)
{
    idProject = value;
}

QString CTicket::getIdCreateBy() const
{
    return idCreateBy;
}

void CTicket::setIdCreateBy(const QString &value)
{
    idCreateBy = value;
}

QString CTicket::getIdAssignTo() const
{
    return idAssignTo;
}

void CTicket::setIdAssignTo(const QString &value)
{
    idAssignTo = value;
}

QString CTicket::getNameTicket() const
{
    return nameTicket;
}

void CTicket::setNameTicket(const QString &value)
{
    nameTicket = value;
}

QString CTicket::getDescrTicket() const
{
    return descrTicket;
}

void CTicket::setDescrTicket(const QString &value)
{
    descrTicket = value;
}

QString CTicket::getEtat() const
{
    return etat;
}

void CTicket::setEtat(const QString &value)
{
    etat = value;
}

QDateTime CTicket::getCreateDate() const
{
    return createDate;
}

void CTicket::setCreateDate(const QDateTime &value)
{
    createDate = value;
}

QDateTime CTicket::getAssignDate() const
{
    return assignDate;
}

void CTicket::setAssignDate(const QDateTime &value)
{
    assignDate = value;
}

QDateTime CTicket::getEndDate() const
{
    return endDate;
}

void CTicket::setEndDate(const QDateTime &value)
{
    endDate = value;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CTicket::CTicket()
{

}
