#ifndef FORMUPDTODO_H
#define FORMUPDTODO_H

#include <QDialog>
#include <vector>
#include <QDateTime>
#include "cuser.h"
#include "task.h"

using namespace std;

namespace Ui {
class FormUpdTodo;
}

class FormUpdTodo : public QDialog
{
    Q_OBJECT

     QString idTk;

public:
    explicit FormUpdTodo(QWidget *parent = 0);
    ~FormUpdTodo();


    // --------------------------
    void loadComboBox(vector<cUser> usr, vector<QString> avc);
    void loadInfoTask(Task source);

private slots:
    void on_save_clicked();

private:
    Ui::FormUpdTodo *ui;

signals:
    void save_data(Task);
};

#endif // FORMUPDTODO_H
