#include "addpeopledialog.h"
#include "ui_addpeopledialog.h"

addPeopleDialog::addPeopleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPeopleDialog)
{
    ui->setupUi(this);
}

addPeopleDialog::~addPeopleDialog()
{
    delete ui;
}
