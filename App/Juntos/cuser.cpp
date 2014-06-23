#include "cuser.h"


QString cUser::getLogin() const
{
    return login;
}

void cUser::setLogin(const QString &value)
{
    login = value;
}

QString cUser::getMail() const
{
    return mail;
}

void cUser::setMail(const QString &value)
{
    mail = value;
}
cUser::cUser()
{
}

cUser::cUser(QString log, QString email)
{
    login = log;
    mail = email;
}
