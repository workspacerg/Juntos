#include "uitest.h"
#include "ui_uitest.h"

uiTest::uiTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uiTest)
{
    ui->setupUi(this);
}

uiTest::~uiTest()
{
    delete ui;
}
