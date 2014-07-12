#ifndef UIFILE_H
#define UIFILE_H

#include <QDialog>
#include <QTableWidgetItem>
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
    void loadTable(std::map<Share,QString>);

private slots:
    void on_BrowseButton_clicked();

    void on_uploadButton_clicked();

    void on_DownloadButton_clicked();

    void on_tableWidgetShare_itemClicked(QTableWidgetItem *item);

    void on_tableWidgetShare_itemSelectionChanged();

private:
    Ui::uiFile *ui;
    std::map<Share,QString> map;
    QTableWidgetItem *current_item;
    bool fileExists(const std::string&);
    void uploadFile(const std::string&);
    void downloadFile(QByteArray content,QString extension);

signals:
    void add_share(std::string,QByteArray);

};

#endif // UIFILE_H
