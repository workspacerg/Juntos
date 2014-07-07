#ifndef UITEST_H
#define UITEST_H

#include <QDialog>
#include "test.h"
#include <vector>

using namespace std;

namespace Ui {
class uiTest;
}

class uiTest : public QDialog
{
    Q_OBJECT

public:
    explicit uiTest(QWidget *parent = 0);
    ~uiTest();

    //
    // ---------------------------------------------
    //

    void loadTable(vector<Test> Source);

private:
    Ui::uiTest *ui;
};

#endif // UITEST_H
