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

    QString user = settings.value("bddConfig/user","root").toString();
    QString password = settings.value("bddConfig/password","root").toString();
    QString host = settings.value("bddConfig/host","QODBC3").toString();
    QString name = settings.value("bddConfig/name","juntos_connect").toString();

    QString login = settings.value("utilisateur/login","").toString();
    QString keypass = settings.value("utilisateur/paswword","").toString();


    ui->bddUser->setText(user);
    ui->bddPass->setText(password);
    ui->bddType->setText(host);
    ui->bddName->setText(name);
    ui->login->setText(login);
    ui->keypass->setText(keypass);

}

void uiPref::on_SaveButton_clicked()
{

    QSettings settings("config.ini", QSettings::IniFormat);

    settings.setValue("bddConfig/user",ui->bddUser->text());
    settings.setValue("bddConfig/password",ui->bddPass->text());
    settings.setValue("bddConfig/host",ui->bddType->text());
    settings.setValue("bddConfig/name",ui->bddName->text());
    settings.setValue("utilisateur/login",ui->login->text());
    settings.setValue("utilisateur/paswword",ui->keypass->text());


    emit newParamConnect();
}
