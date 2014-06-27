#ifndef SUPPRDIALOG_H
#define SUPPRDIALOG_H

#include <QDialog>

namespace Ui {
class SupprDialog;
}

class SupprDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SupprDialog(QWidget *parent = 0);
    ~SupprDialog();

private:
    Ui::SupprDialog *ui;

signals:
    void sendText(QString);

private slots:
    void on_sent_clicked();
};

#endif // SUPPRDIALOG_H
