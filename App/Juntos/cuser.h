#ifndef CUSER_H
#define CUSER_H

#include <QString>

class cUser
{
private:
    QString login;

public:
    cUser();


    QString getLogin() const;
    void setLogin(const QString &value);
};

#endif // CUSER_H
