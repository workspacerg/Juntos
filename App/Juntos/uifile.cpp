#include "uifile.h"
#include "ui_uiFile.h"

uiFile::uiFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uiFile)
{
    ui->setupUi(this);
}

uiFile::~uiFile()
{
    delete ui;
}
