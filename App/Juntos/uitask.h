#ifndef UITASK_H
#define UITASK_H

#include <QWidget>
#include <vector>
#include <QTableWidgetItem>
#include <QDateTime>
#include "task.h"


using namespace std;

namespace Ui {
class uiTask;
}

class uiTask : public QWidget
{
    Q_OBJECT

    QString login;
    bool boiteDel;

public:
    explicit uiTask(QWidget *parent = 0);
    ~uiTask();

    void loadTable(vector<Task>);


    QString getLogin() const;
    void setLogin(const QString &value);

private slots:
    void on_DelTask_clicked();

    void on_addTask_clicked();

    void on_tableWidgetTask_itemDoubleClicked(QTableWidgetItem *item);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_mesTaches_clicked();

    void on_autreTache_clicked();

    void on_nonAssign_clicked();

    void on_confirmDel_clicked();

public slots:


private:
    Ui::uiTask *ui;

    void updTable();


signals:
    void delSelectedTask(QString idTask);
    void add_task();
    void upd_task(QString, QString);

};

#endif // UITASK_H
