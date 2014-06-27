#include "supprdialog.h"
#include "ui_supprdialog.h"

SupprDialog::SupprDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprDialog)
{
    ui->setupUi(this);


    ui->textedit->setAlignment(Qt::AlignCenter);



}

SupprDialog::~SupprDialog()
{
    delete ui;
}

void SupprDialog::on_sent_clicked()
{
    emit sendText(ui->textedit->toPlainText());
}
