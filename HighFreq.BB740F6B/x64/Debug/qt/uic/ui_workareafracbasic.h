/********************************************************************************
** Form generated from reading UI file 'workareafracbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKAREAFRACBASIC_H
#define UI_WORKAREAFRACBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plotopera.h"
#include "plotwh.h"
#include "widgetbasicfrac.h"
#include "widgetfracper.h"

QT_BEGIN_NAMESPACE

class Ui_WorkAreaFracBasicClass
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    WidgetBasicFrac *widgetfracbasic;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    WidgetFracPer *widgetper;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    PlotOpera *plotopera;
    PlotWh *plotwh;

    void setupUi(QWidget *WorkAreaFracBasicClass)
    {
        if (WorkAreaFracBasicClass->objectName().isEmpty())
            WorkAreaFracBasicClass->setObjectName(QString::fromUtf8("WorkAreaFracBasicClass"));
        WorkAreaFracBasicClass->resize(855, 641);
        horizontalLayout = new QHBoxLayout(WorkAreaFracBasicClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(WorkAreaFracBasicClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widgetfracbasic = new WidgetBasicFrac(groupBox);
        widgetfracbasic->setObjectName(QString::fromUtf8("widgetfracbasic"));

        verticalLayout->addWidget(widgetfracbasic);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(WorkAreaFracBasicClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widgetper = new WidgetFracPer(groupBox_2);
        widgetper->setObjectName(QString::fromUtf8("widgetper"));

        verticalLayout_2->addWidget(widgetper);


        verticalLayout_3->addWidget(groupBox_2);


        horizontalLayout->addLayout(verticalLayout_3);

        groupBox_3 = new QGroupBox(WorkAreaFracBasicClass);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        plotopera = new PlotOpera(groupBox_3);
        plotopera->setObjectName(QString::fromUtf8("plotopera"));

        verticalLayout_4->addWidget(plotopera);

        plotwh = new PlotWh(groupBox_3);
        plotwh->setObjectName(QString::fromUtf8("plotwh"));

        verticalLayout_4->addWidget(plotwh);

        verticalLayout_4->setStretch(0, 3);
        verticalLayout_4->setStretch(1, 2);

        horizontalLayout->addWidget(groupBox_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 10);

        retranslateUi(WorkAreaFracBasicClass);

        QMetaObject::connectSlotsByName(WorkAreaFracBasicClass);
    } // setupUi

    void retranslateUi(QWidget *WorkAreaFracBasicClass)
    {
        WorkAreaFracBasicClass->setWindowTitle(QApplication::translate("WorkAreaFracBasicClass", "WorkAreaFracBasic", nullptr));
        groupBox->setTitle(QApplication::translate("WorkAreaFracBasicClass", "\345\216\213\350\243\202\345\237\272\347\241\200\344\277\241\346\201\257", nullptr));
        groupBox_2->setTitle(QApplication::translate("WorkAreaFracBasicClass", "\345\260\204\345\255\224\344\277\241\346\201\257", nullptr));
        groupBox_3->setTitle(QApplication::translate("WorkAreaFracBasicClass", "\346\226\275\345\267\245\345\217\212\345\201\234\346\263\265\346\233\262\347\272\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkAreaFracBasicClass: public Ui_WorkAreaFracBasicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKAREAFRACBASIC_H
