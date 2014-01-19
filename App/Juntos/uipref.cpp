#include "uipref.h"
#include "ui_uipref.h"

uiPref::uiPref(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiPref)
{
    ui->setupUi(this);
}

uiPref::~uiPref()
{
    delete ui;
}
