#ifndef ADDPEOPLEDIALOG_H
#define ADDPEOPLEDIALOG_H

#include <QDialog>


namespace Ui {
class addPeopleDialog;
}

class addPeopleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addPeopleDialog(QWidget *parent = 0);
    ~addPeopleDialog();

private:
    Ui::addPeopleDialog *ui;
};

#endif // ADDPEOPLEDIALOG_H
