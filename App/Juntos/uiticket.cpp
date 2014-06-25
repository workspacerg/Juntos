#include "uiticket.h"
#include "ui_uiticket.h"

uiTicket::uiTicket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiTicket)
{
    ui->setupUi(this);

    QStringList Titreheader            ;
    Titreheader << "id" << "Ticket" << "Créateur" <<"Date d'ajout " << "Assigné le" << " Assigné à "  << "Etat" << "Description" ;

    ui->tableWidgetTicket->setColumnCount(8);
    ui->tableWidgetTicket->setHorizontalHeaderLabels(Titreheader);

    ui->tableWidgetTicket->verticalHeader()->setVisible(false);
    ui->tableWidgetTicket->setShowGrid(false);

    ui->tableWidgetTicket->setColumnWidth(0, 100);


    ui->tableWidgetTicket->horizontalHeader()->setStretchLastSection(true);

    ui->tableWidgetTicket->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");
}

uiTicket::~uiTicket()
{
    delete ui;
}

void uiTicket::loadTable(vector<Ticket> Source)
{


    // Vide la table
    while (ui->tableWidgetTicket->rowCount() > 0)
    {
        ui->tableWidgetTicket->removeRow(0);
    }

    // Charge la table
    for(Ticket& item : Source)
    {
        int LastRow = ui->tableWidgetTicket->rowCount();
        ui->tableWidgetTicket->insertRow(LastRow);
        ui->tableWidgetTicket->setItem(LastRow, 0, new QTableWidgetItem(item.getIdTicket()));
        ui->tableWidgetTicket->setItem(LastRow, 1, new QTableWidgetItem(item.getNameTicket()));
        ui->tableWidgetTicket->setItem(LastRow, 2, new QTableWidgetItem(item.getCreateName()));
        ui->tableWidgetTicket->setItem(LastRow, 3, new QTableWidgetItem(item.getCreateDt()));
        ui->tableWidgetTicket->setItem(LastRow, 4, new QTableWidgetItem(item.getSetUserDate()));
        ui->tableWidgetTicket->setItem(LastRow, 8, new QTableWidgetItem(item.getDescrTicket()));
    }

}

