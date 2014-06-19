#include "uipref.h"
#include "ui_uipref.h"

uiPref::uiPref(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiPref)
{
    ui->setupUi(this);

    loadPref();

}

uiPref::~uiPref()
{
    delete ui;
}

void uiPref::loadPref()
{

    // Ouverture du fichier INI
    QSettings settings("config.ini", QSettings::IniFormat);

    QString user = settings.value("bddConfig/user","config").toString();
    QString password = settings.value("bddConfig/password","config").toString();
    QString host = settings.value("bddConfig/host","config").toString();
    QString name = settings.value("bddConfig/name","config").toString();

    ui->bddUser->setText(user);
    ui->bddPass->setText(password);
    ui->bddType->setText(host);
    ui->bddName->setText(name);

}

void uiPref::on_SaveButton_clicked()
{

    QSettings settings("config.ini", QSettings::IniFormat);

    settings.setValue("bddConfig/user",ui->bddUser->text());
    settings.setValue("bddConfig/password",ui->bddPass->text());
    settings.setValue("bddConfig/host",ui->bddType->text());
    settings.setValue("bddConfig/name",ui->bddName->text());


    emit newParamConnect();
}
