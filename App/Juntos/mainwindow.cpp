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
    PageTest    = new UiTestUnitaire    ;
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

    // Ticket
    QObject::connect(PageTicket, SIGNAL(displayFormAddBug()), this, SLOT(displayFormAddBug()));
    QObject::connect(PageTicket, SIGNAL(displayFormDelBug(QString)), this, SLOT(displayFormDelBug(QString)));
    QObject::connect(PageTicket, SIGNAL(displayFormUpdBug(QString, QString)), this, SLOT(displayFormUpdBug(QString, QString)));

    // Task
    QObject::connect(PageTask, SIGNAL(delSelectedTask(QString)), this, SLOT(deleteTask(QString)));
    QObject::connect(PageTask, SIGNAL(add_task()), this, SLOT(display_Form_Add_Task()));
    QObject::connect(PageTask, SIGNAL(upd_task(QString, QString)), this, SLOT(display_Form_upd_task(QString, QString)));

    // Test
    QObject::connect(PageTest, SIGNAL(del_test(QString)), this, SLOT(del_test(QString)));
    QObject::connect(PageTest, SIGNAL(add_test()), this, SLOT(display_form_add_test()));
    //QObject::connect(PageTest, SIGNAL(upd_task(QString, QString)), this, SLOT(display_Form_upd_task(QString, QString)));


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

//
//
// TICKET -------------------------------------------------------------------------------------------------------------------
//
//

void MainWindow::displayFormAddBug()
{
    vector<cUser> listUser = myBDD->getParticipant(currentProject->getId());

    currentProject->clearUser();
    for(cUser item : listUser)
    {
        currentProject->addUser(item);
    }

    pageAddBug = new formAddBug();
    pageAddBug->loadParticipant(currentProject->getUsers());
    QObject::connect(pageAddBug, SIGNAL(savetodatabase(QString,QString,QString,QString)), this, SLOT(saveTicketToDatabase(QString,QString,QString,QString)));
    pageAddBug->show();
}

void MainWindow::displayFormDelBug(QString idTk)
{
    myBDD->del_ticket(idTk , currentProject->getId());
    emit on_mTicket_clicked();
}

void MainWindow::displayFormUpdBug(QString idTk , QString assign)
{
    vector<cUser> listUser = myBDD->getParticipant(currentProject->getId());

    currentProject->clearUser();
    for(cUser item : listUser)
    {
        currentProject->addUser(item);
    }

    pageUpdBug = new formUpdBug();
    pageUpdBug->loadParticipant(currentProject->getUsers());
    pageUpdBug->loadInfoTicket(myBDD->loadTicketDetail(idTk , assign ));
    QObject::connect(pageUpdBug, SIGNAL(save_upd_ticket(Ticket)), this, SLOT(updTicketToDatabase(Ticket)));
    pageUpdBug->show();
}

void MainWindow::saveTicketToDatabase(QString title ,QString descr ,QString user ,QString etat)
{
    myBDD->add_ticket(title , descr , user , etat , currentProject->getId());

    delete pageAddBug;
    emit on_mTicket_clicked();
}

void MainWindow::updTicketToDatabase(Ticket source)
{
    myBDD->upd_ticket(source);
    delete pageUpdBug;
    emit on_mTicket_clicked();
}



//
//
// TASK -------------------------------------------------------------------------------------------------------------------
//
//
void MainWindow::deleteTask(QString id)
{
    myBDD->delTask(id , currentProject->getId());
    emit on_mTask_clicked();
}

void MainWindow::display_Form_Add_Task()
{

    vector<cUser> listUser = myBDD->getParticipant(currentProject->getId());

    currentProject->clearUser();
    for(cUser item : listUser)
    {
        currentProject->addUser(item);
    }

    vector<QString> avc ;

    avc.push_back("crée");
    avc.push_back("assigné");
    avc.push_back("en cours");

    pageAddTask = new formAddTodo;
        QObject::connect(pageAddTask, SIGNAL(savetodatabase(QString,QString,QString,QString,QString)), this, SLOT(save_To_Database(QString,QString,QString,QString,QString)));
    pageAddTask->loadComboBox(currentProject->getUsers(), avc );
    pageAddTask->show();

    emit on_mTask_clicked();

}

void MainWindow::display_Form_upd_task(QString idTk, QString dev)
{

    vector<cUser> listUser = myBDD->getParticipant(currentProject->getId());

    currentProject->clearUser();
    for(cUser item : listUser)
    {
        currentProject->addUser(item);
    }

    vector<QString> avc ;

    avc.push_back("crée");
    avc.push_back("assigné");
    avc.push_back("en cours");

    pageUpdTask = new FormUpdTodo ;
    QObject::connect(pageUpdTask, SIGNAL(save_data(Task)), this, SLOT(upd_task_to_database(Task)));
    pageUpdTask->loadComboBox(currentProject->getUsers(), avc);
    pageUpdTask->loadInfoTask(myBDD->load_task_Detail(idTk , dev));
    pageUpdTask->show();


}

void MainWindow::upd_task_to_database(Task source)
{
    myBDD->upd_task(source);
    emit on_mTask_clicked();
    delete pageUpdTask;
}




void MainWindow::save_To_Database(QString Titre, QString Descr, QString Usr, QString Avc, QString dt)
{

    myBDD->add_task(Titre , Descr , Usr , Avc , dt , currentProject->getId());
    delete pageAddTask;
    emit on_mTask_clicked();

}

//
//
// TEST UNITAIRE -------------------------------------------------------------------------------------------------------------------
//
//

void MainWindow::display_form_add_test()
{

}

void MainWindow::del_test(QString id)
{

}

void MainWindow::display_form_upd_test()
{

}

void MainWindow::upd_to_dataBase(Test)
{

}





//
//
// UI MAIN WINDOW -------------------------------------------------------------------------------------------------------------------
//
//

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

    PageTask->loadTable(myBDD->loadTask(currentProject->getId()));

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
    // Update des tickets :
    PageTest->loadTable(myBDD->loadTest(currentProject->getId()));


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
