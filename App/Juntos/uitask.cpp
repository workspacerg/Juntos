#include "uitask.h"
#include "ui_uitask.h"

uiTask::uiTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiTask)
{
    ui->setupUi(this);

    QStringList Titreheader            ;
    Titreheader << "id" << "Tâches" << "Etat" << "Créateur" << " Assigné à" <<"Date de création" << "modifié le" << "à finir pour" << "Description" ;

    ui->tableWidgetTask->setColumnCount(9);
    ui->tableWidgetTask->setHorizontalHeaderLabels(Titreheader);

    ui->tableWidgetTask->verticalHeader()->setVisible(false);
    ui->tableWidgetTask->setShowGrid(false);


    ui->tableWidgetTask->setColumnWidth(0, 50);
    ui->tableWidgetTask->setColumnWidth(5, 150);
    ui->tableWidgetTask->setColumnWidth(6, 150);
    ui->tableWidgetTask->setColumnWidth(7, 150);

    ui->tableWidgetTask->horizontalHeader()->setStretchLastSection(true);

    ui->tableWidgetTask->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");
}

uiTask::~uiTask()
{
    delete ui;
}

void uiTask::loadTable(vector<Task> Source)
{
    // Vide la table
    while (ui->tableWidgetTask->rowCount() > 0)
    {
        ui->tableWidgetTask->removeRow(0);
    }

    // Charge la table
    for(Task& item : Source)
    {
        int LastRow = ui->tableWidgetTask->rowCount();
        ui->tableWidgetTask->insertRow(LastRow);
        ui->tableWidgetTask->setItem(LastRow, 0, new QTableWidgetItem(item.getIdTask()));
        ui->tableWidgetTask->setItem(LastRow, 1, new QTableWidgetItem(item.getTitre()));
        ui->tableWidgetTask->setItem(LastRow, 2, new QTableWidgetItem(item.getEtat()));
        ui->tableWidgetTask->setItem(LastRow, 3, new QTableWidgetItem(item.getCreateur()));
        ui->tableWidgetTask->setItem(LastRow, 4, new QTableWidgetItem(item.getDev()));
        ui->tableWidgetTask->setItem(LastRow, 5, new QTableWidgetItem(item.getDateCreation()));
        ui->tableWidgetTask->setItem(LastRow, 6, new QTableWidgetItem(item.getDateModification()));
        ui->tableWidgetTask->setItem(LastRow, 7, new QTableWidgetItem(item.getDateFinalisation()));
        ui->tableWidgetTask->setItem(LastRow, 8, new QTableWidgetItem(item.getDescr()));

    }
}


void uiTask::on_DelTask_clicked()
{
    DialSuppr = new SupprDialog ;

    QObject::connect(DialSuppr, SIGNAL(sendText(QString)), this, SLOT(evaluationSuppr(QString)));
    DialSuppr->show();



}

void uiTask::evaluationSuppr(QString string)
{

    delete DialSuppr;
    if ( string == "SUPPRIMER" )
    {
        emit delSelectedTask(ui->tableWidgetTask->item( ui->tableWidgetTask->currentRow() , 0)->text());
    }
}

void uiTask::on_addTask_clicked()
{
    emit add_task();
}
