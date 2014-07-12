#include "cjournal.h"


QString cJournal::getUsr() const
{
    return usr;
}

void cJournal::setUsr(const QString &value)
{
    usr = value;
}

QString cJournal::getUsr2() const
{
    return usr2;
}

void cJournal::setUsr2(const QString &value)
{
    usr2 = value;
}

QString cJournal::getMsg() const
{
    return msg;
}

void cJournal::setMsg(const QString &value)
{
    msg = value;
}

QDateTime cJournal::getDate() const
{
    return date;
}

void cJournal::setDate(const QDateTime &value)
{
    date = value;
}

int cJournal::getId() const
{
    return id;
}

void cJournal::setId(int value)
{
    id = value;
}
cJournal::cJournal()
{
}

cJournal::cJournal(int _id, QString _user , QString _user2 , QString _msg , QDateTime _date)
{
    id = _id;
    usr = _user;
    usr2 = _user2;
    msg = _msg;
    date = _date;
}
