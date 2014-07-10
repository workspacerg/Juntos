/********************************************************************************
** Form generated from reading UI file 'uiacceuil.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIACCEUIL_H
#define UI_UIACCEUIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uiAcceuil
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *updTable;
    QPushButton *addPeople;
    QPushButton *addProject;
    QPushButton *PBDelProject;
    QWidget *BoiteDeCreation;
    QVBoxLayout *verticalLayout_2;
    QLabel *LNom;
    QLineEdit *LENom;
    QLabel *LDescr;
    QTextEdit *TEDescr;
    QPushButton *PBCreate;
    QWidget *delBox;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *delLine;
    QPushButton *confirmDel;
    QSpacerItem *horizontalSpacer_8;
    QTableWidget *tableWidgetPtoject;

    void setupUi(QWidget *uiAcceuil)
    {
        if (uiAcceuil->objectName().isEmpty())
            uiAcceuil->setObjectName(QStringLiteral("uiAcceuil"));
        uiAcceuil->resize(900, 822);
        verticalLayout_3 = new QVBoxLayout(uiAcceuil);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget = new QWidget(uiAcceuil);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Helvetica Neue"));
        font.setPointSize(17);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        updTable = new QPushButton(widget);
        updTable->setObjectName(QStringLiteral("updTable"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/available_updates-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        updTable->setIcon(icon);
        updTable->setIconSize(QSize(25, 25));
        updTable->setFlat(true);

        horizontalLayout->addWidget(updTable);

        addPeople = new QPushButton(widget);
        addPeople->setObjectName(QStringLiteral("addPeople"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/add_user-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        addPeople->setIcon(icon1);
        addPeople->setIconSize(QSize(25, 25));
        addPeople->setFlat(true);

        horizontalLayout->addWidget(addPeople);

        addProject = new QPushButton(widget);
        addProject->setObjectName(QStringLiteral("addProject"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/add_database-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        addProject->setIcon(icon2);
        addProject->setIconSize(QSize(25, 25));
        addProject->setFlat(true);

        horizontalLayout->addWidget(addProject);

        PBDelProject = new QPushButton(widget);
        PBDelProject->setObjectName(QStringLiteral("PBDelProject"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/delete_database-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        PBDelProject->setIcon(icon3);
        PBDelProject->setIconSize(QSize(25, 25));
        PBDelProject->setFlat(true);

        horizontalLayout->addWidget(PBDelProject);


        verticalLayout_3->addWidget(widget);

        BoiteDeCreation = new QWidget(uiAcceuil);
        BoiteDeCreation->setObjectName(QStringLiteral("BoiteDeCreation"));
        BoiteDeCreation->setMinimumSize(QSize(0, 300));
        BoiteDeCreation->setMaximumSize(QSize(16777215, 16777215));
        BoiteDeCreation->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(BoiteDeCreation);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        LNom = new QLabel(BoiteDeCreation);
        LNom->setObjectName(QStringLiteral("LNom"));
        QFont font1;
        font1.setFamily(QStringLiteral("Helvetica Neue"));
        font1.setPointSize(15);
        LNom->setFont(font1);

        verticalLayout_2->addWidget(LNom);

        LENom = new QLineEdit(BoiteDeCreation);
        LENom->setObjectName(QStringLiteral("LENom"));
        LENom->setMinimumSize(QSize(0, 35));
        LENom->setMaximumSize(QSize(16777215, 45));

        verticalLayout_2->addWidget(LENom);

        LDescr = new QLabel(BoiteDeCreation);
        LDescr->setObjectName(QStringLiteral("LDescr"));
        LDescr->setFont(font1);

        verticalLayout_2->addWidget(LDescr);

        TEDescr = new QTextEdit(BoiteDeCreation);
        TEDescr->setObjectName(QStringLiteral("TEDescr"));
        TEDescr->setMinimumSize(QSize(0, 100));

        verticalLayout_2->addWidget(TEDescr);

        PBCreate = new QPushButton(BoiteDeCreation);
        PBCreate->setObjectName(QStringLiteral("PBCreate"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/plus-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        PBCreate->setIcon(icon4);
        PBCreate->setIconSize(QSize(25, 25));
        PBCreate->setFlat(true);

        verticalLayout_2->addWidget(PBCreate);


        verticalLayout_3->addWidget(BoiteDeCreation);

        delBox = new QWidget(uiAcceuil);
        delBox->setObjectName(QStringLiteral("delBox"));
        verticalLayout = new QVBoxLayout(delBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(delBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        delLine = new QLineEdit(delBox);
        delLine->setObjectName(QStringLiteral("delLine"));
        delLine->setMinimumSize(QSize(300, 60));
        delLine->setMaximumSize(QSize(300, 60));
        QFont font3;
        font3.setPointSize(13);
        delLine->setFont(font3);

        horizontalLayout_4->addWidget(delLine);

        confirmDel = new QPushButton(delBox);
        confirmDel->setObjectName(QStringLiteral("confirmDel"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/dnd-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        confirmDel->setIcon(icon5);
        confirmDel->setIconSize(QSize(40, 40));
        confirmDel->setFlat(true);

        horizontalLayout_4->addWidget(confirmDel);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(delBox);

        tableWidgetPtoject = new QTableWidget(uiAcceuil);
        tableWidgetPtoject->setObjectName(QStringLiteral("tableWidgetPtoject"));
        tableWidgetPtoject->setEnabled(true);
        tableWidgetPtoject->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetPtoject->setAlternatingRowColors(true);
        tableWidgetPtoject->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetPtoject->setSortingEnabled(true);

        verticalLayout_3->addWidget(tableWidgetPtoject);


        retranslateUi(uiAcceuil);

        QMetaObject::connectSlotsByName(uiAcceuil);
    } // setupUi

    void retranslateUi(QWidget *uiAcceuil)
    {
        uiAcceuil->setWindowTitle(QApplication::translate("uiAcceuil", "Form", 0));
        label->setText(QApplication::translate("uiAcceuil", "Sur quel projet travaillez vous ? : ", 0));
        updTable->setText(QString());
        addPeople->setText(QString());
        addProject->setText(QString());
        PBDelProject->setText(QString());
        LNom->setText(QApplication::translate("uiAcceuil", "Nom Projet : ", 0));
        LENom->setText(QString());
        LENom->setPlaceholderText(QApplication::translate("uiAcceuil", "Nom du nouveau projet", 0));
        LDescr->setText(QApplication::translate("uiAcceuil", "Description : ", 0));
        PBCreate->setText(QString());
        label_2->setText(QApplication::translate("uiAcceuil", "Pour supprimer la t\303\242ches, \303\251crivez SUPPRIMER ci-dessous.", 0));
        confirmDel->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        tableWidgetPtoject->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        tableWidgetPtoject->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
    } // retranslateUi

};

namespace Ui {
    class uiAcceuil: public Ui_uiAcceuil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIACCEUIL_H
