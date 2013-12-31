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
    ui->listWidgetProject->addItem(ui->LENom->text());
}

void uiAcceuil::on_PBDelProject_clicked()
{
    delete ui->listWidgetProject->currentItem();
}
