#ifndef UITASK_H
#define UITASK_H

#include <QWidget>

namespace Ui {
class uiTask;
}

class uiTask : public QWidget
{
    Q_OBJECT

public:
    explicit uiTask(QWidget *parent = 0);
    ~uiTask();

private:
    Ui::uiTask *ui;
};

#endif // UITASK_H
