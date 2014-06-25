#include "bdd.h"
#include <QMessageBox>
#include <QDebug>

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


        if(query.exec("select check_param_user('"+login+"', '"+password+"')"))
        {
            while (query.next()) {
               if(query.value(0).toInt() == 1)
               {
                   return true;
               }
               else
               {
                   return false;
               }
            }


        }else
        {
            qDebug() << query.lastError().text();
        }

        return false;

        //        if(query.exec("SELECT * FROM `user` WHERE `login` = '"+login+"' AND `keypass` ='"+password+"'"))
        //        {
        //            while(query.next())
        //            {
        //                return true;
        //            }
        //        }

        //        return false;

}



vector<CProjet> BDD::loadProject()
{
    projects.clear();


    // Chargement des projet

     QSqlQuery query;
    if(query.exec("SELECT pr.id , pr.name , pr.description FROM user u INNER JOIN userinproject up ON u.id = up.idUser INNER JOIN project pr ON up.idProject = pr.id where u.login = '"+ login +"'"))
    {
        while(query.next())
        {
           projects.push_back(CProjet(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString()));

        }
    }

    return projects;
}

bool BDD::addProject(CProjet source)
{

    QSqlQuery query;

    if(query.exec("select insert_new_project('"+ source.getNomProjet() +"', '"+source.getDescProjet()+"' , '" + login + "')"))
    {

        while (query.next()) {
           if(query.value(0).toInt() == 1){
               return true;
           }
           else {
               return false;
           }
        }

    }else
    {
        qDebug() << query.lastError().text();
    }
     return false;

//    if(query.exec("INSERT INTO `project` (`id`, `name`, `description`) VALUES (NULL, '"+source.getNomProjet()+"', '"+source.getDescProjet()+"')"))
//    {
//        if(query.exec("INSERT INTO `userinproject` (`id`, `idUser`, `idProject`, `admin`) VALUES (NULL, (SELECT id FROM `user` WHERE `login` = '"+login+"'), (SELECT id FROM `project` ORDER BY `id` DESC LIMIT 1 ) , 1 )"))
//        {


//            return true ;
//        }
//    }

//    return false;

}

bool BDD::delProject(CProjet source)
{
    QSqlQuery query;

    if(query.exec("select del_project('"+login+"','" + source.getNomProjet() +"')"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){
               return true;
           }
           else {
               return false;
           }
        }

    }else
    {
        qDebug() << query.lastError().text();
    }
     return false;


//    if( query.exec("DELETE FROM `project` WHERE `name` = '"+source.getNomProjet()+"'") )
//    {
//    }
}

CProjet  BDD::getInfoProjet(CProjet  source)
{


    QSqlQuery query;
   if(query.exec("Select * FROM project where name='"+ source.getNomProjet() +"'"))
   {
       while(query.next())
       {
            return CProjet(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString());
       }

   }

     return CProjet(0,"Erreur","Erreur lors de la récuperation");

}

vector<cUser> BDD::getParticipant(int idPro)
{

    vector<cUser> usr ;

    QString idString = QString::number(idPro);

    QSqlQuery query;
    if(query.exec("SELECT DISTINCT login, mail  FROM `user`  Inner join `userinproject` up on `user`.id = up.idUser   inner join `project` pr on up.idProject = pr.id  where pr.id = '"+ idString +"' "))
    {
        while(query.next())
        {
           qDebug() << query.value(0).toString() ;
           qDebug() << query.value(1).toString() ;
           usr.push_back(cUser(query.value(0).toString(),query.value(1).toString()));

        }
    }

    return usr;

}

bool BDD::checkAdmin(int idPro)
{
    QString idString = QString::number(idPro);

    QSqlQuery query;

    if(query.exec("select check_user_admin('"+login+"', '"+idString+"')"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){
               return true;
           }
           else {
               return false;
           }
        }


    }else
    {
        qDebug() << query.lastError().text();
    }
     return false;

//   if(query.exec("SELECT *  FROM `user`  Inner join `userinproject` up on `user`.id = up.idUser   inner join `project` pr on up.idProject = pr.id  where pr.id = '"+ idString +"' and  up.admin = 1  and user.login = '"+login+"' "))
//   {

//       while (query.next()) {
//            return true;
//       }

//   }
//   else
//       qDebug() << "error sql : " << query.lastError().text();

//   return false;

}

bool BDD::addPeopleToProject(QString log, int idPro)
{

    QString idString = QString::number(idPro);
    QSqlQuery query;

    if(query.exec("select insert_people_to_project('"+ login +"', '"+ log +"' , '"+idString+"' )"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){
               return true;
           }
           else {
               return false;
           }
        }

    }else
    {
        qDebug() << query.lastError().text();
    }
     return false;

//    if(query.exec("INSERT INTO `userinproject` (`id`, `idUser`, `idProject`, `admin`) VALUES (NULL, (select id from user where login = '" + log + "' ), '"+ idString +"', '0')"))
//    {

//    }
//    else
//    {
//        qDebug() << "Erreur insert new people in project";
//    }


}

bool BDD::delPeopletoProject(QString log, int idPro)
{

    QString idString = QString::number(idPro);
    QSqlQuery query;

    if(query.exec("select del_user_project('"+ login +"', '"+ log +"', '"+ idString +"')"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){
               return true;
           }
           else {
               return false;
           }
        }

    }else
    {
        qDebug() << query.lastError().text();
    }
     return false;

//    if(query.exec("DELETE FROM `userinproject` WHERE `idProject` =  '"+ idString +"' and `idUser` = (select id from user where login =  '" + log + "' )" ))
//    {

//    }
//    else
//    {
//        qDebug() << "Erreur delete people in project";
//    }

}


// Ticket-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

vector<CTicket> BDD::loadTicket( int idPro )
{

    vector<CTicket> tickets;


    // Chargement des projet

    QSqlQuery query;
    if(query.exec("SELECT tk.idProject, pro.name , tk.name, tk.description, tk.createBy , u2.login as 'Createur', tk.dateLog, tk.dateDone , tk.dateAssignTo, tk.assignToUser , u.login as 'Dev' , e.name , tp.nom FROM task tk   INNER JOIN project pro ON pro.id = tk.idProject  INNER JOIN etat e ON e.id = tk.Etat  INNER JOIN type tp ON tp.id = tk.idType   INNER JOIN user u ON u.id = tk.assignToUser  INNER JOIN user u2 ON u2.id = tk.createBy  WHERE pro.id = 1 AND tp.nom = 'ticket';"))
    {
        while(query.next())
        {

            qDebug() << query.value(0).toString()<< query.value(1).toString() << query.value(2).toString()<< query.value(3).toString()<< query.value(4).toString()<< query.value(5).toString()<< query.value(6).toDateTime()<< query.value(7).toDateTime()<< query.value(8).toDateTime()<< query.value(9).toString()<< query.value(10).toString()<< query.value(11).toString();

//            tickets.push_back(CTicket(query.value(0).toString(),
//                                      query.value(1).toString(),
//                                      query.value(2).toString(),
//                                      query.value(3).toString(),
//                                      query.value(4).toString(),
//                                      query.value(5).toString(),
//                                      query.value(6).toDateTime(),
//                                      query.value(7).toDateTime(),
//                                      query.value(8).toDateTime(),
//                                      query.value(9).toString(),
//                                      query.value(10).toString(),
//                                      query.value(11).toString()
//                                      )
//                              );





        }
    }

    return tickets;

}




