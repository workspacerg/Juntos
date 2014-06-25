#ifndef UITICKET_H
#define UITICKET_H

#include <QWidget>
#include "ticket.h"

using namespace std;

namespace Ui {
class uiTicket;
}

class uiTicket : public QWidget
{
    Q_OBJECT

public:
    explicit uiTicket(QWidget *parent = 0);
    ~uiTicket();

    vector<Ticket> tickets;


    void loadTable(vector<Ticket>);

private slots:
    void on_addBug_clicked();
    void on_delBug_clicked();
    void on_tableWidgetTicket_doubleClicked(const QModelIndex &index);

private:
    Ui::uiTicket *ui;


signals:
    void displayFormAddBug();
    void displayFormDelBug(QString);
    void displayFormUpdBug();


};

#endif // UITICKET_H
