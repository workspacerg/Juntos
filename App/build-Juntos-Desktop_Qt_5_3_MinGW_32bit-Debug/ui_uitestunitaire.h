/********************************************************************************
** Form generated from reading UI file 'uitestunitaire.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UITESTUNITAIRE_H
#define UI_UITESTUNITAIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UiTestUnitaire
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *ok;
    QCheckBox *failed;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidgetTest;
    QWidget *updBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *TitreLine_upd;
    QLineEdit *pOutLine_upd;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *pInline_upd;
    QLabel *label_7;
    QCheckBox *valid;
    QSpacerItem *verticalSpacer;
    QPlainTextEdit *DescrTPL_upd;
    QPushButton *save_test_upd;
    QWidget *addBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *TitreLine;
    QLabel *label_3;
    QLineEdit *pInline;
    QLabel *label_4;
    QLineEdit *pOutLine;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *save_test;
    QPlainTextEdit *DescrTPL;
    QWidget *delBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *delLine;
    QPushButton *confirmDel;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addTest;
    QPushButton *DelTest;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *UiTestUnitaire)
    {
        if (UiTestUnitaire->objectName().isEmpty())
            UiTestUnitaire->setObjectName(QStringLiteral("UiTestUnitaire"));
        UiTestUnitaire->resize(1125, 1070);
        verticalLayout_6 = new QVBoxLayout(UiTestUnitaire);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        lineEdit = new QLineEdit(UiTestUnitaire);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(500, 35));
        lineEdit->setMaximumSize(QSize(500, 16777215));

        horizontalLayout_7->addWidget(lineEdit);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        ok = new QCheckBox(UiTestUnitaire);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setMinimumSize(QSize(25, 25));
        QFont font;
        font.setPointSize(13);
        ok->setFont(font);

        horizontalLayout->addWidget(ok);

        failed = new QCheckBox(UiTestUnitaire);
        failed->setObjectName(QStringLiteral("failed"));
        failed->setMinimumSize(QSize(25, 25));
        failed->setFont(font);

        horizontalLayout->addWidget(failed);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout);

        tableWidgetTest = new QTableWidget(UiTestUnitaire);
        tableWidgetTest->setObjectName(QStringLiteral("tableWidgetTest"));
        tableWidgetTest->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetTest->setAlternatingRowColors(true);
        tableWidgetTest->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetTest->setShowGrid(false);
        tableWidgetTest->setSortingEnabled(true);

        verticalLayout_6->addWidget(tableWidgetTest);

        updBox = new QWidget(UiTestUnitaire);
        updBox->setObjectName(QStringLiteral("updBox"));
        verticalLayout_4 = new QVBoxLayout(updBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(8);
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        TitreLine_upd = new QLineEdit(updBox);
        TitreLine_upd->setObjectName(QStringLiteral("TitreLine_upd"));
        TitreLine_upd->setMinimumSize(QSize(150, 30));
        TitreLine_upd->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(TitreLine_upd, 1, 1, 1, 1);

        pOutLine_upd = new QLineEdit(updBox);
        pOutLine_upd->setObjectName(QStringLiteral("pOutLine_upd"));
        pOutLine_upd->setMinimumSize(QSize(150, 30));
        pOutLine_upd->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(pOutLine_upd, 3, 1, 1, 1);

        label_5 = new QLabel(updBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(170, 30));
        label_5->setMaximumSize(QSize(170, 30));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(updBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(170, 30));
        label_6->setMaximumSize(QSize(170, 30));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        pInline_upd = new QLineEdit(updBox);
        pInline_upd->setObjectName(QStringLiteral("pInline_upd"));
        pInline_upd->setMinimumSize(QSize(150, 30));
        pInline_upd->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(pInline_upd, 2, 1, 1, 1);

        label_7 = new QLabel(updBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(170, 30));
        label_7->setMaximumSize(QSize(170, 30));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        valid = new QCheckBox(updBox);
        valid->setObjectName(QStringLiteral("valid"));
        QFont font1;
        font1.setPointSize(15);
        valid->setFont(font1);

        gridLayout->addWidget(valid, 4, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_3);

        DescrTPL_upd = new QPlainTextEdit(updBox);
        DescrTPL_upd->setObjectName(QStringLiteral("DescrTPL_upd"));
        DescrTPL_upd->setMinimumSize(QSize(0, 200));
        DescrTPL_upd->setMaximumSize(QSize(16777215, 1000));

        horizontalLayout_6->addWidget(DescrTPL_upd);


        verticalLayout_4->addLayout(horizontalLayout_6);

        save_test_upd = new QPushButton(updBox);
        save_test_upd->setObjectName(QStringLiteral("save_test_upd"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/available_updates-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_test_upd->setIcon(icon);
        save_test_upd->setIconSize(QSize(25, 25));
        save_test_upd->setAutoDefault(false);
        save_test_upd->setFlat(true);

        verticalLayout_4->addWidget(save_test_upd);


        verticalLayout_6->addWidget(updBox);

        addBox = new QWidget(UiTestUnitaire);
        addBox->setObjectName(QStringLiteral("addBox"));
        verticalLayout_5 = new QVBoxLayout(addBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(addBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(170, 30));
        label_2->setMaximumSize(QSize(170, 30));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        TitreLine = new QLineEdit(addBox);
        TitreLine->setObjectName(QStringLiteral("TitreLine"));
        TitreLine->setMinimumSize(QSize(150, 30));
        TitreLine->setMaximumSize(QSize(150, 30));

        gridLayout_2->addWidget(TitreLine, 0, 1, 1, 1);

        label_3 = new QLabel(addBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(170, 30));
        label_3->setMaximumSize(QSize(170, 30));
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        pInline = new QLineEdit(addBox);
        pInline->setObjectName(QStringLiteral("pInline"));
        pInline->setMinimumSize(QSize(150, 30));
        pInline->setMaximumSize(QSize(150, 30));

        gridLayout_2->addWidget(pInline, 1, 1, 1, 1);

        label_4 = new QLabel(addBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(170, 30));
        label_4->setMaximumSize(QSize(170, 30));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        pOutLine = new QLineEdit(addBox);
        pOutLine->setObjectName(QStringLiteral("pOutLine"));
        pOutLine->setMinimumSize(QSize(150, 30));
        pOutLine->setMaximumSize(QSize(150, 30));

        gridLayout_2->addWidget(pOutLine, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        save_test = new QPushButton(addBox);
        save_test->setObjectName(QStringLiteral("save_test"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/add_database-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_test->setIcon(icon1);
        save_test->setIconSize(QSize(25, 25));
        save_test->setAutoDefault(false);
        save_test->setFlat(true);

        horizontalLayout_4->addWidget(save_test);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_2);

        DescrTPL = new QPlainTextEdit(addBox);
        DescrTPL->setObjectName(QStringLiteral("DescrTPL"));
        DescrTPL->setMinimumSize(QSize(0, 250));
        DescrTPL->setMaximumSize(QSize(16777215, 1000));

        horizontalLayout_5->addWidget(DescrTPL);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_6->addWidget(addBox);

        delBox = new QWidget(UiTestUnitaire);
        delBox->setObjectName(QStringLiteral("delBox"));
        verticalLayout = new QVBoxLayout(delBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(delBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        delLine = new QLineEdit(delBox);
        delLine->setObjectName(QStringLiteral("delLine"));
        delLine->setMinimumSize(QSize(300, 60));
        delLine->setMaximumSize(QSize(300, 60));
        delLine->setFont(font);

        horizontalLayout_3->addWidget(delLine);

        confirmDel = new QPushButton(delBox);
        confirmDel->setObjectName(QStringLiteral("confirmDel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/dnd-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        confirmDel->setIcon(icon2);
        confirmDel->setIconSize(QSize(40, 40));
        confirmDel->setFlat(true);

        horizontalLayout_3->addWidget(confirmDel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_6->addWidget(delBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        addTest = new QPushButton(UiTestUnitaire);
        addTest->setObjectName(QStringLiteral("addTest"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/box-plus@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        addTest->setIcon(icon3);
        addTest->setIconSize(QSize(40, 40));
        addTest->setFlat(true);

        horizontalLayout_2->addWidget(addTest);

        DelTest = new QPushButton(UiTestUnitaire);
        DelTest->setObjectName(QStringLiteral("DelTest"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/MenuInterface/Ressouces/box-minus@2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        DelTest->setIcon(icon4);
        DelTest->setIconSize(QSize(40, 40));
        DelTest->setFlat(true);

        horizontalLayout_2->addWidget(DelTest);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_6->addLayout(horizontalLayout_2);


        retranslateUi(UiTestUnitaire);

        QMetaObject::connectSlotsByName(UiTestUnitaire);
    } // setupUi

    void retranslateUi(QDialog *UiTestUnitaire)
    {
        UiTestUnitaire->setWindowTitle(QApplication::translate("UiTestUnitaire", "Dialog", 0));
        lineEdit->setPlaceholderText(QApplication::translate("UiTestUnitaire", "Recherche ...", 0));
        ok->setText(QApplication::translate("UiTestUnitaire", "Passed", 0));
        failed->setText(QApplication::translate("UiTestUnitaire", "Failed", 0));
        label_5->setText(QApplication::translate("UiTestUnitaire", "Titre : ", 0));
        label_6->setText(QApplication::translate("UiTestUnitaire", "Param\303\250tre d'entr\303\251 :", 0));
        label_7->setText(QApplication::translate("UiTestUnitaire", "Param\303\250tre de sortie :", 0));
        valid->setText(QApplication::translate("UiTestUnitaire", "Valider", 0));
        save_test_upd->setText(QString());
        label_2->setText(QApplication::translate("UiTestUnitaire", "Titre : ", 0));
        label_3->setText(QApplication::translate("UiTestUnitaire", "Param\303\250tre d'entr\303\251 :", 0));
        label_4->setText(QApplication::translate("UiTestUnitaire", "Param\303\250tre de sortie :", 0));
        save_test->setText(QString());
        label->setText(QApplication::translate("UiTestUnitaire", "Pour supprimer la t\303\242ches, \303\251crivez SUPPRIMER ci-dessous.", 0));
        confirmDel->setText(QString());
        addTest->setText(QString());
        DelTest->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UiTestUnitaire: public Ui_UiTestUnitaire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UITESTUNITAIRE_H
