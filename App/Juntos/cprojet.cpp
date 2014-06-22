#include "cprojet.h"


CProjet::CProjet(QString nom, QString descr)
{

    NomProjet   = nom    ;
    DescProjet  = descr  ;

}

CProjet::CProjet(const CProjet &Source)
{

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





