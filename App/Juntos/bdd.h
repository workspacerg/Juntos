#ifndef BDD_H
#define BDD_H


#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <qstring.h>
#include <QSettings>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QDateTime>
#include "cprojet.h"
#include <vector>
#include "cuser.h"
#include "ticket.h"
#include "task.h"
#include "test.h"
#include "share.h"
#include "cmessage.h"

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
            vector<Task> tasks ;
            vector<Test> tests ;
            vector<Share> shares;
            vector<cMessage> messages;



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
    Ticket loadTicketDetail(QString idTk, QString assign);
    bool add_ticket(QString title , QString descr , QString userToAssign, QString avancement , int idPro);
    bool del_ticket(QString idTk , int idPro);
    bool upd_ticket(Ticket source);

    // Task
    vector<Task> loadTask(int idPro);
    bool delTask(QString idTk , int idPro);
    bool add_task(QString title , QString descr , QString userToAssign, QString avancement , QString date , int idPro);
    Task load_task_Detail(QString idTk, QString assign);
    bool upd_task(Task source);

    // Test
    vector<Test> loadTest(int idPro);
    bool delTest(QString idTk , int idPro);
    bool add_test(QString title , QString descr , QString in, QString out , int idPro);

    // Share
    vector<Share> loadShares(int idPro);
    bool add_share(Share);

    // Message
    vector<cMessage> loadMessage(int idPro, QString receiver);
    bool add_Message(int idPro , QString msg , QString usr);

    QString getLogin() const;
    void setLogin(const QString &value);
};

#endif // BDD_H
