/********************************************************************************
** Form generated from reading UI file 'uitask.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UITASK_H
#define UI_UITASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uiTask
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *mesTaches;
    QCheckBox *nonAssign;
    QCheckBox *autreTache;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidgetTask;
    QWidget *delBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *delLine;
    QPushButton *confirmDel;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *addTask;
    QPushButton *DelTask;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *uiTask)
    {
        if (uiTask->objectName().isEmpty())
            uiTask->setObjectName(QStringLiteral("uiTask"));
        uiTask->resize(825, 592);
        verticalLayout_2 = new QVBoxLayout(uiTask);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lineEdit = new QLineEdit(uiTask);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(500, 35));
        lineEdit->setMaximumSize(QSize(500, 16777215));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mesTaches = new QCheckBox(uiTask);
        mesTaches->setObjectName(QStringLiteral("mesTaches"));
        QFont font;
        font.setFamily(QStringLiteral("Helvetica Neue"));
        font.setPointSize(15);
        mesTaches->setFont(font);

        horizontalLayout->addWidget(mesTaches);

        nonAssign = new QCheckBox(uiTask);
        nonAssign->setObjectName(QStringLiteral("nonAssign"));
        nonAssign->setFont(font);

        horizontalLayout->addWidget(nonAssign);

        autreTache = new QCheckBox(uiTask);
        autreTache->setObjectName(QStringLiteral("autreTache"));
        autreTache->setFont(font);

        horizontalLayout->addWidget(autreTache);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        tableWidgetTask = new QTableWidget(uiTask);
        tableWidgetTask->setObjectName(QStringLiteral("tableWidgetTask"));
        tableWidgetTask->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetTask->setAlternatingRowColors(true);
        tableWidgetTask->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetTask->setSortingEnabled(true);

        verticalLayout_2->addWidget(tableWidgetTask);

        delBox = new QWidget(uiTask);
        delBox->setObjectName(QStringLiteral("delBox"));
        verticalLayout = new QVBoxLayout(delBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(delBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        delLine = new QLineEdit(delBox);
        delLine->setObjectName(QStringLiteral("delLine"));
        delLine->setMinimumSize(QSize(300, 60));
        delLine->setMaximumSize(QSize(300, 60));
        QFont font2;
        font2.setPointSize(13);
        delLine->setFont(font2);

        horizontalLayout_4->addWidget(delLine);

        confirmDel = new QPushButton(delBox);
        confirmDel->setObjectName(QStringLiteral("confirmDel"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/dnd-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        confirmDel->setIcon(icon);
        confirmDel->setIconSize(QSize(40, 40));
        confirmDel->setFlat(true);

        horizontalLayout_4->addWidget(confirmDel);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(delBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        addTask = new QPushButton(uiTask);
        addTask->setObjectName(QStringLiteral("addTask"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/box-plus@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        addTask->setIcon(icon1);
        addTask->setIconSize(QSize(40, 40));
        addTask->setFlat(true);

        horizontalLayout_3->addWidget(addTask);

        DelTask = new QPushButton(uiTask);
        DelTask->setObjectName(QStringLiteral("DelTask"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/box-minus@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        DelTask->setIcon(icon2);
        DelTask->setIconSize(QSize(40, 40));
        DelTask->setFlat(true);

        horizontalLayout_3->addWidget(DelTask);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(uiTask);

        QMetaObject::connectSlotsByName(uiTask);
    } // setupUi

    void retranslateUi(QWidget *uiTask)
    {
        uiTask->setWindowTitle(QApplication::translate("uiTask", "Form", 0));
        lineEdit->setPlaceholderText(QApplication::translate("uiTask", "Recherche ...", 0));
        mesTaches->setText(QApplication::translate("uiTask", "Mes T\303\242ches", 0));
        nonAssign->setText(QApplication::translate("uiTask", "Non Assign\303\251e", 0));
        autreTache->setText(QApplication::translate("uiTask", "Les autres", 0));
        label->setText(QApplication::translate("uiTask", "Pour supprimer la t\303\242ches, \303\251crivez SUPPRIMER ci-dessous.", 0));
        confirmDel->setText(QString());
        addTask->setText(QString());
        DelTask->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class uiTask: public Ui_uiTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UITASK_H
