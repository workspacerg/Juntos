#include "bdd.h"
#include <QMessageBox>

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



vector<CProjet> BDD::loadProject()
{
    projects.clear();

    QSqlQuery query;
    if(query.exec("Select * FROM project where id in (SELECT `idProject` FROM `userinproject` WHERE `idUser` = (select id from user where login =  '"+login+"'))"))
    {
        while(query.next())
        {
           projects.push_back(CProjet(query.value(1).toString(),query.value(2).toString()));
        }
    }

    return projects;
}

bool BDD::addProject(CProjet source)
{

    QSqlQuery query;

    if(query.exec("INSERT INTO `project` (`id`, `name`, `description`, `dateBegin`, `dateEnd`) VALUES (NULL, '"+source.getNomProjet()+"', '"+source.getDescProjet()+"', NULL, NULL)"))
    {
        if(query.exec("INSERT INTO `userinproject` (`id`, `idUser`, `idProject`) VALUES (NULL, (SELECT id FROM `user` WHERE `login` = '"+login+"'), (SELECT id FROM `project` ORDER BY `id` DESC LIMIT 1 ) )"))
        {


            return true ;
        }
    }

    return false;

}

void BDD::delProject(CProjet source)
{
    QSqlQuery query;

    if( query.exec("DELETE FROM `project` WHERE `name` = '"+source.getNomProjet()+"'") )
    {

    }
}




