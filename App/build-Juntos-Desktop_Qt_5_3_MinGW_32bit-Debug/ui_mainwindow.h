/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QWidget *menu;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *mAccueil;
    QPushButton *mTask;
    QPushButton *mTicket;
    QPushButton *mTest;
    QPushButton *mMessages;
    QPushButton *mFile;
    QPushButton *mPreference;
    QSpacerItem *verticalSpacer;
    QWidget *corps;
    QVBoxLayout *verticalLayout_2;
    QWidget *titre;
    QVBoxLayout *verticalLayout_3;
    QLabel *TitreBody;
    QWidget *contenue;
    QVBoxLayout *verticalLayout_4;
    QWidget *cFile;
    QVBoxLayout *verticalLayout_10;
    QWidget *cMessage;
    QVBoxLayout *verticalLayout_11;
    QWidget *cTest;
    QVBoxLayout *verticalLayout_9;
    QWidget *cAccueil;
    QVBoxLayout *verticalLayout_5;
    QWidget *cTask;
    QVBoxLayout *verticalLayout_6;
    QWidget *cPref;
    QVBoxLayout *verticalLayout_7;
    QWidget *cTicket;
    QVBoxLayout *verticalLayout_8;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(947, 969);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        centralWidget->setStyleSheet(QStringLiteral("Background-color: rgb(45, 186, 166); "));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        menu = new QWidget(centralWidget);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setMinimumSize(QSize(95, 0));
        menu->setMaximumSize(QSize(95, 16777215));
        verticalLayout = new QVBoxLayout(menu);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        mAccueil = new QPushButton(menu);
        mAccueil->setObjectName(QStringLiteral("mAccueil"));
        mAccueil->setMinimumSize(QSize(90, 70));
        mAccueil->setMaximumSize(QSize(108, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Helvetica Neue"));
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        font.setKerning(true);
        mAccueil->setFont(font);
        mAccueil->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/J-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        mAccueil->setIcon(icon);
        mAccueil->setIconSize(QSize(45, 40));
        mAccueil->setFlat(true);

        verticalLayout->addWidget(mAccueil);

        mTask = new QPushButton(menu);
        mTask->setObjectName(QStringLiteral("mTask"));
        mTask->setMinimumSize(QSize(90, 70));
        mTask->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/list-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        mTask->setIcon(icon1);
        mTask->setIconSize(QSize(45, 40));
        mTask->setFlat(true);

        verticalLayout->addWidget(mTask);

        mTicket = new QPushButton(menu);
        mTicket->setObjectName(QStringLiteral("mTicket"));
        mTicket->setMinimumSize(QSize(90, 70));
        mTicket->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/outline-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        mTicket->setIcon(icon2);
        mTicket->setIconSize(QSize(45, 40));
        mTicket->setFlat(true);

        verticalLayout->addWidget(mTicket);

        mTest = new QPushButton(menu);
        mTest->setObjectName(QStringLiteral("mTest"));
        mTest->setMinimumSize(QSize(90, 70));
        QFont font1;
        font1.setFamily(QStringLiteral("Helvetica Neue"));
        font1.setItalic(true);
        mTest->setFont(font1);
        mTest->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/air_force-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        mTest->setIcon(icon3);
        mTest->setIconSize(QSize(45, 40));
        mTest->setDefault(false);
        mTest->setFlat(true);

        verticalLayout->addWidget(mTest);

        mMessages = new QPushButton(menu);
        mMessages->setObjectName(QStringLiteral("mMessages"));
        mMessages->setMinimumSize(QSize(90, 70));
        mMessages->setMaximumSize(QSize(90, 70));
        mMessages->setFont(font1);
        mMessages->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/comments-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        mMessages->setIcon(icon4);
        mMessages->setIconSize(QSize(45, 40));
        mMessages->setDefault(false);
        mMessages->setFlat(true);

        verticalLayout->addWidget(mMessages);

        mFile = new QPushButton(menu);
        mFile->setObjectName(QStringLiteral("mFile"));
        mFile->setMinimumSize(QSize(90, 70));
        mFile->setFont(font1);
        mFile->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/folder-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        mFile->setIcon(icon5);
        mFile->setIconSize(QSize(45, 40));
        mFile->setDefault(false);
        mFile->setFlat(true);

        verticalLayout->addWidget(mFile);

        mPreference = new QPushButton(menu);
        mPreference->setObjectName(QStringLiteral("mPreference"));
        mPreference->setMinimumSize(QSize(90, 70));
        mPreference->setFont(font);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/settings-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        mPreference->setIcon(icon6);
        mPreference->setIconSize(QSize(45, 40));
        mPreference->setFlat(true);

        verticalLayout->addWidget(mPreference);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addWidget(menu, 0, 1, 2, 1);

        corps = new QWidget(centralWidget);
        corps->setObjectName(QStringLiteral("corps"));
        corps->setAutoFillBackground(false);
        corps->setStyleSheet(QLatin1String("background-color: white;\n"
""));
        verticalLayout_2 = new QVBoxLayout(corps);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        titre = new QWidget(corps);
        titre->setObjectName(QStringLiteral("titre"));
        titre->setMinimumSize(QSize(0, 75));
        titre->setMaximumSize(QSize(16777215, 75));
        verticalLayout_3 = new QVBoxLayout(titre);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        TitreBody = new QLabel(titre);
        TitreBody->setObjectName(QStringLiteral("TitreBody"));
        QFont font2;
        font2.setFamily(QStringLiteral("Yu Mincho Light"));
        font2.setPointSize(48);
        font2.setBold(false);
        font2.setWeight(50);
        TitreBody->setFont(font2);
        TitreBody->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(TitreBody);


        verticalLayout_2->addWidget(titre);

        contenue = new QWidget(corps);
        contenue->setObjectName(QStringLiteral("contenue"));
        verticalLayout_4 = new QVBoxLayout(contenue);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        cFile = new QWidget(contenue);
        cFile->setObjectName(QStringLiteral("cFile"));
        verticalLayout_10 = new QVBoxLayout(cFile);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));

        verticalLayout_4->addWidget(cFile);

        cMessage = new QWidget(contenue);
        cMessage->setObjectName(QStringLiteral("cMessage"));
        verticalLayout_11 = new QVBoxLayout(cMessage);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));

        verticalLayout_4->addWidget(cMessage);

        cTest = new QWidget(contenue);
        cTest->setObjectName(QStringLiteral("cTest"));
        verticalLayout_9 = new QVBoxLayout(cTest);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));

        verticalLayout_4->addWidget(cTest);

        cAccueil = new QWidget(contenue);
        cAccueil->setObjectName(QStringLiteral("cAccueil"));
        verticalLayout_5 = new QVBoxLayout(cAccueil);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        verticalLayout_4->addWidget(cAccueil);

        cTask = new QWidget(contenue);
        cTask->setObjectName(QStringLiteral("cTask"));
        cTask->setEnabled(true);
        verticalLayout_6 = new QVBoxLayout(cTask);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));

        verticalLayout_4->addWidget(cTask);

        cPref = new QWidget(contenue);
        cPref->setObjectName(QStringLiteral("cPref"));
        cPref->setEnabled(true);
        verticalLayout_7 = new QVBoxLayout(cPref);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));

        verticalLayout_4->addWidget(cPref);

        cTicket = new QWidget(contenue);
        cTicket->setObjectName(QStringLiteral("cTicket"));
        cTicket->setEnabled(true);
        verticalLayout_8 = new QVBoxLayout(cTicket);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));

        verticalLayout_4->addWidget(cTicket);


        verticalLayout_2->addWidget(contenue);


        gridLayout_2->addWidget(corps, 0, 4, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Juntos", 0));
        mAccueil->setText(QString());
        mTask->setText(QString());
        mTicket->setText(QString());
        mTest->setText(QString());
        mMessages->setText(QString());
        mFile->setText(QString());
        mPreference->setText(QString());
        TitreBody->setText(QApplication::translate("MainWindow", "Lancement", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
