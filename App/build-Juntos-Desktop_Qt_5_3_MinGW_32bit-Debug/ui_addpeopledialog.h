/********************************************************************************
** Form generated from reading UI file 'addpeopledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPEOPLEDIALOG_H
#define UI_ADDPEOPLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addPeopleDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *modCenter;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *add;
    QPushButton *dell;
    QTableWidget *tableWidget;

    void setupUi(QDialog *addPeopleDialog)
    {
        if (addPeopleDialog->objectName().isEmpty())
            addPeopleDialog->setObjectName(QStringLiteral("addPeopleDialog"));
        addPeopleDialog->resize(480, 640);
        verticalLayout = new QVBoxLayout(addPeopleDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(addPeopleDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setFamily(QStringLiteral("SketchFlow Print"));
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        modCenter = new QHBoxLayout();
        modCenter->setObjectName(QStringLiteral("modCenter"));
        lineEdit = new QLineEdit(addPeopleDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(370, 0));

        modCenter->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        modCenter->addItem(horizontalSpacer_2);

        add = new QPushButton(addPeopleDialog);
        add->setObjectName(QStringLiteral("add"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/plus-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);
        add->setIconSize(QSize(25, 25));
        add->setAutoDefault(false);
        add->setFlat(true);

        modCenter->addWidget(add);

        dell = new QPushButton(addPeopleDialog);
        dell->setObjectName(QStringLiteral("dell"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/dnd-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        dell->setIcon(icon1);
        dell->setIconSize(QSize(25, 25));
        dell->setAutoDefault(false);
        dell->setFlat(true);

        modCenter->addWidget(dell);


        verticalLayout->addLayout(modCenter);

        tableWidget = new QTableWidget(addPeopleDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(addPeopleDialog);

        QMetaObject::connectSlotsByName(addPeopleDialog);
    } // setupUi

    void retranslateUi(QDialog *addPeopleDialog)
    {
        addPeopleDialog->setWindowTitle(QApplication::translate("addPeopleDialog", "Dialog", 0));
        label->setText(QApplication::translate("addPeopleDialog", "Participant au projet ", 0));
        lineEdit->setPlaceholderText(QApplication::translate("addPeopleDialog", "Login", 0));
        add->setText(QString());
        dell->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class addPeopleDialog: public Ui_addPeopleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPEOPLEDIALOG_H
