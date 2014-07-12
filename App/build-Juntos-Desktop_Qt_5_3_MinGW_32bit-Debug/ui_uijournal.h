/********************************************************************************
** Form generated from reading UI file 'uijournal.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIJOURNAL_H
#define UI_UIJOURNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_uiJournal
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QDialog *uiJournal)
    {
        if (uiJournal->objectName().isEmpty())
            uiJournal->setObjectName(QStringLiteral("uiJournal"));
        uiJournal->resize(915, 684);
        verticalLayout = new QVBoxLayout(uiJournal);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(uiJournal);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setFamily(QStringLiteral("SketchFlow Print"));
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(uiJournal);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(uiJournal);

        QMetaObject::connectSlotsByName(uiJournal);
    } // setupUi

    void retranslateUi(QDialog *uiJournal)
    {
        uiJournal->setWindowTitle(QApplication::translate("uiJournal", "Journal", 0));
        label->setText(QApplication::translate("uiJournal", "Journal des \303\251v\303\250nements", 0));
    } // retranslateUi

};

namespace Ui {
    class uiJournal: public Ui_uiJournal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIJOURNAL_H
