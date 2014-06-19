#ifndef BDD_H
#define BDD_H


#include <iostream>
#include <QtSql/QSqlDatabase>
#include <qstring.h>
#include <QSettings>
class BDD
{
            QSqlDatabase db;

            QString dataBaseName ;
            QString dataBaseType ;
            QString userName ;
            QString keypass ;

public:

    BDD();
    bool connectDB();



};

#endif // BDD_H
