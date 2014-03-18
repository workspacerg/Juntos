#ifndef UITICKET_H
#define UITICKET_H

#include <QWidget>

namespace Ui {
class uiTicket;
}

class uiTicket : public QWidget
{
    Q_OBJECT

public:
    explicit uiTicket(QWidget *parent = 0);
    ~uiTicket();

private:
    Ui::uiTicket *ui;
};

#endif // UITICKET_H
