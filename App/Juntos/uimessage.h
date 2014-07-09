#ifndef UIMESSAGE_H
#define UIMESSAGE_H

#include <QDialog>
#include <vector>
#include "cuser.h"

using namespace std;

namespace Ui {
class uiMessage;
}

class uiMessage : public QDialog
{
    Q_OBJECT

public:
    explicit uiMessage(QWidget *parent = 0);
    ~uiMessage();

    void loadParticipant(vector<cUser>);

private:
    Ui::uiMessage *ui;
};

#endif // UIMESSAGE_H
