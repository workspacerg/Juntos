#include "cprojet.h"

CProjet::CProjet(QWidget *parent) :
    QWidget(parent)
{

    NomProjet   = "vide"    ;
    DescProjet  = ""        ;


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




