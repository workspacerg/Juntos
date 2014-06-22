#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "uiacceuil.h"
#include "uitask.h"
#include "uipref.h"
#include "uiticket.h"
#include "uitest.h"
#include "uifile.h"
#include "notification.h"
#include "bdd.h"

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
    uiTest      *PageTest       ;
    uiFile      *PageFile       ;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void displayNotification(QString, QString);
    void connectBDD();
    void loadTableProject();
    void addProject(CProjet);
    void delProject(CProjet source);
    void selCurrentProject(CProjet source);

private slots:
    void on_mAccueil_clicked();
    void on_mTask_clicked();
    void on_mTicket_clicked();
    void on_mPreference_clicked();
    void on_mMessages_clicked();
    void on_mTest_clicked();
    void on_mFile_clicked();


};

#endif // MAINWINDOW_H
