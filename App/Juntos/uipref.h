#ifndef UIPREF_H
#define UIPREF_H

#include <QWidget>

namespace Ui {
class uiPref;
}

class uiPref : public QWidget
{
    Q_OBJECT

public:
    explicit uiPref(QWidget *parent = 0);
    ~uiPref();

private:
    Ui::uiPref *ui;
};

#endif // UIPREF_H
