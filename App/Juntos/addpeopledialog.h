#ifndef ADDPEOPLEDIALOG_H
#define ADDPEOPLEDIALOG_H

#include <QDialog>
#include <vector>
#include "cuser.h"


using namespace std;


namespace Ui {

    class addPeopleDialog;

}

class addPeopleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addPeopleDialog(QWidget *parent = 0 );
    ~addPeopleDialog();
 Ui::addPeopleDialog *ui;
    void loadParticipant(vector<cUser>);
void disableModification();
private:

    vector<cUser> users;
};

#endif // ADDPEOPLEDIALOG_H
