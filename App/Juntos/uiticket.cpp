#include "uiticket.h"
#include "ui_uiticket.h"


QString uiTicket::getLogin() const
{
    return login;
}

void uiTicket::setLogin(const QString &value)
{
    login = value;
}
uiTicket::uiTicket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiTicket)
{
    ui->setupUi(this);

    ui->delBox->hide();
    boiteDel = false;
    ui->delLine->setAlignment(Qt::AlignCenter);

    ui->mesTk->setChecked(true);

    QStringList Titreheader            ;
    Titreheader << "id" << "Ticket" << "Créateur" <<"Date d'ajout " << "modifié le" << " Assigné à "  << "Etat" << "Description" ;

    ui->tableWidgetTicket->setColumnCount(8);
    ui->tableWidgetTicket->setHorizontalHeaderLabels(Titreheader);

    ui->tableWidgetTicket->verticalHeader()->setVisible(false);
    ui->tableWidgetTicket->setShowGrid(false);
    ui->tableWidgetTicket->setColumnHidden(0,true);
    ui->tableWidgetTicket->setColumnWidth(0, 50);
        ui->tableWidgetTicket->setColumnWidth(1, 200);
    ui->tableWidgetTicket->setColumnWidth(3, 200);
    ui->tableWidgetTicket->setColumnWidth(4, 200);


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
        ui->tableWidgetTicket->setItem(LastRow, 5, new QTableWidgetItem(item.getDev()));
        ui->tableWidgetTicket->setItem(LastRow, 6, new QTableWidgetItem(item.getEtat()));
        ui->tableWidgetTicket->setItem(LastRow, 7, new QTableWidgetItem(item.getDescrTicket()));

        ui->tableWidgetTicket->setItem( LastRow, 3, new QTableWidgetItem( QDateTime::fromString(item.getCreateDt(),"yyyy-MM-ddTHH:mm:ss").toString("yyyy-MM-dd HH:mm:ss")) );
        ui->tableWidgetTicket->setItem( LastRow, 4, new QTableWidgetItem( QDateTime::fromString(item.getSetUserDate(),"yyyy-MM-ddTHH:mm:ss").toString("yyyy-MM-dd HH:mm:ss")));


    }

    updTable();

}


void uiTicket::on_addBug_clicked()
{
   emit displayFormAddBug();
}

void uiTicket::on_delBug_clicked()
{
    if(ui->tableWidgetTicket->currentRow() == -1)
    {

       return;
    }
   // emit displayFormDelBug(ui->tableWidgetTicket->item( ui->tableWidgetTicket->currentRow() , 0)->text());

    if(boiteDel == true)
    {
        boiteDel = false;
        ui->delBox->hide();
        ui->delLine->setText("");
    }
    else{
        boiteDel = true;
        ui->delBox->show();
    }

}

void uiTicket::on_tableWidgetTicket_itemDoubleClicked(QTableWidgetItem *item)
{
    emit displayFormUpdBug(ui->tableWidgetTicket->item( item->row() , 0)->text() ,  ui->tableWidgetTicket->item( item->row() , 5)->text() );
}

void uiTicket::on_confirmDel_clicked()
{
    if(ui->tableWidgetTicket->currentRow() == -1)
    {

       return;
    }

    if ( ui->delLine->text() == "SUPPRIMER" )
    {
        emit displayFormDelBug(ui->tableWidgetTicket->item( ui->tableWidgetTicket->currentRow() , 0)->text());
    }

    ui->delBox->hide();
    boiteDel = false;
}

void uiTicket::on_lineEdit_textChanged(const QString &arg1)
{
    for (int i = 0 ; i < ui->tableWidgetTicket->rowCount() ; i++ )
    {
        ui->tableWidgetTicket->hideRow(i);
        for (int y = 0 ; y < ui->tableWidgetTicket->columnCount() ; y++ )
        {
            if(   ui->tableWidgetTicket->item( i , y)->text().indexOf( arg1, Qt::CaseInsensitive) >=0  && ui->tableWidgetTicket->item( i , y)->text() != "" ){

                ui->tableWidgetTicket->showRow(i);
            }
            else{
            }

        }
    }
}

void uiTicket::updTable()
{

    for (int i = 0 ; i < ui->tableWidgetTicket->rowCount() ; i++ )
    {
            ui->tableWidgetTicket->hideRow(i);

    }


    if(ui->mesTk->isChecked()){

        for (int i = 0 ; i < ui->tableWidgetTicket->rowCount() ; i++ )
        {
            if(  ui->tableWidgetTicket->item( i , 5)->text() ==  login && ui->tableWidgetTicket->item( i , 6)->text() !=  "résolu" ){
                ui->tableWidgetTicket->showRow(i);
            }

        }
    }

    if(ui->autreTk->isChecked()){

        for (int i = 0 ; i < ui->tableWidgetTicket->rowCount() ; i++ )
        {
            if(  ui->tableWidgetTicket->item( i , 5)->text() !=  login ){
                ui->tableWidgetTicket->showRow(i);
            }
        }
    }

    if(ui->nonAssign->isChecked()){

        for (int i = 0 ; i < ui->tableWidgetTicket->rowCount() ; i++ )
        {
            if(  ui->tableWidgetTicket->item( i , 5)->text() ==  "" ){
                ui->tableWidgetTicket->showRow(i);
            }

        }
    }

    if(ui->resolus->isChecked()){

        for (int i = 0 ; i < ui->tableWidgetTicket->rowCount() ; i++ )
        {
            if(  ui->tableWidgetTicket->item( i , 6)->text() ==  "résolu" ){
                ui->tableWidgetTicket->showRow(i);
            }
        }
    }
}

void uiTicket::on_mesTk_clicked()
{
    updTable();
}

void uiTicket::on_autreTk_clicked()
{
    updTable();
}

void uiTicket::on_resolus_clicked()
{
    updTable();
}

void uiTicket::on_nonAssign_clicked()
{
    updTable();
}
