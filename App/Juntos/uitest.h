#ifndef UITEST_H
#define UITEST_H

#include <QDialog>

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

    void loadData();

private:
    Ui::uiTest *ui;
};

#endif // UITEST_H
