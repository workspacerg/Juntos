#ifndef FORMUPDBUG_H
#define FORMUPDBUG_H

#include <QDialog>
#include <vector>
#include <QDateTime>
#include "cuser.h"
#include "ticket.h"

using namespace std;

namespace Ui {
class formUpdBug;
}

class formUpdBug : public QDialog
{
    Q_OBJECT

    QString idTk;

public:
    explicit formUpdBug(QWidget *parent = 0);
    ~formUpdBug();
    void loadParticipant(vector<cUser> usr);
    void loadInfoTicket(Ticket);

private slots:
    void on_save_clicked();

private:
    Ui::formUpdBug *ui;

signals:
    void save_upd_ticket(Ticket);

};

#endif // FORMUPDBUG_H
