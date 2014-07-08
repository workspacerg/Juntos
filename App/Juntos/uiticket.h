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
        QString login;

public:
    explicit uiTicket(QWidget *parent = 0);
    ~uiTicket();

    vector<Ticket> tickets;


    void loadTable(vector<Ticket>);

    QString getLogin() const;
    void setLogin(const QString &value);

private slots:
    void on_addBug_clicked();
    void on_delBug_clicked();
    void on_tableWidgetTicket_itemDoubleClicked(QTableWidgetItem *item);

    void on_confirmDel_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_mesTk_clicked();

    void on_autreTk_clicked();

    void on_resolus_clicked();

    void on_nonAssign_clicked();

private:
    Ui::uiTicket *ui;
    void updTable();


signals:
    void displayFormAddBug();
    void displayFormDelBug(QString);
    void displayFormUpdBug(QString, QString);


};

#endif // UITICKET_H
