/********************************************************************************
** Form generated from reading UI file 'uiFile.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIFILE_H
#define UI_UIFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_uiFile
{
public:
    QListView *listView;
    QPushButton *BrowseButton;
    QPushButton *DownloadButton;
    QLineEdit *lineEdit;
    QPushButton *uploadButton;

    void setupUi(QDialog *uiFile)
    {
        if (uiFile->objectName().isEmpty())
            uiFile->setObjectName(QStringLiteral("uiFile"));
        uiFile->resize(984, 601);
        listView = new QListView(uiFile);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(80, 40, 381, 411));
        BrowseButton = new QPushButton(uiFile);
        BrowseButton->setObjectName(QStringLiteral("BrowseButton"));
        BrowseButton->setGeometry(QRect(690, 140, 75, 21));
        DownloadButton = new QPushButton(uiFile);
        DownloadButton->setObjectName(QStringLiteral("DownloadButton"));
        DownloadButton->setGeometry(QRect(80, 10, 75, 23));
        lineEdit = new QLineEdit(uiFile);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(540, 140, 141, 20));
        uploadButton = new QPushButton(uiFile);
        uploadButton->setObjectName(QStringLiteral("uploadButton"));
        uploadButton->setGeometry(QRect(580, 170, 75, 21));

        retranslateUi(uiFile);

        QMetaObject::connectSlotsByName(uiFile);
    } // setupUi

    void retranslateUi(QDialog *uiFile)
    {
        uiFile->setWindowTitle(QApplication::translate("uiFile", "Dialog", 0));
        BrowseButton->setText(QApplication::translate("uiFile", "Browse", 0));
        DownloadButton->setText(QApplication::translate("uiFile", "Download", 0));
        uploadButton->setText(QApplication::translate("uiFile", "Upload", 0));
    } // retranslateUi

};

namespace Ui {
    class uiFile: public Ui_uiFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIFILE_H
