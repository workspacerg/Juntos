#include "uitask.h"
#include "ui_uitask.h"


QString uiTask::getLogin() const
{
    return login;
}

void uiTask::setLogin(const QString &value)
{
    login = value;
}
uiTask::uiTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiTask)
{
    ui->setupUi(this);


    ui->delBox->hide();
    boiteDel = false;
    ui->delLine->setAlignment(Qt::AlignCenter);

    QStringList Titreheader            ;
    Titreheader << "id" << "Tâches" << "Etat" << "Créateur" << " Assigné à" <<"Date de création" << "modifié le" << "à finir pour" << "Description" ;

    ui->tableWidgetTask->setColumnCount(9);
    ui->tableWidgetTask->setHorizontalHeaderLabels(Titreheader);

    ui->tableWidgetTask->verticalHeader()->setVisible(false);
    ui->tableWidgetTask->setShowGrid(false);


    ui->tableWidgetTask->setColumnWidth(0, 50);
    ui->tableWidgetTask->setColumnWidth(5, 150);
    ui->tableWidgetTask->setColumnWidth(6, 150);
    ui->tableWidgetTask->setColumnWidth(7, 150);

    ui->tableWidgetTask->horizontalHeader()->setStretchLastSection(true);

    ui->tableWidgetTask->setStyleSheet("QTableView {selection-Background-color: rgb(45, 186, 166); }");
}

uiTask::~uiTask()
{
    delete ui;
}

void uiTask::loadTable(vector<Task> Source)
{
    // Vide la table
    while (ui->tableWidgetTask->rowCount() > 0)
    {
        ui->tableWidgetTask->removeRow(0);
    }

    // Charge la table
    for(Task& item : Source)
    {
        int LastRow = ui->tableWidgetTask->rowCount();
        ui->tableWidgetTask->insertRow(LastRow);
        ui->tableWidgetTask->setItem(LastRow, 0, new QTableWidgetItem(item.getIdTask()));
        ui->tableWidgetTask->setItem(LastRow, 1, new QTableWidgetItem(item.getTitre()));
        ui->tableWidgetTask->setItem(LastRow, 2, new QTableWidgetItem(item.getEtat()));
        ui->tableWidgetTask->setItem(LastRow, 3, new QTableWidgetItem(item.getCreateur()));
        ui->tableWidgetTask->setItem(LastRow, 4, new QTableWidgetItem(item.getDev()));
        ui->tableWidgetTask->setItem(LastRow, 5, new QTableWidgetItem(item.getDateCreation()));
        ui->tableWidgetTask->setItem(LastRow, 6, new QTableWidgetItem(item.getDateModification()));
        ui->tableWidgetTask->setItem(LastRow, 7, new QTableWidgetItem(item.getDateFinalisation()));
        ui->tableWidgetTask->setItem(LastRow, 8, new QTableWidgetItem(item.getDescr()));

    }

    ui->mesTaches->setChecked(true);
    updTable();
}


void uiTask::on_DelTask_clicked()
{

    if(ui->tableWidgetTask->currentRow() == -1)
    {

       return;
    }

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


void uiTask::on_addTask_clicked()
{
    emit add_task();
}

void uiTask::on_tableWidgetTask_itemDoubleClicked(QTableWidgetItem *item)
{

    emit upd_task(ui->tableWidgetTask->item( item->row() , 0)->text() ,  ui->tableWidgetTask->item( item->row() , 4)->text() );

}



void uiTask::updTable()
{

    for (int i = 0 ; i < ui->tableWidgetTask->rowCount() ; i++ )
    {
            ui->tableWidgetTask->hideRow(i);

    }


    if(ui->mesTaches->isChecked()){

        for (int i = 0 ; i < ui->tableWidgetTask->rowCount() ; i++ )
        {
            if(  ui->tableWidgetTask->item( i , 3)->text() ==  login || ui->tableWidgetTask->item( i , 4)->text() ==  login  ){
                ui->tableWidgetTask->showRow(i);
            }

        }
    }


    if(ui->autreTache->isChecked()){

        for (int i = 0 ; i < ui->tableWidgetTask->rowCount() ; i++ )
        {
            if(  ui->tableWidgetTask->item( i , 3)->text() !=  login && ui->tableWidgetTask->item( i , 4)->text() !=  login  ){
                ui->tableWidgetTask->showRow(i);
            }

        }
    }

    if(ui->nonAssign->isChecked()){

        for (int i = 0 ; i < ui->tableWidgetTask->rowCount() ; i++ )
        {
            if( ui->tableWidgetTask->item( i , 4)->text() ==  ""  ){
                ui->tableWidgetTask->showRow(i);
            }

        }
    }

}

void uiTask::on_lineEdit_textChanged(const QString &arg1)
{
    for (int i = 0 ; i < ui->tableWidgetTask->rowCount() ; i++ )
    {
        ui->tableWidgetTask->hideRow(i);
        for (int y = 0 ; y < ui->tableWidgetTask->columnCount() ; y++ )
        {
            if(   ui->tableWidgetTask->item( i , y)->text().indexOf( arg1, Qt::CaseInsensitive) >=0  && ui->tableWidgetTask->item( i , y)->text() != "" ){

                ui->tableWidgetTask->showRow(i);
            }
            else{
            }
        }
    }
}

void uiTask::on_mesTaches_clicked()
{
    updTable();
}

void uiTask::on_autreTache_clicked()
{
    updTable();
}

void uiTask::on_nonAssign_clicked()
{
    updTable();
}

void uiTask::on_confirmDel_clicked()
{

    if (  ui->delLine->text() == "SUPPRIMER" )
    {
        emit delSelectedTask(ui->tableWidgetTask->item( ui->tableWidgetTask->currentRow() , 0)->text());
    }

    boiteDel = false;
    ui->delBox->hide();
     ui->delLine->setText("");
}
