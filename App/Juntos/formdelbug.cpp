#include "formdelbug.h"
#include "ui_formdelbug.h"

formDelBug::formDelBug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formDelBug)
{
    ui->setupUi(this);
}

formDelBug::~formDelBug()
{
    delete ui;
}
