#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "uiacceuil.h"
#include "uitask.h"
#include "uipref.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    uiAcceuil   *PageAccueil    ;
    uiTask      *PageTask       ;
    uiPref      *PagePref       ;


private slots:
    void on_mAccueil_clicked();

    void on_mTask_clicked();

    void on_mTicket_clicked();

    void on_mPreference_clicked();

    void on_mMessages_clicked();

private:
    Ui::MainWindow *ui;




    void hideAll();
};

#endif // MAINWINDOW_H
