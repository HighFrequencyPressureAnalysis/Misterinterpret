/********************************************************************************
** Form generated from reading UI file 'dialogparallel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPARALLEL_H
#define UI_DIALOGPARALLEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogParallelClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelmovie;
    QLabel *labeltext;

    void setupUi(QDialog *DialogParallelClass)
    {
        if (DialogParallelClass->objectName().isEmpty())
            DialogParallelClass->setObjectName(QString::fromUtf8("DialogParallelClass"));
        DialogParallelClass->resize(435, 116);
        verticalLayout = new QVBoxLayout(DialogParallelClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelmovie = new QLabel(DialogParallelClass);
        labelmovie->setObjectName(QString::fromUtf8("labelmovie"));

        horizontalLayout->addWidget(labelmovie);

        labeltext = new QLabel(DialogParallelClass);
        labeltext->setObjectName(QString::fromUtf8("labeltext"));

        horizontalLayout->addWidget(labeltext);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogParallelClass);

        QMetaObject::connectSlotsByName(DialogParallelClass);
    } // setupUi

    void retranslateUi(QDialog *DialogParallelClass)
    {
        DialogParallelClass->setWindowTitle(QApplication::translate("DialogParallelClass", "DialogParallel", nullptr));
        labelmovie->setText(QApplication::translate("DialogParallelClass", "TextLabel", nullptr));
        labeltext->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogParallelClass: public Ui_DialogParallelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPARALLEL_H
