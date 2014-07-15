/********************************************************************************
** Form generated from reading UI file 'uiticket.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UITICKET_H
#define UI_UITICKET_H

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

class Ui_uiTicket
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *resolus;
    QCheckBox *mesTk;
    QCheckBox *autreTk;
    QCheckBox *nonAssign;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidgetTicket;
    QWidget *delBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *delLine;
    QPushButton *confirmDel;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addBug;
    QPushButton *delBug;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *uiTicket)
    {
        if (uiTicket->objectName().isEmpty())
            uiTicket->setObjectName(QStringLiteral("uiTicket"));
        uiTicket->resize(814, 662);
        verticalLayout_2 = new QVBoxLayout(uiTicket);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(uiTicket);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(500, 35));
        lineEdit->setMaximumSize(QSize(500, 16777215));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        resolus = new QCheckBox(uiTicket);
        resolus->setObjectName(QStringLiteral("resolus"));
        QFont font;
        font.setFamily(QStringLiteral("Helvetica Neue"));
        font.setPointSize(16);
        resolus->setFont(font);

        horizontalLayout->addWidget(resolus);

        mesTk = new QCheckBox(uiTicket);
        mesTk->setObjectName(QStringLiteral("mesTk"));
        mesTk->setFont(font);

        horizontalLayout->addWidget(mesTk);

        autreTk = new QCheckBox(uiTicket);
        autreTk->setObjectName(QStringLiteral("autreTk"));
        autreTk->setFont(font);

        horizontalLayout->addWidget(autreTk);

        nonAssign = new QCheckBox(uiTicket);
        nonAssign->setObjectName(QStringLiteral("nonAssign"));
        nonAssign->setFont(font);

        horizontalLayout->addWidget(nonAssign);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        tableWidgetTicket = new QTableWidget(uiTicket);
        tableWidgetTicket->setObjectName(QStringLiteral("tableWidgetTicket"));
        tableWidgetTicket->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetTicket->setAlternatingRowColors(true);
        tableWidgetTicket->setSelectionMode(QAbstractItemView::ContiguousSelection);
        tableWidgetTicket->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetTicket->setShowGrid(false);
        tableWidgetTicket->setSortingEnabled(true);

        verticalLayout_2->addWidget(tableWidgetTicket);

        delBox = new QWidget(uiTicket);
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
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

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

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(delBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        addBug = new QPushButton(uiTicket);
        addBug->setObjectName(QStringLiteral("addBug"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/box-plus@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        addBug->setIcon(icon1);
        addBug->setIconSize(QSize(40, 40));
        addBug->setFlat(true);

        horizontalLayout_3->addWidget(addBug);

        delBug = new QPushButton(uiTicket);
        delBug->setObjectName(QStringLiteral("delBug"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/box-minus@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        delBug->setIcon(icon2);
        delBug->setIconSize(QSize(40, 40));
        delBug->setFlat(true);

        horizontalLayout_3->addWidget(delBug);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(uiTicket);

        QMetaObject::connectSlotsByName(uiTicket);
    } // setupUi

    void retranslateUi(QWidget *uiTicket)
    {
        uiTicket->setWindowTitle(QApplication::translate("uiTicket", "Form", 0));
        lineEdit->setPlaceholderText(QApplication::translate("uiTicket", "Recherche ...", 0));
        resolus->setText(QApplication::translate("uiTicket", "R\303\251solus", 0));
        mesTk->setText(QApplication::translate("uiTicket", "Mes ticket", 0));
        autreTk->setText(QApplication::translate("uiTicket", "Autres", 0));
        nonAssign->setText(QApplication::translate("uiTicket", "Non Assign\303\251", 0));
        label->setText(QApplication::translate("uiTicket", "Pour supprimer la t\303\242ches, \303\251crivez SUPPRIMER ci-dessous.", 0));
        confirmDel->setText(QString());
        addBug->setText(QString());
        delBug->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class uiTicket: public Ui_uiTicket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UITICKET_H
