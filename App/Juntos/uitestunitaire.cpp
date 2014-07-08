#include "uitestunitaire.h"
#include "ui_uitestunitaire.h"
#include <QDebug>

UiTestUnitaire::UiTestUnitaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UiTestUnitaire)
{
    ui->setupUi(this);

     ui->delBox->hide();
     boiteDel = false;

     ui->addBox->hide();
     boiteAdd = false;

     ui->updBox->hide();
     boiteUpd = false;


     ui->ok->setChecked(true);
     ui->failed->setChecked(true);


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
          ui->tableWidgetTest->setItem(LastRow, 4, new QTableWidgetItem("Failed"));
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

    if(boiteUpd == true)
    {
        boiteUpd = false;
        ui->updBox->hide();

        ui->TitreLine_upd->setText("");
        ui->pInline_upd->setText("");
        ui->pOutLine_upd->setText("");
        ui->DescrTPL_upd->setPlainText("");
        ui->valid->setChecked(false);

    }
    else{
        boiteUpd = true;
        ui->updBox->show();

        ui->TitreLine_upd->setText(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 1)->text());
        ui->pInline_upd->setText(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 2)->text());
        ui->pOutLine_upd->setText(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 3)->text());
        ui->DescrTPL_upd->setPlainText(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 6)->text());

        if(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 4)->text() == "Passed" )
        {
            ui->valid->setChecked(true);
        }

    }

}

void UiTestUnitaire::on_confirmDel_clicked()
{

    if(ui->tableWidgetTest->currentRow() == -1)
    {

       return;
    }

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

    ui->TitreLine->setText("");
    ui->pInline->setText("");
    ui->pOutLine->setText("");
    ui->DescrTPL->setPlainText("");

    boiteAdd = false;
    ui->addBox->hide();
}

void UiTestUnitaire::on_save_test_upd_clicked()
{

    emit upd_test( ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 0)->text() , ui->TitreLine_upd->text(),  ui->pInline_upd->text() , ui->pOutLine_upd->text(), ui->DescrTPL_upd->toPlainText() );

    ui->TitreLine_upd->setText("");
    ui->pInline_upd->setText("");
    ui->pOutLine_upd->setText("");
    ui->DescrTPL_upd->setPlainText("");

    boiteUpd = false;
    ui->updBox->hide();

}

void UiTestUnitaire::on_tableWidgetTest_itemChanged(QTableWidgetItem *item)
{

}

void UiTestUnitaire::on_tableWidgetTest_itemClicked(QTableWidgetItem *item)
{

    if(boiteUpd == true){
        ui->TitreLine_upd->setText(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 1)->text());
        ui->pInline_upd->setText(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 2)->text());
        ui->pOutLine_upd->setText(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 3)->text());
        ui->DescrTPL_upd->setPlainText(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 6)->text());

        if(ui->tableWidgetTest->item( ui->tableWidgetTest->currentRow() , 4)->text() == "Passed" )
        {
            ui->valid->setChecked(true);
        }
    }

}

void UiTestUnitaire::on_ok_clicked()
{

    updTable();
    ui->lineEdit->setText("");

}


void UiTestUnitaire::on_failed_clicked()
{
    updTable();
    ui->lineEdit->setText("");
}


void UiTestUnitaire::updTable()
{
    if (ui->ok->isChecked())
    {
        for (int i = 0 ; i < ui->tableWidgetTest->rowCount() ; i++ )
        {

            if(  ui->tableWidgetTest->item( i , 4)->text() == "Passed"    ){
                ui->tableWidgetTest->showRow(i);
            }

        }
    }
    else{

        for (int i = 0 ; i < ui->tableWidgetTest->rowCount() ; i++ )
        {

            if(  ui->tableWidgetTest->item( i , 4)->text() == "Passed"    ){
                ui->tableWidgetTest->hideRow(i);
            }

        }

    }

    if (ui->failed->isChecked())
    {
        for (int i = 0 ; i < ui->tableWidgetTest->rowCount() ; i++ )
        {
            if(  ui->tableWidgetTest->item( i , 4)->text() == "Failed"    ){
                ui->tableWidgetTest->showRow(i);
            }
        }
    }
    else{

        for (int i = 0 ; i < ui->tableWidgetTest->rowCount() ; i++ )
        {
            if(  ui->tableWidgetTest->item( i , 4)->text() == "Failed"    ){
                ui->tableWidgetTest->hideRow(i);

            }
        }
    }

}

void UiTestUnitaire::on_lineEdit_textChanged(const QString &arg1)
{


    for (int i = 0 ; i < ui->tableWidgetTest->rowCount() ; i++ )
    {
        ui->tableWidgetTest->hideRow(i);
        for (int y = 0 ; y < ui->tableWidgetTest->columnCount() ; y++ )
        {
            if(   ui->tableWidgetTest->item( i , y)->text().indexOf( arg1, Qt::CaseInsensitive) >=0  && ui->tableWidgetTest->item( i , y)->text() != "" ){

                ui->tableWidgetTest->showRow(i);
            }
            else{
            }

        }
    }

}
