#ifndef UITASK_H
#define UITASK_H

#include <QWidget>
#include <vector>
#include "task.h"
#include "supprdialog.h"


using namespace std;

namespace Ui {
class uiTask;
}

class uiTask : public QWidget
{
    Q_OBJECT

public:
    explicit uiTask(QWidget *parent = 0);
    ~uiTask();

    void loadTable(vector<Task>);


private slots:
    void on_DelTask_clicked();

    void on_addTask_clicked();

public slots:
    void evaluationSuppr(QString);

private:
    Ui::uiTask *ui;

    SupprDialog * DialSuppr;
signals:
    void delSelectedTask(QString idTask);
    void add_task();

};

#endif // UITASK_H
