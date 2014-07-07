#ifndef UITESTUNITAIRE_H
#define UITESTUNITAIRE_H

#include <QDialog>
#include "test.h"
#include <vector>
#include "QTableWidgetItem"

using namespace std;

namespace Ui {
class UiTestUnitaire;
}

class UiTestUnitaire : public QDialog
{
    Q_OBJECT

    bool boiteDel;

public:
    explicit UiTestUnitaire(QWidget *parent = 0);
    ~UiTestUnitaire();

    void loadTable(vector<Test> Source);

private slots:
    void on_addTest_clicked();

    void on_DelTest_clicked();

    void on_tableWidgetTest_itemDoubleClicked(QTableWidgetItem *item);

    void on_confirmDel_clicked();

private:
    Ui::UiTestUnitaire *ui;

signals:
    void add_test();
    void del_test(QString idTest);
    void upd_test(int idTest);
};

#endif // UITESTUNITAIRE_H
