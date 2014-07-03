#include "uitest.h"
#include "ui_uitest.h"

uiTest::uiTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uiTest)
{

    ui->setupUi(this);

    QStringList Titreheader            ;
    Titreheader << "Test name" << "paramètre d'entrée" << "paramètre de sortie" << "Resultat attendu" << "description";

    ui->tableWidgetTest->setColumnCount(5);
    ui->tableWidgetTest->setHorizontalHeaderLabels(Titreheader);

    ui->tableWidgetTest->verticalHeader()->setVisible(false);
    ui->tableWidgetTest->setShowGrid(false);

    ui->tableWidgetTest->setColumnWidth(0, 250);


    ui->tableWidgetTest->horizontalHeader()->setStretchLastSection(true);

    ui->tableWidgetTest->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");

}

uiTest::~uiTest()
{
    delete ui;
}
