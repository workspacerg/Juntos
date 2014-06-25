#ifndef FORMADDBUG_H
#define FORMADDBUG_H

#include <QDialog>
#include <vector>
#include "cuser.h"

using namespace std;

namespace Ui {
class formAddBug;
}

class formAddBug : public QDialog
{
    Q_OBJECT

public:
    explicit formAddBug(QWidget *parent = 0);
    ~formAddBug();

    void loadParticipant(vector<cUser> usr);

private:
    Ui::formAddBug *ui;

signals:
    void savetodatabase( QString, QString, QString, QString );

private slots:
    void on_save_clicked();
};

#endif // FORMADDBUG_H
