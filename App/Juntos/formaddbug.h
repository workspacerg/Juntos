#ifndef FORMADDBUG_H
#define FORMADDBUG_H

#include <QDialog>

namespace Ui {
class formAddBug;
}

class formAddBug : public QDialog
{
    Q_OBJECT

public:
    explicit formAddBug(QWidget *parent = 0);
    ~formAddBug();

private:
    Ui::formAddBug *ui;
};

#endif // FORMADDBUG_H
