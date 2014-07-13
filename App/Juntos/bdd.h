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
#include "cjournal.h"

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
            vector<cJournal> journal;



public:

    BDD();
    bool connectDB();
    bool verifUser();
    bool checkAdmin(int);
    cUser getInfoUser(QString _log);
    cUser getInfoUserById(int id);

    // Thread
    int count_Change();
    int cout_messageWith(QString id , QString idPro);
    cMessage getLastMessage(QString id, QString idPro);
    int cout_Event( QString idUser, QString idPro );
    cJournal getLastEvent(QString idUser , QString idPro);

    // Projet
    vector<CProjet> loadProject();
    bool addProject(CProjet source);
    bool delProject(CProjet source);
    CProjet getInfoProjet(CProjet source);
    vector<cUser> getParticipant(int);
    bool addPeopleToProject(QString , int , QString nomPro);
    bool delPeopletoProject(QString, int , QString nomPro);

    // Ticket
    vector<Ticket> loadTicket(int);
    Ticket loadTicketDetail(QString idTk, QString assign);
    bool add_ticket(QString title , QString descr , QString userToAssign, QString avancement , int idPro);
    bool del_ticket(QString idTk , int idPro);
    bool upd_ticket(Ticket source, int id);

    // Task
    vector<Task> loadTask(int idPro);
    bool delTask(QString idTk , int idPro);
    bool add_task(QString title , QString descr , QString userToAssign, QString avancement , QString date , int idPro);
    Task load_task_Detail(QString idTk, QString assign);
    bool upd_task(Task source, int idPro);
    vector<QString> selectAvancement();

    // Test
    vector<Test> loadTest(int idPro);
    bool delTest(QString idTk , int idPro);
    bool add_test(QString title , QString descr , QString in, QString out , int idPro);
    bool upd_test(QString title, QString descr, QString in, QString out, int validate, int idTest,  int idPro);

    // Share
    std::map<Share, QString> loadShares(int idPro);
    bool add_share(Share *);

    // Message
    vector<cMessage> loadMessage(int idPro, QString receiver);
    bool add_Message(int idPro , QString msg , QString usr);

    // Journal
    vector<cJournal> select_journal(int idPro);

    QString getLogin() const;
    void setLogin(const QString &value);
};

#endif // BDD_H
