#ifndef UIFILE_H
#define UIFILE_H

#include <QDialog>
#include "share.h"

namespace Ui {
class uiFile;
}

class uiFile : public QDialog
{
    Q_OBJECT

public:
    explicit uiFile(QWidget *parent = 0);
    ~uiFile();

private slots:
    void on_BrowseButton_clicked();

    void on_uploadButton_clicked();

    void on_DownloadButton_clicked();

private:
    Ui::uiFile *ui;
    bool fileExists(const std::string&);
    void uploadFile(const std::string&);
    void downloadFile(const std::string&, std::string);

signals:
    void add_share(QString,std::string);

};

#endif // UIFILE_H
