#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include   <QDebug>

namespace Ui {
class Launcher;
}

class Launcher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Launcher(QWidget *parent = 0);
    ~Launcher();

public slots:
    void showAccueil()      ;
    void showTicket()       ;
    void showTask()         ;
    void showMessage()      ;
    void showPreference()   ;

private:
    Ui::Launcher    *ui                                                     ;

    QWidget         *body               =   new QWidget                     ;
    QWidget         *menu               =   new QWidget                     ;
    QWidget         *firstPage          =   new QWidget                     ;

    QGridLayout     *mainLayout         =   new QGridLayout                 ;
    QGridLayout     *mainBodyLayout     =   new QGridLayout                 ;
    QGridLayout     *menuLayout         =   new QGridLayout                 ;

    QLabel          *Titre              =   new QLabel("Juntos")            ;

    QPushButton     *Menu1              =   new QPushButton("Accueil")      ;
    QPushButton     *Menu2              =   new QPushButton("Ticket")       ;
    QPushButton     *Menu3              =   new QPushButton("Todo")         ;
    QPushButton     *Menu4              =   new QPushButton("Chat")         ;
    QPushButton     *Menu5              =   new QPushButton("Paramètre")    ;



};

#endif // LAUNCHER_H
