#ifndef FORMDELBUG_H
#define FORMDELBUG_H

#include <QDialog>

namespace Ui {
class formDelBug;
}

class formDelBug : public QDialog
{
    Q_OBJECT

public:
    explicit formDelBug(QWidget *parent = 0);
    ~formDelBug();

private:
    Ui::formDelBug *ui;
};

#endif // FORMDELBUG_H
