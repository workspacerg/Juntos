#include "uitestunitaire.h"
#include "ui_uitestunitaire.h"

UiTestUnitaire::UiTestUnitaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UiTestUnitaire)
{
    ui->setupUi(this);

     ui->delBox->hide();
     boiteDel = false;

     ui->addBox->hide();
     boiteAdd = false;

    QStringList Titreheader            ;
    Titreheader << "id" << "Votre test" << "paramètre d'entrée" << "Resultat attendu" << "Validation" << "Valideur" << "description";

    ui->tableWidgetTest->setColumnCount(7);
    ui->tableWidgetTest->setHorizontalHeaderLabels(Titreheader);

    ui->tableWidgetTest->verticalHeader()->setVisible(false);
    ui->tableWidgetTest->setShowGrid(false);

    ui->tableWidgetTest->setColumnWidth(0, 50);
    ui->tableWidgetTest->setColumnWidth(1, 250);
    ui->tableWidgetTest->setColumnWidth(2, 250);
    ui->tableWidgetTest->setColumnWidth(3, 250);


    ui->tableWidgetTest->horizontalHeader()->setStretchLastSection(true);

    ui->tableWidgetTest->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");

}

UiTestUnitaire::~UiTestUnitaire()
{
    delete ui;
}


void UiTestUnitaire::loadTable(vector<Test> Source)
{
    // Vide la table
    while (ui->tableWidgetTest->rowCount() > 0)
    {
        ui->tableWidgetTest->removeRow(0);
    }

    // Charge la table
    for(Test& item : Source)
    {
        int LastRow = ui->tableWidgetTest->rowCount();
        ui->tableWidgetTest->insertRow(LastRow);
        ui->tableWidgetTest->setItem(LastRow, 0, new QTableWidgetItem(item.getIdTest()));
        ui->tableWidgetTest->setItem(LastRow, 1, new QTableWidgetItem(item.getTitre()));
        ui->tableWidgetTest->setItem(LastRow, 2, new QTableWidgetItem(item.getParamIn()));
        ui->tableWidgetTest->setItem(LastRow, 3, new QTableWidgetItem(item.getResultatAttendu()));
        if(item.getValidation() == QString::number(1)){
         ui->tableWidgetTest->setItem(LastRow, 4, new QTableWidgetItem("Passed"));
        }
        else{
          ui->tableWidgetTest->setItem(LastRow, 4, new QTableWidgetItem("failed"));
        }
        ui->tableWidgetTest->setItem(LastRow, 5, new QTableWidgetItem(item.getValidePar()));
        ui->tableWidgetTest->setItem(LastRow, 6, new QTableWidgetItem(item.getDescr()));

    }
}


void UiTestUnitaire::on_addTest_clicked()
{
    if(boiteAdd == true)
    {
        boiteAdd = false;
        ui->addBox->hide();
    }
    else{
        boiteAdd = true;
        ui->addBox->show();
    }
}

void UiTestUnitaire::on_DelTest_clicked()
{

    if(boiteDel == true)
    {
        boiteDel = false;
        ui->delBox->hide();
    }
    else{
        boiteDel = true;
        ui->delBox->show();
    }
}

void UiTestUnitaire::on_tableWidgetTest_itemDoubleClicked(QTableWidgetItem *item)
{
    emit upd_test(item->row());
}

void UiTestUnitaire::on_confirmDel_clicked()
{
    if ( ui->delLine->text() == "SUPPRIMER" )
    {
        emit del_test(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 0)->text());
    }

    ui->delBox->hide();
    boiteDel = false;

}

void UiTestUnitaire::on_save_test_clicked()
{
    if(ui->TitreLine->text() == "" || ui->pInline->text() == "" || ui->pOutLine->text() == ""){

        return ;
    }

    emit add_test(ui->TitreLine->text(),  ui->pInline->text() , ui->pOutLine->text(), ui->DescrTPL->toPlainText() );

}
