/********************************************************************************
** Form generated from reading UI file 'uimessage.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIMESSAGE_H
#define UI_UIMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_uiMessage
{
public:
    QHBoxLayout *horizontalLayout_2;
    QListWidget *User;
    QVBoxLayout *verticalLayout;
    QListWidget *Messages;
    QHBoxLayout *horizontalLayout;
    QLineEdit *myMessage;
    QPushButton *sendMessage;

    void setupUi(QDialog *uiMessage)
    {
        if (uiMessage->objectName().isEmpty())
            uiMessage->setObjectName(QStringLiteral("uiMessage"));
        uiMessage->resize(974, 650);
        horizontalLayout_2 = new QHBoxLayout(uiMessage);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        User = new QListWidget(uiMessage);
        User->setObjectName(QStringLiteral("User"));
        User->setMaximumSize(QSize(300, 16777215));
        QFont font;
        font.setPointSize(12);
        User->setFont(font);

        horizontalLayout_2->addWidget(User);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Messages = new QListWidget(uiMessage);
        Messages->setObjectName(QStringLiteral("Messages"));
        QFont font1;
        font1.setPointSize(14);
        Messages->setFont(font1);

        verticalLayout->addWidget(Messages);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        myMessage = new QLineEdit(uiMessage);
        myMessage->setObjectName(QStringLiteral("myMessage"));
        myMessage->setMinimumSize(QSize(500, 50));
        myMessage->setMaximumSize(QSize(16777215, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("MV Boli"));
        font2.setPointSize(13);
        font2.setBold(false);
        font2.setWeight(50);
        font2.setKerning(true);
        myMessage->setFont(font2);

        horizontalLayout->addWidget(myMessage);

        sendMessage = new QPushButton(uiMessage);
        sendMessage->setObjectName(QStringLiteral("sendMessage"));
        sendMessage->setMinimumSize(QSize(0, 40));
        sendMessage->setAutoDefault(false);
        sendMessage->setFlat(true);

        horizontalLayout->addWidget(sendMessage);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(uiMessage);

        QMetaObject::connectSlotsByName(uiMessage);
    } // setupUi

    void retranslateUi(QDialog *uiMessage)
    {
        uiMessage->setWindowTitle(QApplication::translate("uiMessage", "Dialog", 0));
        myMessage->setPlaceholderText(QApplication::translate("uiMessage", "Votre message ...", 0));
        sendMessage->setText(QApplication::translate("uiMessage", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class uiMessage: public Ui_uiMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIMESSAGE_H
