#ifndef BDD_H
#define BDD_H


#include <iostream>
#include <QtSql/QSqlDatabase>
#include <qstring.h>
#include <QSettings>
#include <QtSql/QSqlQuery>

class BDD
{
            QSqlDatabase db;

            QString dataBaseName ;
            QString dataBaseType ;
            QString userBDD ;
            QString passwordBDD ;

            QString login ;
            QString password;

public:

    BDD();
    bool connectDB();
    bool verifUser();

};

#endif // BDD_H
