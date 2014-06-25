#ifndef UITICKET_H
#define UITICKET_H

#include <QWidget>
#include "cticket.h"

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

    vector<CTicket> tickets;


    void loadTable(vector<CTicket>);

private:
    Ui::uiTicket *ui;
};

#endif // UITICKET_H
