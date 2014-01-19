#include "uitask.h"
#include "ui_uitask.h"

uiTask::uiTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiTask)
{
    ui->setupUi(this);
}

uiTask::~uiTask()
{
    delete ui;
}
