/********************************************************************************
** Form generated from reading UI file 'dialogwaiting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGWAITING_H
#define UI_DIALOGWAITING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_DialogWaitingClass
{
public:
    QGridLayout *gridLayout;
    QLabel *labeltime;
    QLabel *labelinfor;
    QLabel *labeltimevalue;
    QLabel *labelpic;
    QProgressBar *progressBar;
    QLabel *labelprogress;

    void setupUi(QDialog *DialogWaitingClass)
    {
        if (DialogWaitingClass->objectName().isEmpty())
            DialogWaitingClass->setObjectName(QString::fromUtf8("DialogWaitingClass"));
        DialogWaitingClass->resize(600, 281);
        gridLayout = new QGridLayout(DialogWaitingClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labeltime = new QLabel(DialogWaitingClass);
        labeltime->setObjectName(QString::fromUtf8("labeltime"));

        gridLayout->addWidget(labeltime, 1, 0, 1, 1);

        labelinfor = new QLabel(DialogWaitingClass);
        labelinfor->setObjectName(QString::fromUtf8("labelinfor"));

        gridLayout->addWidget(labelinfor, 0, 1, 1, 1);

        labeltimevalue = new QLabel(DialogWaitingClass);
        labeltimevalue->setObjectName(QString::fromUtf8("labeltimevalue"));

        gridLayout->addWidget(labeltimevalue, 1, 1, 1, 1);

        labelpic = new QLabel(DialogWaitingClass);
        labelpic->setObjectName(QString::fromUtf8("labelpic"));

        gridLayout->addWidget(labelpic, 0, 0, 1, 1);

        progressBar = new QProgressBar(DialogWaitingClass);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 2, 1, 1, 1);

        labelprogress = new QLabel(DialogWaitingClass);
        labelprogress->setObjectName(QString::fromUtf8("labelprogress"));

        gridLayout->addWidget(labelprogress, 2, 0, 1, 1);


        retranslateUi(DialogWaitingClass);

        QMetaObject::connectSlotsByName(DialogWaitingClass);
    } // setupUi

    void retranslateUi(QDialog *DialogWaitingClass)
    {
        DialogWaitingClass->setWindowTitle(QApplication::translate("DialogWaitingClass", "DialogWaiting", nullptr));
        labeltime->setText(QApplication::translate("DialogWaitingClass", "\346\227\266\351\227\264(s)\357\274\232", nullptr));
        labelinfor->setText(QApplication::translate("DialogWaitingClass", "0", nullptr));
        labeltimevalue->setText(QApplication::translate("DialogWaitingClass", "0", nullptr));
        labelpic->setText(QApplication::translate("DialogWaitingClass", "TextLabel", nullptr));
        labelprogress->setText(QApplication::translate("DialogWaitingClass", "\350\277\233\345\272\246\346\230\276\347\244\272\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogWaitingClass: public Ui_DialogWaitingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGWAITING_H
