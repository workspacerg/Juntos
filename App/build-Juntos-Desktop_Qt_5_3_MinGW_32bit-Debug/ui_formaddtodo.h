/********************************************************************************
** Form generated from reading UI file 'formaddtodo.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMADDTODO_H
#define UI_FORMADDTODO_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_formAddTodo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *titleTicket;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QComboBox *usrComboBox;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_7;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QComboBox *etatComboBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QTextEdit *description;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *save;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *formAddTodo)
    {
        if (formAddTodo->objectName().isEmpty())
            formAddTodo->setObjectName(QStringLiteral("formAddTodo"));
        formAddTodo->resize(845, 833);
        verticalLayout = new QVBoxLayout(formAddTodo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(formAddTodo);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setFamily(QStringLiteral("SketchFlow Print"));
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(formAddTodo);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Yi Baiti"));
        font1.setPointSize(18);
        label_2->setFont(font1);

        horizontalLayout_4->addWidget(label_2);

        titleTicket = new QLineEdit(formAddTodo);
        titleTicket->setObjectName(QStringLiteral("titleTicket"));
        titleTicket->setMinimumSize(QSize(0, 40));

        horizontalLayout_4->addWidget(titleTicket);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(formAddTodo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout->addWidget(label_5);

        usrComboBox = new QComboBox(formAddTodo);
        usrComboBox->setObjectName(QStringLiteral("usrComboBox"));
        usrComboBox->setMinimumSize(QSize(250, 35));
        QFont font2;
        font2.setPointSize(11);
        usrComboBox->setFont(font2);

        horizontalLayout->addWidget(usrComboBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_7 = new QLabel(formAddTodo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        horizontalLayout->addWidget(label_7);

        dateTimeEdit = new QDateTimeEdit(formAddTodo);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setMinimumSize(QSize(250, 35));
        dateTimeEdit->setFont(font2);

        horizontalLayout->addWidget(dateTimeEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(formAddTodo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_3->addWidget(label_6);

        etatComboBox = new QComboBox(formAddTodo);
        etatComboBox->setObjectName(QStringLiteral("etatComboBox"));
        etatComboBox->setMinimumSize(QSize(250, 35));
        etatComboBox->setFont(font2);
        etatComboBox->setFrame(true);

        horizontalLayout_3->addWidget(etatComboBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        label_3 = new QLabel(formAddTodo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        description = new QTextEdit(formAddTodo);
        description->setObjectName(QStringLiteral("description"));

        verticalLayout->addWidget(description);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        save = new QPushButton(formAddTodo);
        save->setObjectName(QStringLiteral("save"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/add_database-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon);
        save->setIconSize(QSize(30, 30));
        save->setAutoDefault(false);
        save->setFlat(true);

        horizontalLayout_2->addWidget(save);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(formAddTodo);

        QMetaObject::connectSlotsByName(formAddTodo);
    } // setupUi

    void retranslateUi(QDialog *formAddTodo)
    {
        formAddTodo->setWindowTitle(QApplication::translate("formAddTodo", "Dialog", 0));
        label->setText(QApplication::translate("formAddTodo", "Cr\303\251ation d'une t\303\242che", 0));
        label_2->setText(QApplication::translate("formAddTodo", "Titre :", 0));
        label_5->setText(QApplication::translate("formAddTodo", "Assign\303\251 \303\240 :", 0));
        label_7->setText(QApplication::translate("formAddTodo", "Pour le : ", 0));
        label_6->setText(QApplication::translate("formAddTodo", "Avancement :", 0));
        label_3->setText(QApplication::translate("formAddTodo", "Description", 0));
        save->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class formAddTodo: public Ui_formAddTodo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMADDTODO_H
