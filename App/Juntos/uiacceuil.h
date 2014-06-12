#ifndef UIACCEUIL_H
#define UIACCEUIL_H

#include <QWidget>
#include "cprojet.h"

namespace Ui {
class uiAcceuil;
}

class uiAcceuil : public QWidget
{
    Q_OBJECT

public:
    explicit uiAcceuil(QWidget *parent = 0);
    ~uiAcceuil();

signals:
    void notifiactionNewProject(QString, QString);

private slots:
    void on_addProject_clicked();


    void on_PBCreate_clicked();

    void on_PBDelProject_clicked();

private:
    Ui::uiAcceuil *ui;

       bool BtCreation ;
};

#endif // UIACCEUIL_H
