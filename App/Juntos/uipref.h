#ifndef UIPREF_H
#define UIPREF_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class uiPref;
}

class uiPref : public QWidget
{
    Q_OBJECT

public:
    explicit uiPref(QWidget *parent = 0);
    ~uiPref();

     void loadPref();

private:
    Ui::uiPref *ui;

signals:
    void newParamConnect();

private slots:
    void on_SaveButton_clicked();
};

#endif // UIPREF_H
