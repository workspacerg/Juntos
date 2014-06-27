#ifndef FORMADDTODO_H
#define FORMADDTODO_H

#include <QDialog>
#include <vector>
#include "cuser.h"
#include <QDebug>
#include <QDateTime>

using namespace std;

namespace Ui {
class formAddTodo;
}

class formAddTodo : public QDialog
{
    Q_OBJECT

public:
    explicit formAddTodo(QWidget *parent = 0);
    ~formAddTodo();

    // --------------------------
    void loadComboBox(vector<cUser>, vector<QString>);

private slots:
    void on_save_clicked();

private:
    Ui::formAddTodo *ui;

signals:
    void savetodatabase( QString, QString, QString, QString, QString );
};

#endif // FORMADDTODO_H
