/********************************************************************************
** Form generated from reading UI file 'dialogfracbasic.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFRACBASIC_H
#define UI_DIALOGFRACBASIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "widgetbasicfrac.h"

QT_BEGIN_NAMESPACE

class Ui_DialogFracBasicClass
{
public:
    QVBoxLayout *verticalLayout;
    WidgetBasicFrac *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonsure;
    QPushButton *pushButtonclose;

    void setupUi(QDialog *DialogFracBasicClass)
    {
        if (DialogFracBasicClass->objectName().isEmpty())
            DialogFracBasicClass->setObjectName(QString::fromUtf8("DialogFracBasicClass"));
        DialogFracBasicClass->resize(261, 560);
        verticalLayout = new QVBoxLayout(DialogFracBasicClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new WidgetBasicFrac(DialogFracBasicClass);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonsure = new QPushButton(DialogFracBasicClass);
        pushButtonsure->setObjectName(QString::fromUtf8("pushButtonsure"));

        horizontalLayout->addWidget(pushButtonsure);

        pushButtonclose = new QPushButton(DialogFracBasicClass);
        pushButtonclose->setObjectName(QString::fromUtf8("pushButtonclose"));

        horizontalLayout->addWidget(pushButtonclose);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        retranslateUi(DialogFracBasicClass);

        QMetaObject::connectSlotsByName(DialogFracBasicClass);
    } // setupUi

    void retranslateUi(QDialog *DialogFracBasicClass)
    {
        DialogFracBasicClass->setWindowTitle(QApplication::translate("DialogFracBasicClass", "DialogFracBasic", nullptr));
        pushButtonsure->setText(QApplication::translate("DialogFracBasicClass", "\347\241\256\350\256\244", nullptr));
        pushButtonclose->setText(QApplication::translate("DialogFracBasicClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFracBasicClass: public Ui_DialogFracBasicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFRACBASIC_H
