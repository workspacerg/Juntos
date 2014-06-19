#ifndef BDD_H
#define BDD_H


#include <iostream>
#include <QtSql/QSqlDatabase>
#include <qstring.h>
#include <QSettings>
#include <QtSql/QSqlQuery>
#include "cprojet.h"
#include <vector>

using namespace std;

class BDD
{
            QSqlDatabase db;

            QString dataBaseName ;
            QString dataBaseType ;
            QString userBDD ;
            QString passwordBDD ;

            QString login ;
            QString password;

            vector<CProjet> projects ;

public:

    BDD();
    bool connectDB();
    bool verifUser();
    vector<CProjet> loadProject();

};

#endif // BDD_H
