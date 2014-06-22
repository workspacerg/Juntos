#ifndef UIACCEUIL_H
#define UIACCEUIL_H

#include <QWidget>
#include "cprojet.h"
#include <iostream>
#include <vector>
#include <QTableWidgetItem>

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
    void on_updTable_clicked();
    void on_tableWidgetPtoject_itemDoubleClicked(QTableWidgetItem *item);

signals:
    void notifiactionNewProject(QString, QString);
    void sigLoadTable();
    void sigAddPro(CProjet);
    void sigDelPro(CProjet);
    void sigSelectCurrentPro(CProjet);


};

#endif // UIACCEUIL_H
