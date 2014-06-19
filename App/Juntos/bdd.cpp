#include "bdd.h"


#define q2c(string) string.toStdString()


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
    userBDD = settings.value("bddConfig/user","config").toString();
    passwordBDD = settings.value("bddConfig/password","config").toString();

    dataBaseType = settings.value("bddConfig/host","QODBC3").toString();
    dataBaseName = settings.value("bddConfig/name","juntos_connect").toString();

    login = settings.value("utilisateur/login","").toString();
    password = settings.value("utilisateur/paswword","").toString();



    db = QSqlDatabase::addDatabase(dataBaseType);
    db.setDatabaseName(dataBaseName);
    db.setUserName(userBDD);
    db.setPassword(passwordBDD);

    return (db.open())?true:false;
}

bool BDD::verifUser()
{

        QSqlQuery query;

        if(query.exec("SELECT * FROM `user` WHERE `login` = '"+login+"' AND `keypass` ='"+password+"'"))
        {
            while(query.next())
            {
                return true;
            }
        }

        return false;
}


