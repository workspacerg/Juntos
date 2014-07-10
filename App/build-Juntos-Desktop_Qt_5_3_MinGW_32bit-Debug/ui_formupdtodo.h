/********************************************************************************
** Form generated from reading UI file 'formupdtodo.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMUPDTODO_H
#define UI_FORMUPDTODO_H

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

class Ui_FormUpdTodo
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
    QLabel *label_8;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_2;
    QDateTimeEdit *dateCrea;
    QDateTimeEdit *dateModif;
    QDateTimeEdit *dateEnd;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextEdit *description;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *save;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *FormUpdTodo)
    {
        if (FormUpdTodo->objectName().isEmpty())
            FormUpdTodo->setObjectName(QStringLiteral("FormUpdTodo"));
        FormUpdTodo->resize(815, 674);
        verticalLayout_4 = new QVBoxLayout(FormUpdTodo);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(FormUpdTodo);
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
        label_2 = new QLabel(FormUpdTodo);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Yi Baiti"));
        font1.setPointSize(18);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        titleTicket = new QLineEdit(FormUpdTodo);
        titleTicket->setObjectName(QStringLiteral("titleTicket"));
        titleTicket->setMinimumSize(QSize(400, 40));
        QFont font2;
        font2.setPointSize(11);
        titleTicket->setFont(font2);

        horizontalLayout_2->addWidget(titleTicket);

        label_10 = new QLabel(FormUpdTodo);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        horizontalLayout_2->addWidget(label_10);

        createComboBox = new QComboBox(FormUpdTodo);
        createComboBox->setObjectName(QStringLiteral("createComboBox"));
        createComboBox->setMinimumSize(QSize(180, 35));
        createComboBox->setFont(font2);

        horizontalLayout_2->addWidget(createComboBox);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(FormUpdTodo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout->addWidget(label_5);

        usrComboBox = new QComboBox(FormUpdTodo);
        usrComboBox->setObjectName(QStringLiteral("usrComboBox"));
        usrComboBox->setMinimumSize(QSize(180, 35));
        usrComboBox->setFont(font2);

        horizontalLayout->addWidget(usrComboBox);

        label_6 = new QLabel(FormUpdTodo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout->addWidget(label_6);

        etatComboBox = new QComboBox(FormUpdTodo);
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
        label_7 = new QLabel(FormUpdTodo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(150, 0));
        label_7->setMaximumSize(QSize(150, 16777215));
        label_7->setFont(font1);

        verticalLayout_3->addWidget(label_7);

        label_8 = new QLabel(FormUpdTodo);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(150, 0));
        label_8->setMaximumSize(QSize(150, 16777215));
        label_8->setFont(font1);

        verticalLayout_3->addWidget(label_8);

        label_9 = new QLabel(FormUpdTodo);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(150, 0));
        label_9->setMaximumSize(QSize(150, 16777215));
        label_9->setFont(font1);

        verticalLayout_3->addWidget(label_9);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        dateCrea = new QDateTimeEdit(FormUpdTodo);
        dateCrea->setObjectName(QStringLiteral("dateCrea"));
        dateCrea->setEnabled(false);
        dateCrea->setMinimumSize(QSize(200, 30));
        dateCrea->setFont(font2);

        verticalLayout_2->addWidget(dateCrea);

        dateModif = new QDateTimeEdit(FormUpdTodo);
        dateModif->setObjectName(QStringLiteral("dateModif"));
        dateModif->setEnabled(false);
        dateModif->setMinimumSize(QSize(200, 30));
        dateModif->setFont(font2);

        verticalLayout_2->addWidget(dateModif);

        dateEnd = new QDateTimeEdit(FormUpdTodo);
        dateEnd->setObjectName(QStringLiteral("dateEnd"));
        dateEnd->setEnabled(true);
        dateEnd->setMinimumSize(QSize(200, 30));
        dateEnd->setFont(font2);

        verticalLayout_2->addWidget(dateEnd);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(FormUpdTodo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        description = new QTextEdit(FormUpdTodo);
        description->setObjectName(QStringLiteral("description"));

        verticalLayout->addWidget(description);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        save = new QPushButton(FormUpdTodo);
        save->setObjectName(QStringLiteral("save"));

        horizontalLayout_4->addWidget(save);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_4);


        retranslateUi(FormUpdTodo);

        QMetaObject::connectSlotsByName(FormUpdTodo);
    } // setupUi

    void retranslateUi(QDialog *FormUpdTodo)
    {
        FormUpdTodo->setWindowTitle(QApplication::translate("FormUpdTodo", "Dialog", 0));
        label->setText(QApplication::translate("FormUpdTodo", "Details T\303\242ches", 0));
        label_2->setText(QApplication::translate("FormUpdTodo", "Titre :", 0));
        label_10->setText(QApplication::translate("FormUpdTodo", "Cr\303\251e par :", 0));
        label_5->setText(QApplication::translate("FormUpdTodo", "Assign\303\251 \303\240 :", 0));
        label_6->setText(QApplication::translate("FormUpdTodo", "Avancement :", 0));
        label_7->setText(QApplication::translate("FormUpdTodo", "Cr\303\251ation", 0));
        label_8->setText(QApplication::translate("FormUpdTodo", "Modification", 0));
        label_9->setText(QApplication::translate("FormUpdTodo", "Date de fin", 0));
        label_3->setText(QApplication::translate("FormUpdTodo", "Description", 0));
        save->setText(QApplication::translate("FormUpdTodo", "Sauvegarder", 0));
    } // retranslateUi

};

namespace Ui {
    class FormUpdTodo: public Ui_FormUpdTodo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMUPDTODO_H
