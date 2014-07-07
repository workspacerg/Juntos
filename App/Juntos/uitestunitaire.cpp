#include "uitestunitaire.h"
#include "ui_uitestunitaire.h"

UiTestUnitaire::UiTestUnitaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UiTestUnitaire)
{
    ui->setupUi(this);

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
     emit add_test();
}

void UiTestUnitaire::on_DelTest_clicked()
{
    emit del_test();
}

void UiTestUnitaire::on_tableWidgetTest_itemDoubleClicked(QTableWidgetItem *item)
{
    emit upd_test(item->row());
}
