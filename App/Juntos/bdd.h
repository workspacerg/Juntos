#ifndef BDD_H
#define BDD_H


#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <qstring.h>
#include <QSettings>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "cprojet.h"
#include <vector>
#include "cuser.h"
#include "ticket.h"

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
            vector<Ticket> tickets ;



public:

    BDD();
    bool connectDB();
    bool verifUser();
    bool checkAdmin(int);

    // Projet
    vector<CProjet> loadProject();
    bool addProject(CProjet source);
    bool delProject(CProjet source);
    CProjet getInfoProjet(CProjet source);
    vector<cUser> getParticipant(int);
    bool addPeopleToProject( QString , int );
    bool delPeopletoProject( QString, int );

    // Ticket
    vector<Ticket> loadTicket(int);
    bool add_ticket(QString title , QString descr , QString userToAssign, QString avancement , int idPro);


};

#endif // BDD_H
