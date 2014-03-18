#include "uiticket.h"
#include "ui_uiticket.h"

uiTicket::uiTicket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiTicket)
{
    ui->setupUi(this);

    QStringList Titreheader            ;
    Titreheader <<"Ticket"<<"Date de résolution"<<"Assigné à " << "Description" ;

    ui->tableWidgetTicket->setColumnCount(4);
    ui->tableWidgetTicket->setHorizontalHeaderLabels(Titreheader);

    ui->tableWidgetTicket->verticalHeader()->setVisible(false);
    ui->tableWidgetTicket->setShowGrid(false);

    ui->tableWidgetTicket->setColumnWidth(0, 200);


    ui->tableWidgetTicket->horizontalHeader()->setStretchLastSection(true);

    ui->tableWidgetTicket->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");
}

uiTicket::~uiTicket()
{
    delete ui;
}
