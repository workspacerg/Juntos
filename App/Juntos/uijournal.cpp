#include "uijournal.h"
#include "ui_uijournal.h"
#include <QDebug>

uiJournal::uiJournal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uiJournal)
{
    ui->setupUi(this);
}

uiJournal::~uiJournal()
{
    delete ui;
}

void uiJournal::closeEvent(QCloseEvent *event)
{
    delete this;
}
