#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>

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

    disableAllFunction();



    emit on_mAccueil_clicked();

    // Centre de notifiaction
    Notif = new notification();
    QObject::connect(PageAccueil, SIGNAL(notifiactionNewProject(QString, QString)), this, SLOT(displayNotification(QString, QString)));

    // Base de donnée
    myBDD = new BDD();
    emit connectBDD();
    QObject::connect(PagePref, SIGNAL(newParamConnect()), this, SLOT(connectBDD()));

    // ACCEUIL
    QObject::connect(PageAccueil, SIGNAL(sigLoadTable()), this, SLOT(loadTableProject()));
    QObject::connect(PageAccueil, SIGNAL(sigAddPro(CProjet)), this, SLOT(addProject(CProjet)));
    QObject::connect(PageAccueil, SIGNAL(sigDelPro(CProjet)), this, SLOT(delProject(CProjet)));
    QObject::connect(PageAccueil, SIGNAL(sigSelectCurrentPro(CProjet)), this, SLOT(selCurrentProject(CProjet)));
    QObject::connect(PageAccueil, SIGNAL(sigGetParticipant()), this, SLOT(getParticipant()));

}


MainWindow::~MainWindow()
{
    delete Notif;
    delete ui;
}

void MainWindow::connectBDD()
{

    if(myBDD->connectDB() &&  myBDD->verifUser())
    {
       ui->statusBar->showMessage("Vous êts connecté");
       ui->menu->show();
       emit on_mAccueil_clicked();


       emit loadTableProject();

    }
    else
    {
       ui->statusBar->showMessage("la connexion à échoué");
       ui->menu->hide();
       emit on_mPreference_clicked();
    }

}

void MainWindow::loadTableProject()
{

    PageAccueil->loadTable(myBDD->loadProject());

}

void MainWindow::addProject(CProjet source)
{
    myBDD->addProject(CProjet(source.getNomProjet(), source.getDescProjet()));
    emit  loadTableProject();
}

void MainWindow::delProject(CProjet source)
{

    myBDD->delProject(source);
    emit  loadTableProject();

}

void MainWindow::selCurrentProject(CProjet source)
{
    //currentProject = new CProjet(source.getNomProjet(), source.getDescProjet());

    currentProject = new CProjet(myBDD->getInfoProjet(source));
    enableAllFunction();

    qDebug() << currentProject->getId();
    qDebug() << currentProject->getNomProjet();
    qDebug() << currentProject->getDescProjet();

    ui->statusBar->showMessage(" Current project is : "  +  currentProject->getNomProjet());

}

void MainWindow::getParticipant()
{
       vector<cUser> listUser = myBDD->getParticipant(currentProject->getId());

       currentProject->clearUser();
       for(cUser item : listUser)
       {
           qDebug() << item.getLogin();
           currentProject->addUser(item);
       }

       pagePeople = new addPeopleDialog();
        QObject::connect(pagePeople, SIGNAL(sigAddUserToProject(QString)), this, SLOT(addPeopletoProject(QString)));
        QObject::connect(pagePeople, SIGNAL(sigDelUserToProject(QString)), this, SLOT(delPeopleToProject(QString)));

        pagePeople->loadParticipant(currentProject->getUsers());

       // Verifier droit admin du projet
       // si false cache la bar de modification
       if(!myBDD->checkAdmin(currentProject->getId()))
       {
             pagePeople->disableModification();
       }

       pagePeople->show();
}

void MainWindow::addPeopletoProject(QString usrToadd)
{
    myBDD->addPeopleToProject(usrToadd, currentProject->getId());
    delete pagePeople;
}

void MainWindow::delPeopleToProject(QString usrToadd)
{
    qDebug() << "delPeopleToProject(QString usrToadd)" ;
    myBDD->delPeopletoProject(usrToadd, currentProject->getId());
    delete pagePeople;
}

void MainWindow::displayNotification(QString titre, QString content)
{
    Notif->sendNotification(titre, content, 12000);
}

// pragma ui


void MainWindow::enableAllFunction(){

    ui->mTask->setEnabled(true);
    ui->mTest->setEnabled(true);
    ui->mTicket->setEnabled(true);
    ui->mMessages->setEnabled(true);
    ui->mFile->setEnabled(true);

}

void MainWindow::disableAllFunction(){

    ui->mTask->setEnabled(false);
    ui->mTest->setEnabled(false);
    ui->mTicket->setEnabled(false);
    ui->mMessages->setEnabled(false);
    ui->mFile->setEnabled(false);

}

void MainWindow::hideAll()
{

    ui->cAccueil->hide() ;
    ui->cPref->hide()    ;
    ui->cTask->hide()    ;
    ui->cTicket->hide()  ;
    ui->cTest->hide()    ;
    ui->cFile->hide()    ;

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
    // Update des tickets :


    PageTicket->loadTable(myBDD->loadTicket(currentProject->getId()));


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
