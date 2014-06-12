#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    PageAccueil = new uiAcceuil ;
    PageTask    = new uiTask    ;
    PagePref    = new uiPref    ;
    PageTicket  = new uiTicket  ;
    PageTest    = new uiTest    ;
    PageFile    = new uiFile    ;


    emit on_mAccueil_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideAll()
{

    ui->cAccueil->hide();
    ui->cPref->hide()   ;
    ui->cTask->hide()   ;
    ui->cTicket->hide() ;
    ui->cTest->hide()   ;
    ui->cFile->hide()   ;

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
    ui->TitreBody->setText("Liste des tâches");
    ui->cTask->layout()->addWidget(PageTask);
    ui->cTask->show();

}

void MainWindow::on_mTicket_clicked()
{
    this->hideAll();
    ui->TitreBody->setText("Ticket");
    ui->cTicket->layout()->addWidget(PageTicket);
    ui->cTicket->show();
}

void MainWindow::on_mPreference_clicked()
{
    this->hideAll();
    ui->TitreBody->setText("Préférence");
    ui->cPref->layout()->addWidget(PagePref);
    ui->cPref->show();
}

void MainWindow::on_mMessages_clicked()
{
    this->hideAll();
    ui->TitreBody->setText("Messages");

}


void MainWindow::on_mTest_clicked()
{
    this->hideAll();
    ui->TitreBody->setText("Test");
    ui->cTest->layout()->addWidget(PageTest);
    ui->cTest->show();
}

void MainWindow::on_mFile_clicked()
{
    this->hideAll();
    ui->TitreBody->setText("File");
    ui->cFile->layout()->addWidget(PageFile);
    ui->cFile->show();
}
