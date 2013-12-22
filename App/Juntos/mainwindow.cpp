#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->cPref->hide();
    ui->cTask->hide();
    ui->cTicket->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mAccueil_clicked()
{
    this->hideAll();
    ui->cAccueil->show();

}

void MainWindow::on_mTask_clicked()
{
    this->hideAll();
    ui->cTask->show();
}

void MainWindow::on_mTicket_clicked()
{
    this->hideAll();
    ui->cTicket->show();
}

void MainWindow::on_mPreference_clicked()
{
    this->hideAll();
    ui->cPref->show();
}

void MainWindow::hideAll()
{
    ui->cAccueil->hide();
    ui->cPref->hide();
    ui->cTask->hide();
    ui->cTicket->hide();
}
