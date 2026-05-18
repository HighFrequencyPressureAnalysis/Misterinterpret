/********************************************************************************
** Form generated from reading UI file 'widgetfracper.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETFRACPER_H
#define UI_WIDGETFRACPER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "tableviewperpos.h"
#include "toolbutton.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetFracPerClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxbg;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBoxper;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    ToolButton *toolButtonload;
    QLabel *label_3;
    QComboBox *comboBoxsymbol;
    TableViewPerpos *tableviewperpos;

    void setupUi(QWidget *WidgetFracPerClass)
    {
        if (WidgetFracPerClass->objectName().isEmpty())
            WidgetFracPerClass->setObjectName(QString::fromUtf8("WidgetFracPerClass"));
        WidgetFracPerClass->resize(313, 791);
        verticalLayout = new QVBoxLayout(WidgetFracPerClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(WidgetFracPerClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        doubleSpinBoxbg = new QDoubleSpinBox(WidgetFracPerClass);
        doubleSpinBoxbg->setObjectName(QString::fromUtf8("doubleSpinBoxbg"));
        doubleSpinBoxbg->setMinimum(500.000000000000000);
        doubleSpinBoxbg->setMaximum(10000.000000000000000);
        doubleSpinBoxbg->setValue(6000.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBoxbg);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBoxper = new QGroupBox(WidgetFracPerClass);
        groupBoxper->setObjectName(QString::fromUtf8("groupBoxper"));
        gridLayout = new QGridLayout(groupBoxper);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBoxper);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(groupBoxper);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setValue(5);
        spinBox->setDisplayIntegerBase(15);

        horizontalLayout->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        toolButtonload = new ToolButton(groupBoxper);
        toolButtonload->setObjectName(QString::fromUtf8("toolButtonload"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Waterhammer/Misterinterpret/HighFrequencyPressureAnalysis/res/Icon/loaddata/clipborad.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonload->setIcon(icon);

        horizontalLayout_2->addWidget(toolButtonload);

        label_3 = new QLabel(groupBoxper);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        comboBoxsymbol = new QComboBox(groupBoxper);
        comboBoxsymbol->setObjectName(QString::fromUtf8("comboBoxsymbol"));

        horizontalLayout_2->addWidget(comboBoxsymbol);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBoxper);

        tableviewperpos = new TableViewPerpos(WidgetFracPerClass);
        tableviewperpos->setObjectName(QString::fromUtf8("tableviewperpos"));

        verticalLayout->addWidget(tableviewperpos);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 10);

        retranslateUi(WidgetFracPerClass);

        QMetaObject::connectSlotsByName(WidgetFracPerClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetFracPerClass)
    {
        WidgetFracPerClass->setWindowTitle(QApplication::translate("WidgetFracPerClass", "WidgetFracPer", nullptr));
        label->setText(QApplication::translate("WidgetFracPerClass", "\346\241\245\345\241\236/\344\272\272\345\267\245\344\272\225\345\272\225(m)", nullptr));
        groupBoxper->setTitle(QApplication::translate("WidgetFracPerClass", "\345\260\204\345\255\224\346\225\260\346\215\256", nullptr));
        label_2->setText(QApplication::translate("WidgetFracPerClass", "\345\260\204\345\255\224\347\260\207\346\225\260", nullptr));
        toolButtonload->setText(QApplication::translate("WidgetFracPerClass", "\345\211\252\345\210\207\346\235\277\345\257\274\345\205\245", nullptr));
        label_3->setText(QApplication::translate("WidgetFracPerClass", "\345\210\206\345\211\262\347\254\246\345\217\267\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetFracPerClass: public Ui_WidgetFracPerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETFRACPER_H
