#ifndef UIFILE_H
#define UIFILE_H

#include <QDialog>

namespace Ui {
class uiFile;
}

class uiFile : public QDialog
{
    Q_OBJECT

public:
    explicit uiFile(QWidget *parent = 0);
    ~uiFile();

private:
    Ui::uiFile *ui;
};

#endif // UIFILE_H
