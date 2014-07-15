/********************************************************************************
** Form generated from reading UI file 'uipref.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIPREF_H
#define UI_UIPREF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uiPref
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *bddType;
    QLabel *label_2;
    QLineEdit *bddName;
    QLabel *label_4;
    QLineEdit *bddUser;
    QLabel *label_3;
    QLineEdit *bddPass;
    QLabel *label_5;
    QLineEdit *login;
    QLabel *label_6;
    QLineEdit *keypass;
    QPushButton *SaveButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *uiPref)
    {
        if (uiPref->objectName().isEmpty())
            uiPref->setObjectName(QStringLiteral("uiPref"));
        uiPref->resize(771, 590);
        gridLayout = new QGridLayout(uiPref);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(uiPref);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Helvetica Neue"));
        font.setPointSize(16);
        label->setFont(font);

        verticalLayout->addWidget(label);

        bddType = new QLineEdit(uiPref);
        bddType->setObjectName(QStringLiteral("bddType"));
        bddType->setMinimumSize(QSize(500, 35));
        bddType->setMaximumSize(QSize(500, 16777215));

        verticalLayout->addWidget(bddType);

        label_2 = new QLabel(uiPref);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        bddName = new QLineEdit(uiPref);
        bddName->setObjectName(QStringLiteral("bddName"));
        bddName->setMinimumSize(QSize(500, 35));
        bddName->setMaximumSize(QSize(500, 16777215));

        verticalLayout->addWidget(bddName);

        label_4 = new QLabel(uiPref);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        bddUser = new QLineEdit(uiPref);
        bddUser->setObjectName(QStringLiteral("bddUser"));
        bddUser->setMinimumSize(QSize(500, 35));
        bddUser->setMaximumSize(QSize(500, 16777215));

        verticalLayout->addWidget(bddUser);

        label_3 = new QLabel(uiPref);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        bddPass = new QLineEdit(uiPref);
        bddPass->setObjectName(QStringLiteral("bddPass"));
        bddPass->setMinimumSize(QSize(500, 35));
        bddPass->setMaximumSize(QSize(500, 16777215));
        bddPass->setInputMethodHints(Qt::ImhHiddenText);

        verticalLayout->addWidget(bddPass);

        label_5 = new QLabel(uiPref);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        login = new QLineEdit(uiPref);
        login->setObjectName(QStringLiteral("login"));
        login->setMinimumSize(QSize(500, 35));
        login->setMaximumSize(QSize(500, 16777215));

        verticalLayout->addWidget(login);

        label_6 = new QLabel(uiPref);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        keypass = new QLineEdit(uiPref);
        keypass->setObjectName(QStringLiteral("keypass"));
        keypass->setMinimumSize(QSize(500, 35));
        keypass->setMaximumSize(QSize(500, 16777215));
        keypass->setInputMethodHints(Qt::ImhHiddenText);

        verticalLayout->addWidget(keypass);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        SaveButton = new QPushButton(uiPref);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/cloud-minus@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        SaveButton->setIcon(icon);
        SaveButton->setIconSize(QSize(35, 35));
        SaveButton->setFlat(true);

        gridLayout->addWidget(SaveButton, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 141, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(uiPref);

        QMetaObject::connectSlotsByName(uiPref);
    } // setupUi

    void retranslateUi(QWidget *uiPref)
    {
        uiPref->setWindowTitle(QApplication::translate("uiPref", "Form", 0));
        label->setText(QApplication::translate("uiPref", "Type BDD", 0));
        label_2->setText(QApplication::translate("uiPref", "Base de donn\303\251e ", 0));
        label_4->setText(QApplication::translate("uiPref", "User BDD", 0));
        label_3->setText(QApplication::translate("uiPref", "Password BDD", 0));
        label_5->setText(QApplication::translate("uiPref", "Login", 0));
        label_6->setText(QApplication::translate("uiPref", "Password", 0));
        SaveButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class uiPref: public Ui_uiPref {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIPREF_H
