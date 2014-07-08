#ifndef UITICKET_H
#define UITICKET_H

#include <QWidget>
#include <QTableWidgetItem>
#include "ticket.h"

using namespace std;

namespace Ui {
class uiTicket;
}

class uiTicket : public QWidget
{
    Q_OBJECT
        bool boiteDel;

public:
    explicit uiTicket(QWidget *parent = 0);
    ~uiTicket();

    vector<Ticket> tickets;


    void loadTable(vector<Ticket>);

private slots:
    void on_addBug_clicked();
    void on_delBug_clicked();
    void on_tableWidgetTicket_itemDoubleClicked(QTableWidgetItem *item);

    void on_confirmDel_clicked();

private:
    Ui::uiTicket *ui;


signals:
    void displayFormAddBug();
    void displayFormDelBug(QString);
    void displayFormUpdBug(QString, QString);


};

#endif // UITICKET_H
