#include "bdd.h"
#include <QMessageBox>
#include <QDebug>

#define q2c(string) string.toStdString()



QString BDD::getLogin() const
{
    return login;
}

void BDD::setLogin(const QString &value)
{
    login = value;
}
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

    QString nomPro = source.getNomProjet();
    QString Descr= source.getDescProjet();

    QRegExp rx( "([^\\\\])'" );
    nomPro.replace( rx, "\\1\\'" );
    Descr.replace( rx, "\\1\\'" );


    QSqlQuery query;

    if(query.exec("select insert_new_project('"+ nomPro +"', '"+ Descr +"' , '" + login + "')"))
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

}

bool BDD::delProject(CProjet source)
{
    QSqlQuery query;

    QString nomPro = source.getNomProjet();
    QString Descr= source.getDescProjet();

    QRegExp rx( "([^\\\\])'" );
    nomPro.replace( rx, "\\1\\'" );
    Descr.replace( rx, "\\1\\'" );

    if(query.exec("select del_project('"+login+"','" + nomPro +"')"))
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

}

CProjet  BDD::getInfoProjet(CProjet  source)
{


    QString nomPro = source.getNomProjet();
    QString Descr= source.getDescProjet();

    QRegExp rx( "([^\\\\])'" );
    nomPro.replace( rx, "\\1\\'" );
    Descr.replace( rx, "\\1\\'" );


    QSqlQuery query;
   if(query.exec("Select * FROM project where name='"+ nomPro +"'"))
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

}

cUser BDD::getInfoUser(QString _log)
{

   QSqlQuery query;
   if(query.exec("Select * FROM user where login ='"+ _log +"'"))
   {
       while(query.next())
       {
            return cUser(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString());
       }

   }

     return cUser();

}


cUser BDD::getInfoUserById(int id){
    QSqlQuery query;

    if(query.exec(QString("Select * FROM user where id =%1").arg(id)))
    {
        while(query.next())
        {
             return cUser(query.value(0).toInt(),query.value(1).toString(),query.value(2).toString());
        }
    }

    return cUser();
}


int BDD::cout_messageWith(QString id , QString idPro)
{
    QSqlQuery query;
    if(query.exec("SELECT count(*) FROM `message` WHERE `receiverId`= '"+id+"' AND projectID = '"+idPro+"'  "))
    {
        while(query.next())
        {
             return query.value(0).toInt() ;
        }

    }

    return 0;
}

cMessage BDD::getLastMessage(QString id ,  QString idPro)
{
    QSqlQuery query;
    if(query.exec("SELECT u1.login , u2.login , message , date FROM `message` INNER JOIN user u1 ON u1.id = senderId INNER JOIN user u2 ON u2.id = receiverId WHERE `receiverId`= '"+id+"' AND projectID = '"+idPro+"'  ORDER BY date DESC LIMIT 1 "))
    {
        while(query.next())
        {
             QDateTime date = QDateTime::fromString(query.value(3).toString(),"yyyy-MM-ddTHH:mm:ss");
             return cMessage(query.value(0).toString() , query.value(1).toString(), query.value(2).toString(), date ) ;
        }

    }
    return cMessage();
}




int BDD::cout_Event( QString idUser, QString idPro )
{
    QSqlQuery query;
    if(query.exec(" SELECT count(*) FROM `journal` WHERE `idProjet` = '"+idPro+"' AND `idUserToContact` = '"+idUser+"' AND NOT `idUser` = '"+idUser+"' "))
    {
        while(query.next())
        {
             return query.value(0).toInt() ;
        }

    }

    return 0;
}

cJournal BDD::getLastEvent(QString idUser , QString idPro)
{
    QSqlQuery query;
    if(query.exec("SELECT j.id , u1.login , u2.login , j.date , j.action FROM `journal` j INNER JOIN user u1 ON u1.id = j.idUser INNER JOIN user u2 ON u2.id = j.idUserToContact WHERE `idProjet` = 1 AND `idUserToContact` = 1 AND NOT `idUser` = 1 ORDER BY date DESC LIMIT 1 "))
    {
        while(query.next())
        {

             QDateTime date = QDateTime::fromString(query.value(3).toString(),"yyyy-MM-ddTHH:mm:ss");
             return cJournal(query.value(0).toInt() , query.value(1).toString() , query.value(2).toString()  ,  query.value(4).toString() , date );
        }

    }
    return cJournal();
}

bool BDD::addPeopleToProject(QString log, int idPro, QString nomPro)
{

    QString idString = QString::number(idPro);
    QSqlQuery query;

    if(query.exec("select insert_people_to_project('"+ login +"', '"+ log +"' , '"+idString+"' )"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){


               QString Message = login + " a ajouté "+ log +" au projet :" + nomPro ;
               query.exec("select add_journal( '"+ login +"' , '"+ log +"' , '"+ idString +"' , '"+ Message +"' )");

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

}

bool BDD::delPeopletoProject(QString log, int idPro , QString nomPro)
{

    QString idString = QString::number(idPro);
    QSqlQuery query;

    if(query.exec("select del_user_project('"+ login +"', '"+ log +"', '"+ idString +"')"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){


               QString Message = login + " a supprmé "+ log +" au projet : projet " + nomPro ;
               query.exec("select add_journal( '"+ login +"' , '"+ log +"' , '"+ idString +"' , '"+ Message +"' )");

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
}


// Ticket-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

vector<Ticket> BDD::loadTicket( int idPro )
{

    tickets.clear();

    QString idString = QString::number(idPro);

    // Chargement des projet

    QSqlQuery query;
    if(query.exec("SELECT tk.id, tk.name, tk.description, u2.login, tk.dateLog,  tk.dateAssignTo , u.login as 'Dev' , e.name FROM task tk   INNER JOIN project pro ON pro.id = tk.idProject  INNER JOIN etat e ON e.id = tk.Etat  INNER JOIN type tp ON tp.id = tk.idType   INNER JOIN user u ON u.id = tk.assignToUser  INNER JOIN user u2 ON u2.id = tk.createBy  WHERE pro.id = '"+idString+"' AND tp.nom = 'ticket';"))
    {
        while(query.next())
        {

            tickets.push_back(Ticket(query.value(0).toString() , query.value(1).toString(), query.value(2).toString(), query.value(3).toString() ,  query.value(4).toString() ,  query.value(5).toString() ,  query.value(6).toString() ,  query.value(7).toString() ));


        }
    }

    if(query.exec("SELECT tk.id, tk.name, tk.description, u2.login, tk.dateLog,  tk.dateAssignTo , e.name FROM task tk   INNER JOIN project pro ON pro.id = tk.idProject  INNER JOIN etat e ON e.id = tk.Etat  INNER JOIN type tp ON tp.id = tk.idType INNER JOIN user u2 ON u2.id = tk.createBy  WHERE pro.id = '"+idString+"' AND tp.nom = 'ticket' AND tk.assignToUser is null "))
    {
        while(query.next())
        {

            tickets.push_back(Ticket(query.value(0).toString() , query.value(1).toString(), query.value(2).toString(), query.value(3).toString() ,  query.value(4).toString() ,  query.value(5).toString() ,  "" ,  query.value(6).toString() ));


        }
    }


    return tickets;

}

Ticket BDD::loadTicketDetail(QString idTk , QString assign )
{

    Ticket bug;

    QSqlQuery query;

    if(assign == ""){

        if(query.exec("select t.name , t.description, u.login, t.dateLog , t.dateDone , t.dateAssignTo , e.name  from task t inner join Etat e on e.id = t.Etat inner join user u on u.id = t.createBy  where t.id = '"+ idTk +"' "))
        {
            while(query.next())
            {
                bug.setIdTicket(idTk);
                bug.setNameTicket(query.value(0).toString());
                bug.setDescrTicket(query.value(1).toString());
                bug.setCreateName(query.value(2).toString());
                bug.setCreateDt(query.value(3).toString());
                bug.setEndDate(query.value(4).toString());
                bug.setSetUserDate(query.value(5).toString());
                bug.setDev("");
                bug.setEtat(query.value(6).toString());

            }
        }



    }
    else{

        if(query.exec("select t.name , t.description, u.login, t.dateLog , t.dateDone , t.dateAssignTo , u2.login , e.name  from task t inner join Etat e on e.id = t.Etat inner join user u on u.id = t.createBy inner join user u2 on u2.id = t.assignToUser where t.id = '"+ idTk +"' "))
        {
            while(query.next())
            {
                bug.setIdTicket(idTk);
                bug.setNameTicket(query.value(0).toString());
                bug.setDescrTicket(query.value(1).toString());
                bug.setCreateName(query.value(2).toString());
                bug.setCreateDt(query.value(3).toString());
                bug.setEndDate(query.value(4).toString());
                bug.setSetUserDate(query.value(5).toString());
                bug.setDev(query.value(6).toString());
                bug.setEtat(query.value(7).toString());

            }
        }
    }


    return bug;

}

bool BDD::add_ticket(QString title , QString descr , QString userToAssign, QString avancement , int idPro )
{

    QRegExp rx( "([^\\\\])'" );
    title.replace( rx, "\\1\\'" );
    descr.replace( rx, "\\1\\'" );

    QString idString = QString::number(idPro);
    QSqlQuery query;

    if(query.exec("select add_ticket('"+ login +"', '"+ title +"' , '"+ descr +"', '"+ userToAssign +"' , '"+ avancement +"', '"+ idString +"' )"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){

               QString Message = login + " a ajouté le ticket " + title ;

               if(userToAssign == "")
                   query.exec("select add_journal( '"+ login +"' , '"+ login +"' , '"+ idString +"' , '"+ Message +"' )");
               else
                   query.exec("select add_journal( '"+ login +"' , '"+ userToAssign +"' , '"+ idString +"' , '"+ Message +"' )");

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

}

bool BDD::del_ticket(QString idTk , int idPro)
{

    QString idString = QString::number(idPro);
    QSqlQuery query;

    if(query.exec("select del_ticket('" + login + "' , '"+ idTk +"' , '"+ idString +"')"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){


               QString Message = login + " a supprmé le ticket " + idTk ;
               query.exec("select add_journal( '"+ login +"' , '"+ login +"' , '"+ idString +"' , '"+ Message +"' )");

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

}

bool BDD::upd_ticket(Ticket source , int id)
{

    QString idString = QString::number(id);
    QSqlQuery query;

    QString createName = source.getCreateName();
    QString nameTicket = source.getNameTicket();
    QString descrTK = source.getDescrTicket();
    QString dev = source.getDev();

    QRegExp rx( "([^\\\\])'" );
    createName.replace( rx, "\\1\\'" );
    nameTicket.replace( rx, "\\1\\'" );
    descrTK.replace( rx, "\\1\\'" );
    dev.replace( rx, "\\1\\'" );

    if(query.exec("select upd_ticket('"+ login +"' ,'"+ createName  +"' , '"+ nameTicket +"' , '"+ descrTK +"' , '"+ dev +"' , '"+ source.getEtat() +"' , '"+ source.getIdTicket()+"')"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){


               QString Message = login + " a mise à jour le ticket " + source.getNameTicket() ;
               query.exec("select add_journal( '"+ login +"' , '"+ source.getDev() +"' , '"+ idString +"' , '"+ Message +"' )");

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
}


// TASK -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


vector<Task> BDD::loadTask(int idPro)
{
    tasks.clear();

    QString idString = QString::number(idPro);

    // Chargement des projet

    QSqlQuery query;
    if(query.exec("SELECT td.`id` , td.titre , td.description, uC.login as 'Createur', uD.login as 'Developpeur' , atd.nom , td.`dateCreation`, td.`dateModification`, td.`dateFinalisation` FROM todo td INNER JOIN avancementTodo atd on td.`idAvancement` = atd.id INNER JOIN user uC on td.`idCreateur` = uC.id INNER JOIN user uD on td.`idDeveloppeur` = uD.id WHERE td.`idProjet` = '"+idString+"' "))
    {
        while(query.next())
        {

            tasks.push_back(Task(query.value(0).toString() , query.value(1).toString(), query.value(2).toString(), query.value(3).toString() ,  query.value(4).toString() ,  query.value(5).toString() ,  query.value(6).toString() , query.value(7).toString(), query.value(8).toString()));

        }
    }

    if(query.exec("SELECT td.`id` , td.titre , td.description, uC.login as 'Createur', atd.nom , td.`dateCreation`, td.`dateModification`, td.`dateFinalisation` FROM todo td INNER JOIN avancementTodo atd on td.`idAvancement` = atd.id INNER JOIN user uC on td.`idCreateur` = uC.id WHERE td.`idProjet` = '"+idString+"' AND td.idDeveloppeur is null "))
    {
        while(query.next())
        {

          tasks.push_back(Task(query.value(0).toString() , query.value(1).toString(), query.value(2).toString(), query.value(3).toString() , "" ,  query.value(4).toString() ,  query.value(5).toString() ,  query.value(6).toString() , query.value(7).toString()));

        }
    }


    return tasks;
}

bool BDD::delTask(QString idTk, int idPro)
{

    QString idString = QString::number(idPro);
    QSqlQuery query;

    if(query.exec("select del_task('" + login + "' , '"+ idTk +"' , '"+ idString +"')"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){


               QString Message = login + " a supprimé la tâche " + idTk ;
               query.exec("select add_journal( '"+ login +"' , '"+ login +"' , '"+ idString +"' , '"+ Message +"' )");

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

}

bool BDD::add_task(QString title, QString descr, QString userToAssign, QString avancement, QString date, int idPro)
{

    QString idString = QString::number(idPro);
    QSqlQuery query;

    QRegExp rx( "([^\\\\])'" );
    title.replace( rx, "\\1\\'" );
    descr.replace( rx, "\\1\\'" );

    if(query.exec("select add_task('"+ login +"', '"+ title +"' , '"+ descr +"', '"+ userToAssign +"' , '"+ avancement +"',  '"+ date +"', '"+ idString +"' )"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){



               QString Message = login + " a ajouté la tâche " + title ;
               query.exec("select add_journal( '"+ login +"' , '"+ userToAssign +"' , '"+ idString +"' , '"+ Message +"' )");


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

}

Task BDD::load_task_Detail(QString idTk, QString assign)
{


    Task todo;

    QSqlQuery query;

    if(assign != ""){

        if(query.exec("SELECT td.titre , td.description, uC.login as 'Createur', uD.login as 'Developpeur' , atd.nom , td.`dateCreation`, td.`dateModification`, td.`dateFinalisation` FROM todo td INNER JOIN avancementTodo atd on td.`idAvancement` = atd.id INNER JOIN user uC on td.`idCreateur` = uC.id INNER JOIN user uD on td.`idDeveloppeur` = uD.id WHERE td.id =  '"+ idTk +"' "))
        {
            while(query.next())
            {
                todo.setIdTask(idTk);
                todo.setTitre(query.value(0).toString());
                todo.setDescr(query.value(1).toString());
                todo.setCreateur(query.value(2).toString());
                todo.setDev(query.value(3).toString());
                todo.setEtat(query.value(4).toString());
                todo.setDateCreation(query.value(5).toString());
                todo.setDateModification(query.value(6).toString());
                todo.setDateFinalisation(query.value(7).toString());

            }
        }



    }
    else{

        if(query.exec("SELECT td.titre , td.description, uC.login as 'Createur', atd.nom , td.`dateCreation`, td.`dateModification`, td.`dateFinalisation` FROM todo td INNER JOIN avancementTodo atd on td.`idAvancement` = atd.id INNER JOIN user uC on td.`idCreateur` = uC.id WHERE td.id =  '"+ idTk +"' "))
        {
            while(query.next())
            {
                todo.setIdTask(idTk);
                todo.setTitre(query.value(0).toString());
                todo.setDescr(query.value(1).toString());
                todo.setCreateur(query.value(2).toString());
                todo.setDev("");
                todo.setEtat(query.value(3).toString());
                todo.setDateCreation(query.value(4).toString());
                todo.setDateModification(query.value(5).toString());
                todo.setDateFinalisation(query.value(6).toString());

            }
        }
    }

    return todo ;

}

bool BDD::upd_task(Task source, int idPro)
{

    QString title = source.getTitre();
    QString descr = source.getDescr();

    QRegExp rx( "([^\\\\])'" );
    title.replace( rx, "\\1\\'" );
    descr.replace( rx, "\\1\\'" );

    QString idString = QString::number(idPro);
    QSqlQuery query;

    if(query.exec("select upd_task('"+ login +"' ,'"+ source.getCreateur()  +"' , '"+ title +"' , '"+ descr +"' , '"+ source.getDev() +"' , '"+ source.getEtat() +"' , '"+ source.getIdTask()+"')"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){


               QString Message = login + " a mis à jour la tâche " + source.getIdTask() ;
               query.exec("select add_journal( '"+ login +"' , '"+ source.getDev() +"' , '"+ idString +"' , '"+ Message +"' )");

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
}

vector<QString> BDD::selectAvancement()
{

            vector<QString> myList;

            QSqlQuery query;
            if(query.exec("SELECT nom FROM `avancementtodo` "))
            {
                while(query.next())
                {
                     myList.push_back(query.value(0).toString());
                }

            }

            return myList;
}

//
// Test unitaire
//

vector<Test> BDD::loadTest(int idPro)
{


    tests.clear();

    QString idString = QString::number(idPro);

    // Chargement des test

    QSqlQuery query;

    if(query.exec("SELECT tu.`id`, `name`, `desciption`, `paramIn` , `paramOut` , `resultat`, user.login FROM `testunitaire` tu INNER JOIN user ON user.id = tu.valideur WHERE `projectId` = '"+ idString +"' "))
    {
        while(query.next())
        {

            tests.push_back(Test(query.value(0).toString() , query.value(1).toString(), query.value(2).toString(), query.value(3).toString() ,  query.value(4).toString() ,  query.value(5).toString() , query.value(6).toString()));

        }
    }

    if(query.exec("SELECT tu.`id`, `name`, `desciption`, `paramIn` , `paramOut` , `resultat` , valideur FROM `testunitaire` tu  WHERE `projectId` = '"+idString+"'  AND valideur is null "))
    {

    while(query.next())
        {

            tests.push_back(Test(query.value(0).toString() , query.value(1).toString(), query.value(2).toString(), query.value(3).toString() ,  query.value(4).toString() ,  query.value(5).toString() , ""));

        }
    }

    return tests;
}

bool BDD::delTest(QString idTk, int idPro)
{

    QString idString = QString::number(idPro);
    QSqlQuery query;

    if(query.exec("select del_test('" + login + "' , '"+ idTk +"' , '"+ idString +"')"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){


               QString Message = login + " a supprimé un test du projet : " + idPro  ;
               query.exec("select add_journal( '"+ login +"' , '"+ login +"' , '"+ idString +"' , '"+ Message +"' )");

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

}

bool BDD::add_test(QString title, QString descr, QString in, QString out, int idPro)
{
    QString idString = QString::number(idPro);
    QSqlQuery query;


    QRegExp rx( "([^\\\\])'" );
    title.replace( rx, "\\1\\'" );
    descr.replace( rx, "\\1\\'" );
    in.replace( rx, "\\1\\'" );
    out.replace( rx, "\\1\\'" );

    if(query.exec("select add_test('"+ login +"', '"+ title +"' , '"+ descr +"', '"+ in +"' , '"+ out +"', '"+ idString +"' )"))
    {
        while (query.next()) {
           if(query.value(0).toInt() == 1){

               QString Message = login + " a ajouté un test : " + title ;
               query.exec("select add_journal( '"+ login +"' , '"+ login +"' , '"+ idString +"' , '"+ Message +"' )");

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
}

bool BDD::upd_test(QString title, QString descr, QString in, QString out, int validate, int idTest,  int idPro)
{
    QRegExp rx( "([^\\\\])'" );
    title.replace( rx, "\\1\\'" );
    descr.replace( rx, "\\1\\'" );
    in.replace( rx, "\\1\\'" );
    out.replace( rx, "\\1\\'" );

    QString idString = QString::number(idPro);
    QString idTestString = QString::number(idTest);
    QString validateString = QString::number(validate);

    if(validate == 0){
        validateString = "0";
    }
    else {
        validateString = "1";
    }

    QSqlQuery query;

    if(query.exec("select upd_test('"+ login +"', '"+ title +"' , '"+ descr +"', '"+ in +"' , '"+ out +"', '"+ validateString +"' , '"+ idTestString +"' , '"+ idString +"' )"))
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
}

vector<cMessage> BDD::loadMessage(int idPro, QString receiver)
{
    messages.clear();

    QString idString = QString::number(idPro);

    // Chargement des test

    QSqlQuery query;

    if(query.exec("SELECT u1.login , u2.login , message , date FROM `message` INNER JOIN user u1 ON u1.id = senderId INNER JOIN user u2 ON u2.id = receiverId WHERE `projectID` = '"+idString+"' AND ((u2.login = '"+ receiver +"' AND u1.login = '"+ login +"' ) || (u2.login = '"+ login +"' AND u1.login = '"+ receiver +"')) order By date "))
    {
        while(query.next())
        {

            QDateTime date = QDateTime::fromString(query.value(3).toString(),"yyyy-MM-ddTHH:mm:ss");
            messages.push_back(cMessage(query.value(0).toString() , query.value(1).toString(), query.value(2).toString(), date ));

        }
    }

    return messages;
}

bool BDD::add_Message(int idPro, QString msg, QString usr)
{
    QString idString = QString::number(idPro);
    QSqlQuery query;

    QRegExp rx( "([^\\\\])'" );
    msg.replace( rx, "\\1\\'" );
    usr.replace( rx, "\\1\\'" );


    if(query.exec("select add_Message( '"+ login +"' , '"+ msg +"' , '"+ usr +"' , '"+ idString +"' )"))
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
}

vector<cJournal> BDD::select_journal(int idPro)
{
    journal.clear();

    QSqlQuery query;
    if(query.exec(QString("SELECT j.id , u1.login , u2.login , j.date , j.action FROM `journal` j INNER JOIN user u1 ON u1.id = j.idUser INNER JOIN user u2 ON u2.id = j.idUserToContact WHERE `idProjet` = %1 ORDER BY j.date DESC ;").arg(idPro)))
    {
        while(query.next())
        {
           QDateTime date = QDateTime::fromString(query.value(3).toString(),"yyyy-MM-ddTHH:mm:ss");
           journal.push_back(cJournal(query.value(0).toInt() , query.value(1).toString() , query.value(2).toString()  ,  query.value(4).toString() , date ));
        }
    }

    return journal;
}

//
// Share
//

std::map<Share,QString> BDD::loadShares(int idPro){
    shares.clear();
    std::map<Share,QString> map;
    QSqlQuery query;
    if(query.exec(QString("SELECT s.id,projectId,userId,filename,filecontent,login FROM sharefiles s,user u WHERE projectId = %1 AND userId = u.id;").arg(idPro)))
    {
        while(query.next())
        {
           Share s = Share(query.value(0).toInt(),query.value(1).toInt(),query.value(2).toInt(),query.value(3).toString().toStdString(),query.value(4).toByteArray());
           map[s] = query.value(5).toString();
           shares.push_back(s);
        }
    }

    return map;
}

bool BDD::add_share(Share* s){
    QSqlQuery query;
    query.prepare("INSERT INTO sharefiles (projectId,userId,filename,filecontent) VALUES(?,?,?,?)");
    query.addBindValue(s->getIdProject());
    query.addBindValue(s->getIdCreator());
    query.addBindValue(s->getFilename().c_str());
    query.addBindValue(s->getContent(),QSql::Binary);
    if(!query.exec())
    {
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
}



