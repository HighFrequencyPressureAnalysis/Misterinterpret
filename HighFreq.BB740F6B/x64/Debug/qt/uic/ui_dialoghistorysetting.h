/********************************************************************************
** Form generated from reading UI file 'dialoghistorysetting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGHISTORYSETTING_H
#define UI_DIALOGHISTORYSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogHistorySetting
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QComboBox *comboBoxtype;
    QComboBox *comboBoxunit;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonsure;

    void setupUi(QDialog *DialogHistorySetting)
    {
        if (DialogHistorySetting->objectName().isEmpty())
            DialogHistorySetting->setObjectName(QString::fromUtf8("DialogHistorySetting"));
        DialogHistorySetting->resize(289, 133);
        verticalLayout = new QVBoxLayout(DialogHistorySetting);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBoxtype = new QComboBox(DialogHistorySetting);
        comboBoxtype->setObjectName(QString::fromUtf8("comboBoxtype"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        comboBoxtype->setFont(font);

        gridLayout->addWidget(comboBoxtype, 0, 1, 1, 3);

        comboBoxunit = new QComboBox(DialogHistorySetting);
        comboBoxunit->setObjectName(QString::fromUtf8("comboBoxunit"));
        comboBoxunit->setFont(font);

        gridLayout->addWidget(comboBoxunit, 1, 1, 1, 3);

        label = new QLabel(DialogHistorySetting);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(DialogHistorySetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 2);

        pushButtonsure = new QPushButton(DialogHistorySetting);
        pushButtonsure->setObjectName(QString::fromUtf8("pushButtonsure"));

        gridLayout->addWidget(pushButtonsure, 2, 2, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(DialogHistorySetting);

        QMetaObject::connectSlotsByName(DialogHistorySetting);
    } // setupUi

    void retranslateUi(QDialog *DialogHistorySetting)
    {
        DialogHistorySetting->setWindowTitle(QApplication::translate("DialogHistorySetting", "DialogHistorySetting", nullptr));
        label->setText(QApplication::translate("DialogHistorySetting", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        label_2->setText(QApplication::translate("DialogHistorySetting", "\346\225\260\346\215\256\345\215\225\344\275\215\357\274\232", nullptr));
        pushButtonsure->setText(QApplication::translate("DialogHistorySetting", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogHistorySetting: public Ui_DialogHistorySetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGHISTORYSETTING_H
