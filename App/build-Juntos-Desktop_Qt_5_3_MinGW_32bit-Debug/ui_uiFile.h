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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_uiFile
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *BrowseButton;
    QPushButton *uploadButton;
    QTableWidget *tableWidgetShare;
    QPushButton *DownloadButton;

    void setupUi(QDialog *uiFile)
    {
        if (uiFile->objectName().isEmpty())
            uiFile->setObjectName(QStringLiteral("uiFile"));
        uiFile->resize(984, 601);
        verticalLayout = new QVBoxLayout(uiFile);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(uiFile);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(11);
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);

        BrowseButton = new QPushButton(uiFile);
        BrowseButton->setObjectName(QStringLiteral("BrowseButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/add_list-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        BrowseButton->setIcon(icon);
        BrowseButton->setIconSize(QSize(40, 40));
        BrowseButton->setAutoDefault(false);
        BrowseButton->setFlat(true);

        horizontalLayout->addWidget(BrowseButton);

        uploadButton = new QPushButton(uiFile);
        uploadButton->setObjectName(QStringLiteral("uploadButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/upload-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        uploadButton->setIcon(icon1);
        uploadButton->setIconSize(QSize(40, 40));
        uploadButton->setAutoDefault(false);
        uploadButton->setFlat(true);

        horizontalLayout->addWidget(uploadButton);


        verticalLayout->addLayout(horizontalLayout);

        tableWidgetShare = new QTableWidget(uiFile);
        tableWidgetShare->setObjectName(QStringLiteral("tableWidgetShare"));

        verticalLayout->addWidget(tableWidgetShare);

        DownloadButton = new QPushButton(uiFile);
        DownloadButton->setObjectName(QStringLiteral("DownloadButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/downloads-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        DownloadButton->setIcon(icon2);
        DownloadButton->setIconSize(QSize(40, 40));
        DownloadButton->setAutoDefault(false);
        DownloadButton->setFlat(true);

        verticalLayout->addWidget(DownloadButton);


        retranslateUi(uiFile);

        QMetaObject::connectSlotsByName(uiFile);
    } // setupUi

    void retranslateUi(QDialog *uiFile)
    {
        uiFile->setWindowTitle(QApplication::translate("uiFile", "Dialog", 0));
        BrowseButton->setText(QString());
        uploadButton->setText(QString());
        DownloadButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class uiFile: public Ui_uiFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIFILE_H
