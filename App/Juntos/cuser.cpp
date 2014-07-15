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

int cUser::getIdUser() const
{
    return idUser;
}

void cUser::setIdUser(int value)
{
    idUser = value;
}
cUser::cUser()
{
}

cUser::cUser(QString log, QString email)
{
    login = log;
    mail = email;
}

cUser::cUser(int id, QString log, QString email)
{
    idUser = id;
    login = log;
    mail = email;
}

void cUser::loadAllParam(int _id, QString _login, QString _mail)
{
    idUser  = _id;
    login   = _login;
    mail    = _mail;
}
