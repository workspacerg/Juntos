#ifndef UIACCEUIL_H
#define UIACCEUIL_H

#include <QWidget>
#include "cprojet.h"
#include <iostream>
#include <vector>

using namespace std;

namespace Ui {
class uiAcceuil;
}

class uiAcceuil : public QWidget
{
    Q_OBJECT

private:

    bool BtCreation ;

    vector<CProjet> projects ;
    Ui::uiAcceuil *ui;

public:
    explicit uiAcceuil(QWidget *parent = 0);
    ~uiAcceuil();

    void loadTable(vector<CProjet> Source);

private slots:
    void on_addProject_clicked();
    void on_PBCreate_clicked();
    void on_PBDelProject_clicked();

signals:
    void notifiactionNewProject(QString, QString);

};

#endif // UIACCEUIL_H
