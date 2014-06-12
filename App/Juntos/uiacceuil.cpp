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

    CProjet *Projet                     = new CProjet;
    Projet->setNomProjet(ui->LENom->text());
    Projet->setDescProjet(ui->TEDescr->toPlainText());

    int LastRow = ui->tableWidgetPtoject->rowCount();
    ui->tableWidgetPtoject->insertRow(LastRow);
    ui->tableWidgetPtoject->setItem(LastRow, 0, new QTableWidgetItem(Projet->getNomProjet()));
    ui->tableWidgetPtoject->setItem(LastRow, 1, new QTableWidgetItem(Projet->getDescProjet()));

    emit notifiactionNewProject("Création de projet", "Le projet " + Projet->getNomProjet() + " à été crée avec succès");

}

void uiAcceuil::on_PBDelProject_clicked()
{


    ui->tableWidgetPtoject->removeRow(ui->tableWidgetPtoject->currentRow()) ;
}
