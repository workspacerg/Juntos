#include "formupdtodo.h"
#include "ui_formupdtodo.h"

FormUpdTodo::FormUpdTodo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormUpdTodo)
{
    ui->setupUi(this);
}

FormUpdTodo::~FormUpdTodo()
{
    delete ui;
}

void FormUpdTodo::loadComboBox(vector<cUser> usr, vector<QString> avc)
{
    ui->usrComboBox->addItem("");
    for(cUser item : usr)
    {
        ui->usrComboBox->addItem(item.getLogin());
    }


    for(QString item : avc)
    {
        ui->etatComboBox->addItem(item);
    }

    for(cUser item : usr)
    {
        ui->createComboBox->addItem(item.getLogin());
    }
}

void FormUpdTodo::loadInfoTask(Task source)
{

    idTk = source.getIdTask();
    ui->titleTicket->setText(source.getTitre());
    ui->description->setText(source.getDescr());
    ui->dateCrea->setDateTime(QDateTime::fromString(source.getDateCreation(),"yyyy-MM-ddTHH:mm:ss"));
    ui->dateModif->setDateTime(QDateTime::fromString(source.getDateModification(),"yyyy-MM-ddTHH:mm:ss"));
    ui->dateEnd->setDateTime(QDateTime::fromString(source.getDateFinalisation(),"yyyy-MM-ddTHH:mm:ss"));
    ui->etatComboBox->setCurrentIndex(ui->etatComboBox->findText(source.getEtat()));
    ui->usrComboBox->setCurrentIndex(ui->usrComboBox->findText(source.getDev()));
    ui->createComboBox->setCurrentIndex(ui->createComboBox->findText(source.getCreateur()));


}

void FormUpdTodo::on_save_clicked()
{

    Task todo;

    todo.setIdTask(idTk);
    todo.setTitre(ui->titleTicket->text());
    todo.setDescr(ui->description->toPlainText());
    todo.setCreateur(ui->createComboBox->currentText());
    todo.setDev(ui->usrComboBox->currentText());
    todo.setEtat(ui->etatComboBox->currentText());
    todo.setDateFinalisation(ui->dateEnd->dateTime().toString("yyyy-MM-dd HH:mm:ss"));

    emit save_data(todo);
}
