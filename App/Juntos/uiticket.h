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

private:
    Ui::uiTicket *ui;
};

#endif // UITICKET_H
