/********************************************************************************
** Form generated from reading UI file 'formupdbug.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMUPDBUG_H
#define UI_FORMUPDBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_formUpdBug
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *titleTicket;
    QLabel *label_10;
    QComboBox *createComboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QComboBox *usrComboBox;
    QLabel *label_6;
    QComboBox *etatComboBox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QDateTimeEdit *dateCrea;
    QDateTimeEdit *dateEnd;
    QDateTimeEdit *dateAssign;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextEdit *description;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *save;

    void setupUi(QDialog *formUpdBug)
    {
        if (formUpdBug->objectName().isEmpty())
            formUpdBug->setObjectName(QStringLiteral("formUpdBug"));
        formUpdBug->resize(837, 783);
        verticalLayout_4 = new QVBoxLayout(formUpdBug);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(formUpdBug);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setFamily(QStringLiteral("SketchFlow Print"));
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(formUpdBug);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Yi Baiti"));
        font1.setPointSize(18);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        titleTicket = new QLineEdit(formUpdBug);
        titleTicket->setObjectName(QStringLiteral("titleTicket"));
        titleTicket->setMinimumSize(QSize(400, 40));
        QFont font2;
        font2.setPointSize(11);
        titleTicket->setFont(font2);

        horizontalLayout_2->addWidget(titleTicket);

        label_10 = new QLabel(formUpdBug);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        horizontalLayout_2->addWidget(label_10);

        createComboBox = new QComboBox(formUpdBug);
        createComboBox->setObjectName(QStringLiteral("createComboBox"));
        createComboBox->setMinimumSize(QSize(180, 35));
        createComboBox->setFont(font2);

        horizontalLayout_2->addWidget(createComboBox);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(formUpdBug);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout->addWidget(label_5);

        usrComboBox = new QComboBox(formUpdBug);
        usrComboBox->setObjectName(QStringLiteral("usrComboBox"));
        usrComboBox->setMinimumSize(QSize(180, 35));
        usrComboBox->setFont(font2);

        horizontalLayout->addWidget(usrComboBox);

        label_6 = new QLabel(formUpdBug);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout->addWidget(label_6);

        etatComboBox = new QComboBox(formUpdBug);
        etatComboBox->setObjectName(QStringLiteral("etatComboBox"));
        etatComboBox->setMinimumSize(QSize(180, 35));
        etatComboBox->setFont(font2);
        etatComboBox->setFrame(true);

        horizontalLayout->addWidget(etatComboBox);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_7 = new QLabel(formUpdBug);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(150, 0));
        label_7->setMaximumSize(QSize(150, 16777215));
        label_7->setFont(font1);

        verticalLayout_3->addWidget(label_7);

        label_9 = new QLabel(formUpdBug);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(150, 0));
        label_9->setMaximumSize(QSize(150, 16777215));
        label_9->setFont(font1);

        verticalLayout_3->addWidget(label_9);

        label_8 = new QLabel(formUpdBug);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(150, 0));
        label_8->setMaximumSize(QSize(150, 16777215));
        label_8->setFont(font1);

        verticalLayout_3->addWidget(label_8);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        dateCrea = new QDateTimeEdit(formUpdBug);
        dateCrea->setObjectName(QStringLiteral("dateCrea"));
        dateCrea->setEnabled(false);
        dateCrea->setMinimumSize(QSize(200, 30));
        dateCrea->setFont(font2);

        verticalLayout_2->addWidget(dateCrea);

        dateEnd = new QDateTimeEdit(formUpdBug);
        dateEnd->setObjectName(QStringLiteral("dateEnd"));
        dateEnd->setEnabled(false);
        dateEnd->setMinimumSize(QSize(200, 30));
        dateEnd->setFont(font2);

        verticalLayout_2->addWidget(dateEnd);

        dateAssign = new QDateTimeEdit(formUpdBug);
        dateAssign->setObjectName(QStringLiteral("dateAssign"));
        dateAssign->setEnabled(false);
        dateAssign->setMinimumSize(QSize(200, 30));
        dateAssign->setFont(font2);

        verticalLayout_2->addWidget(dateAssign);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(formUpdBug);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        description = new QTextEdit(formUpdBug);
        description->setObjectName(QStringLiteral("description"));

        verticalLayout->addWidget(description);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        save = new QPushButton(formUpdBug);
        save->setObjectName(QStringLiteral("save"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/available_updates-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon);
        save->setIconSize(QSize(30, 30));
        save->setAutoDefault(false);
        save->setFlat(true);

        horizontalLayout_4->addWidget(save);


        verticalLayout_4->addLayout(horizontalLayout_4);


        retranslateUi(formUpdBug);

        QMetaObject::connectSlotsByName(formUpdBug);
    } // setupUi

    void retranslateUi(QDialog *formUpdBug)
    {
        formUpdBug->setWindowTitle(QApplication::translate("formUpdBug", "Dialog", 0));
        label->setText(QApplication::translate("formUpdBug", "Details Ticket", 0));
        label_2->setText(QApplication::translate("formUpdBug", "Titre :", 0));
        label_10->setText(QApplication::translate("formUpdBug", "Cr\303\251e par :", 0));
        label_5->setText(QApplication::translate("formUpdBug", "Assign\303\251 \303\240 :", 0));
        label_6->setText(QApplication::translate("formUpdBug", "Etat d'avancement :", 0));
        etatComboBox->clear();
        etatComboBox->insertItems(0, QStringList()
         << QApplication::translate("formUpdBug", "ouvert", 0)
         << QApplication::translate("formUpdBug", "accept\303\251", 0)
         << QApplication::translate("formUpdBug", "confirm\303\251", 0)
         << QApplication::translate("formUpdBug", "affect\303\251", 0)
         << QApplication::translate("formUpdBug", "r\303\251solu", 0)
         << QApplication::translate("formUpdBug", "ferm\303\251", 0)
         << QApplication::translate("formUpdBug", "rejet\303\251", 0)
        );
        label_7->setText(QApplication::translate("formUpdBug", "Cr\303\251ation", 0));
        label_9->setText(QApplication::translate("formUpdBug", "Fermeture", 0));
        label_8->setText(QApplication::translate("formUpdBug", "Assignation", 0));
        label_3->setText(QApplication::translate("formUpdBug", "Description", 0));
        save->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class formUpdBug: public Ui_formUpdBug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMUPDBUG_H
