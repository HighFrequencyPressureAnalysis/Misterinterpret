/********************************************************************************
** Form generated from reading UI file 'dialogfracper.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFRACPER_H
#define UI_DIALOGFRACPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "widgetfracper.h"

QT_BEGIN_NAMESPACE

class Ui_DialogFracPerClass
{
public:
    QVBoxLayout *verticalLayout;
    WidgetFracPer *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonsure;
    QPushButton *pushButtonclose;

    void setupUi(QDialog *DialogFracPerClass)
    {
        if (DialogFracPerClass->objectName().isEmpty())
            DialogFracPerClass->setObjectName(QString::fromUtf8("DialogFracPerClass"));
        DialogFracPerClass->resize(306, 400);
        verticalLayout = new QVBoxLayout(DialogFracPerClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new WidgetFracPer(DialogFracPerClass);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonsure = new QPushButton(DialogFracPerClass);
        pushButtonsure->setObjectName(QString::fromUtf8("pushButtonsure"));

        horizontalLayout->addWidget(pushButtonsure);

        pushButtonclose = new QPushButton(DialogFracPerClass);
        pushButtonclose->setObjectName(QString::fromUtf8("pushButtonclose"));

        horizontalLayout->addWidget(pushButtonclose);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        retranslateUi(DialogFracPerClass);

        QMetaObject::connectSlotsByName(DialogFracPerClass);
    } // setupUi

    void retranslateUi(QDialog *DialogFracPerClass)
    {
        DialogFracPerClass->setWindowTitle(QApplication::translate("DialogFracPerClass", "DialogFracPer", nullptr));
        pushButtonsure->setText(QApplication::translate("DialogFracPerClass", "\347\241\256\350\256\244", nullptr));
        pushButtonclose->setText(QApplication::translate("DialogFracPerClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFracPerClass: public Ui_DialogFracPerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFRACPER_H
