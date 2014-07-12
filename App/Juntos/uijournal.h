#ifndef UIJOURNAL_H
#define UIJOURNAL_H

#include <QDialog>
#include <vector>
#include "cjournal.h"

using namespace std;

namespace Ui {
class uiJournal;
}

class uiJournal : public QDialog
{
    Q_OBJECT

public:
    explicit uiJournal(QWidget *parent = 0);
    ~uiJournal();

    void loadJournal(vector<cJournal> j);

private:
    Ui::uiJournal *ui;
    void closeEvent( QCloseEvent* event );

};

#endif // UIJOURNAL_H
