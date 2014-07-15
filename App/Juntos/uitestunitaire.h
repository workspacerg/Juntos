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
    bool boiteAdd;
    bool boiteUpd;

public:
    explicit UiTestUnitaire(QWidget *parent = 0);
    ~UiTestUnitaire();

    void loadTable(vector<Test> Source);

private slots:
    void on_addTest_clicked();

    void on_DelTest_clicked();

    void on_tableWidgetTest_itemDoubleClicked(QTableWidgetItem *item);

    void on_confirmDel_clicked();

    void on_save_test_clicked();

    void on_save_test_upd_clicked();

    void on_tableWidgetTest_itemChanged(QTableWidgetItem *item);

    void on_tableWidgetTest_itemClicked(QTableWidgetItem *item);

    void on_ok_clicked();

    void updTable();

    void on_failed_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::UiTestUnitaire *ui;

signals:
    void add_test(QString,QString,QString,QString);
    void del_test(QString idTest );
    void upd_test(QString ,QString,QString,QString,QString, int);
};

#endif // UITESTUNITAIRE_H
