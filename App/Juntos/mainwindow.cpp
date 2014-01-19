#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    PageAccueil = new uiAcceuil ;

    emit on_mAccueil_clicked();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideAll()
{

    ui->cAccueil->hide();
    ui->cPref->hide();
    ui->cTask->hide();
    ui->cTicket->hide();

}


void MainWindow::on_mAccueil_clicked()
{

    this->hideAll();
    ui->TitreBody->setText("Juntos");
    ui->cAccueil->layout()->addWidget(PageAccueil);
    ui->cAccueil->show();

}

void MainWindow::on_mTask_clicked()
{

    this->hideAll();
    ui->TitreBody->setText("Task");
    ui->cTask->show();

}

void MainWindow::on_mTicket_clicked()
{
    this->hideAll();
    ui->TitreBody->setText("Ticket");

    ui->cTicket->show();
}

void MainWindow::on_mPreference_clicked()
{
    this->hideAll();
    ui->TitreBody->setText("Préférence");
    ui->cPref->show();
}

void MainWindow::on_mMessages_clicked()
{
    this->hideAll();
    ui->TitreBody->setText("Messages");

}

