#include "uiacceuil.h"
#include "ui_uiacceuil.h"
#include "QDialog"
#include "QGridLayout"
#include "QDebug"
#include "QString"
#include "QtDebug"


uiAcceuil::uiAcceuil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiAcceuil)
{
    ui->setupUi(this);
    ui->BoiteDeCreation->hide();
    BtCreation = false ;

    ui->tableWidgetPtoject->verticalHeader()->setVisible(false);
    ui->tableWidgetPtoject->setShowGrid(false);

    ui->addPeople->hide();

    QStringList test            ;
    test <<"Nom"<<"Description"  ;
    ui->tableWidgetPtoject->setColumnCount(2);
    ui->tableWidgetPtoject->setColumnWidth(0, 200);
    ui->tableWidgetPtoject->setHorizontalHeaderLabels(test);
    ui->tableWidgetPtoject->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetPtoject->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");
}

uiAcceuil::~uiAcceuil()
{
    delete ui;
}

void uiAcceuil::loadTable(vector<CProjet> Source)
{

    while (ui->tableWidgetPtoject->rowCount() > 0)
    {
        ui->tableWidgetPtoject->removeRow(0);
    }

    for(CProjet& item : Source)
    {
        int LastRow = ui->tableWidgetPtoject->rowCount();
        ui->tableWidgetPtoject->insertRow(LastRow);
        ui->tableWidgetPtoject->setItem(LastRow, 0, new QTableWidgetItem(item.getNomProjet()));
        ui->tableWidgetPtoject->setItem(LastRow, 1, new QTableWidgetItem(item.getDescProjet()));
    }
}

void uiAcceuil::on_addProject_clicked()
{
    ////////////////////////////////////////////////////////////////////////////////
    ///     Mecanisme d'affichage de la boite de creation
    if (BtCreation == false){
        ui->BoiteDeCreation->show();
        ui->LENom->setFocus();
        BtCreation = true ;
    }
    else{
         ui->BoiteDeCreation->hide();
         BtCreation = false ;
    }
}

void uiAcceuil::on_PBCreate_clicked()
{
    ui->BoiteDeCreation->hide();
    BtCreation = false ;

    emit sigAddPro(CProjet(ui->LENom->text(), ui->TEDescr->toPlainText()));
   // emit notifiactionNewProject("Création de projet", "Le projet " + Projet->getNomProjet() + " à été crée avec succès");

    ui->LENom->clear();
    ui->TEDescr->clear();

}

void uiAcceuil::on_PBDelProject_clicked()
{

    if(ui->tableWidgetPtoject->currentRow() != -1  )
    {
        emit sigDelPro(CProjet(ui->tableWidgetPtoject->item(ui->tableWidgetPtoject->currentRow() , 0)->text() , ui->tableWidgetPtoject->item(ui->tableWidgetPtoject->currentRow() , 1)->text() ));
    }

}

void uiAcceuil::on_updTable_clicked()
{
    emit sigLoadTable();
}

void uiAcceuil::on_tableWidgetPtoject_itemDoubleClicked(QTableWidgetItem *item)
{
    ui->addPeople->show();
    emit sigSelectCurrentPro(CProjet(ui->tableWidgetPtoject->item( item->row() , 0)->text() , ui->tableWidgetPtoject->item( item->row() , 1)->text() ));
}
