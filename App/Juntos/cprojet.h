#ifndef CPROJET_H
#define CPROJET_H

#include <QWidget>
#include <QString>
#include <vector>
#include "cuser.h"

using namespace std;

class CProjet
{

public:

    CProjet(QString nom, QString descr);
    CProjet(const CProjet &Source);


    QString getNomProjet() const;
    void setNomProjet(const QString &value);

    QString getDescProjet() const;
    void setDescProjet(const QString &value);



    vector<cUser> getUsers() const;
    void setUsers(const vector<cUser> &value);


private:

    QString NomProjet       ;
    QString DescProjet      ;
    vector<cUser> users     ;

};

#endif // CPROJET_H
