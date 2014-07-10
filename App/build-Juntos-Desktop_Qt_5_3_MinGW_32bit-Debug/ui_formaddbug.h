/********************************************************************************
** Form generated from reading UI file 'formaddbug.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMADDBUG_H
#define UI_FORMADDBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_formAddBug
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *titleTicket;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QComboBox *usrComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *etatComboBox;
    QLabel *label_3;
    QTextEdit *description;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *save;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *formAddBug)
    {
        if (formAddBug->objectName().isEmpty())
            formAddBug->setObjectName(QStringLiteral("formAddBug"));
        formAddBug->resize(721, 698);
        verticalLayout = new QVBoxLayout(formAddBug);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(formAddBug);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setFamily(QStringLiteral("SketchFlow Print"));
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(formAddBug);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Yi Baiti"));
        font1.setPointSize(18);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        titleTicket = new QLineEdit(formAddBug);
        titleTicket->setObjectName(QStringLiteral("titleTicket"));
        titleTicket->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(titleTicket);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(formAddBug);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        usrComboBox = new QComboBox(formAddBug);
        usrComboBox->setObjectName(QStringLiteral("usrComboBox"));
        usrComboBox->setMinimumSize(QSize(250, 35));
        QFont font2;
        font2.setPointSize(11);
        usrComboBox->setFont(font2);

        horizontalLayout_2->addWidget(usrComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(formAddBug);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        etatComboBox = new QComboBox(formAddBug);
        etatComboBox->setObjectName(QStringLiteral("etatComboBox"));
        etatComboBox->setMinimumSize(QSize(250, 35));
        etatComboBox->setFont(font2);
        etatComboBox->setFrame(true);

        horizontalLayout_3->addWidget(etatComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        label_3 = new QLabel(formAddBug);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        description = new QTextEdit(formAddBug);
        description->setObjectName(QStringLiteral("description"));

        verticalLayout->addWidget(description);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        save = new QPushButton(formAddBug);
        save->setObjectName(QStringLiteral("save"));

        horizontalLayout_4->addWidget(save);

        cancel = new QPushButton(formAddBug);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout_4->addWidget(cancel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(formAddBug);

        QMetaObject::connectSlotsByName(formAddBug);
    } // setupUi

    void retranslateUi(QDialog *formAddBug)
    {
        formAddBug->setWindowTitle(QApplication::translate("formAddBug", "Dialog", 0));
        label->setText(QApplication::translate("formAddBug", "Cr\303\251ation d'un ticket", 0));
        label_2->setText(QApplication::translate("formAddBug", "Titre :", 0));
        label_5->setText(QApplication::translate("formAddBug", "Assign\303\251 \303\240 :", 0));
        label_6->setText(QApplication::translate("formAddBug", "Etat d'avancement :", 0));
        etatComboBox->clear();
        etatComboBox->insertItems(0, QStringList()
         << QApplication::translate("formAddBug", "ouvert", 0)
         << QApplication::translate("formAddBug", "accept\303\251", 0)
         << QApplication::translate("formAddBug", "confirm\303\251", 0)
         << QApplication::translate("formAddBug", "affect\303\251", 0)
         << QApplication::translate("formAddBug", "r\303\251solu", 0)
         << QApplication::translate("formAddBug", "ferm\303\251", 0)
         << QApplication::translate("formAddBug", "rejet\303\251", 0)
        );
        label_3->setText(QApplication::translate("formAddBug", "Description", 0));
        save->setText(QApplication::translate("formAddBug", "Sauvegarder", 0));
        cancel->setText(QApplication::translate("formAddBug", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class formAddBug: public Ui_formAddBug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMADDBUG_H
