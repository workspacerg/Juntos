#include "uitask.h"
#include "ui_uitask.h"

uiTask::uiTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiTask)
{
    ui->setupUi(this);

    QStringList Titreheader            ;
    Titreheader <<"Taches"<<"Date de résolution"<<"Assigné à " << "Description" ;

    ui->tableWidgetTask->setColumnCount(4);
    ui->tableWidgetTask->setHorizontalHeaderLabels(Titreheader);

    ui->tableWidgetTask->verticalHeader()->setVisible(false);
    ui->tableWidgetTask->setShowGrid(false);

    ui->tableWidgetTask->setColumnWidth(0, 200);


    ui->tableWidgetTask->horizontalHeader()->setStretchLastSection(true);

    ui->tableWidgetTask->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");
}

uiTask::~uiTask()
{
    delete ui;
}
