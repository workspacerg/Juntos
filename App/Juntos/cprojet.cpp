#include "cprojet.h"


CProjet::CProjet(QString nom, QString descr)
{

    NomProjet   = nom    ;
    DescProjet  = descr  ;

}

CProjet::CProjet(int id, QString nom, QString descr)
{
    this->id = id;
    NomProjet   = nom    ;
    DescProjet  = descr  ;
}

CProjet::CProjet(const CProjet &Source)
{

    id = Source.getId();
    NomProjet   = Source.getNomProjet()  ;
    DescProjet  = Source.getDescProjet() ;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Getter et setter de la classe cProjet

QString CProjet::getNomProjet() const
{
    return NomProjet;
}

void CProjet::setNomProjet(const QString &value)
{
    NomProjet = value;
}
QString CProjet::getDescProjet() const
{
    return DescProjet;
}

void CProjet::setDescProjet(const QString &value)
{
    DescProjet = value;
}
vector<cUser> CProjet::getUsers() const
{
    return users;
}

void CProjet::setUsers(const vector<cUser> &value)
{
    users = value;
}
int CProjet::getId() const
{
    return id;
}

void CProjet::setId(int value)
{
    id = value;
}

void CProjet::addUser(cUser source)
{
    users.push_back(source);
}






