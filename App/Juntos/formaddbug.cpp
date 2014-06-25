#include "formaddbug.h"
#include "ui_formaddbug.h"

formAddBug::formAddBug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formAddBug)
{
    ui->setupUi(this);
}

formAddBug::~formAddBug()
{
    delete ui;
}
