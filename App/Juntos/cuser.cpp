#include "cuser.h"


QString cUser::getLogin() const
{
    return login;
}

void cUser::setLogin(const QString &value)
{
    login = value;
}
cUser::cUser()
{
}
