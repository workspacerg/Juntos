#include "bdd.h"

BDD::BDD()
{

}

bool BDD::connectDB()
{
    if(db.isOpen())
        db.close();

    // Connection à la base de donnée.
    // Ouverture du fichier INI
    QSettings settings("config.ini", QSettings::IniFormat);
    QString user = settings.value("bddConfig/user","config").toString();
    QString password = settings.value("bddConfig/password","config").toString();


    db = QSqlDatabase::addDatabase("QODBC3");
    db.setDatabaseName("juntos_connect");
    db.setUserName(user);
    db.setPassword(password);

    return (db.open())?true:false;
}


