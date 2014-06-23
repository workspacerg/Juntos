#ifndef CUSER_H
#define CUSER_H

#include <QString>

class cUser
{
private:
    QString login;
    QString mail;

public:
    cUser();
    cUser(QString log, QString email);


    QString getLogin() const;
    void setLogin(const QString &value);
    QString getMail() const;
    void setMail(const QString &value);
};

#endif // CUSER_H
