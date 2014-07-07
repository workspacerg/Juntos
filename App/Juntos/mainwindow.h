#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "uiacceuil.h"
#include "uitask.h"
#include "uipref.h"
#include "uiticket.h"
#include "uitestunitaire.h"
#include "uifile.h"
#include "notification.h"
#include "bdd.h"
#include "addpeopledialog.h"
#include "formaddbug.h"
#include "formupdbug.h"
#include "formaddtodo.h"
#include "formupdtodo.h"
#include "test.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

    BDD *myBDD ;
    CProjet * currentProject ;
    notification *Notif ;

    Ui::MainWindow *ui;
    void hideAll();
    void enableAllFunction();
    void disableAllFunction();


public:

    uiAcceuil   *PageAccueil    ;
    uiTask      *PageTask       ;
    uiPref      *PagePref       ;
    uiTicket    *PageTicket     ;
    UiTestUnitaire      *PageTest       ;
    uiFile      *PageFile       ;

    addPeopleDialog *pagePeople ;

    formAddBug *pageAddBug ;
    formUpdBug *pageUpdBug ;

    formAddTodo *pageAddTask;
    FormUpdTodo *pageUpdTask;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void displayNotification(QString, QString);
    // BDD ------------------------------------------------------------------------------------------------------------------------------
    void connectBDD();
    void loadTableProject();
    void addProject(CProjet);
    void delProject(CProjet source);
    void selCurrentProject(CProjet source);
    void getParticipant();
    void addPeopletoProject(QString);
    void delPeopleToProject(QString);;

    //  Ticket ------------------------------------------------------------------------------------------------------------------------------
    void displayFormAddBug();
    void displayFormDelBug(QString idTk);
    void displayFormUpdBug(QString idTk , QString assign);
    void saveTicketToDatabase(QString , QString , QString , QString );
    void updTicketToDatabase(Ticket source);

    // Task ----------------------------------------------------------------------------------------------------------------------------------
    void deleteTask(QString id);
    void display_Form_Add_Task();
    void display_Form_upd_task(QString, QString dev);
    void upd_task_to_database(Task);

    // Test ------------------------------------------------------------------------------------------------------------------------------
    void add_test(QString _titre, QString _in, QString _out, QString _descr);
    void del_test(QString id);
    void display_form_upd_test();
    void upd_to_dataBase(Test);

private slots:
    void on_mAccueil_clicked();
    void on_mTask_clicked();
    void on_mTicket_clicked();
    void on_mPreference_clicked();
    void on_mMessages_clicked();
    void on_mTest_clicked();
    void on_mFile_clicked();
    void save_To_Database(QString , QString , QString , QString , QString);


};

#endif // MAINWINDOW_H
