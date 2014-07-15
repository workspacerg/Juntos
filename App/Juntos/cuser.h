#ifndef CUSER_H
#define CUSER_H

#include <QString>

class cUser
{
private:
    int idUser;
    QString login;
    QString mail;

public:
    cUser();
    cUser(QString log, QString email);
    cUser(int id, QString log, QString email);
    void loadAllParam(int _id, QString _login, QString _mail);


    QString getLogin() const;
    void setLogin(const QString &value);
    QString getMail() const;
    void setMail(const QString &value);
    int getIdUser() const;
    void setIdUser(int value);
};

#endif // CUSER_H
