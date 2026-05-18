/********************************************************************************
** Form generated from reading UI file 'workarea.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKAREA_H
#define UI_WORKAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "workareafracbasic.h"

QT_BEGIN_NAMESPACE

class Ui_WorkAreaClass
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *labelcurrent;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidgetcompare;
    WorkAreaFracBasic *tabfrac;
    QWidget *tabresult;
    QWidget *tabcompare;
    QWidget *tabhighfre;

    void setupUi(QWidget *WorkAreaClass)
    {
        if (WorkAreaClass->objectName().isEmpty())
            WorkAreaClass->setObjectName(QString::fromUtf8("WorkAreaClass"));
        WorkAreaClass->resize(1430, 592);
        horizontalLayout = new QHBoxLayout(WorkAreaClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(WorkAreaClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 2);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        labelcurrent = new QLabel(groupBox_2);
        labelcurrent->setObjectName(QString::fromUtf8("labelcurrent"));

        gridLayout->addWidget(labelcurrent, 1, 2, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(WorkAreaClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeWidget = new QTreeWidget(groupBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);


        verticalLayout_2->addWidget(groupBox);

        verticalLayout_2->setStretch(1, 10);

        horizontalLayout->addLayout(verticalLayout_2);

        tabWidgetcompare = new QTabWidget(WorkAreaClass);
        tabWidgetcompare->setObjectName(QString::fromUtf8("tabWidgetcompare"));
        tabfrac = new WorkAreaFracBasic();
        tabfrac->setObjectName(QString::fromUtf8("tabfrac"));
        tabWidgetcompare->addTab(tabfrac, QString());
        tabresult = new QWidget();
        tabresult->setObjectName(QString::fromUtf8("tabresult"));
        tabWidgetcompare->addTab(tabresult, QString());
        tabcompare = new QWidget();
        tabcompare->setObjectName(QString::fromUtf8("tabcompare"));
        tabWidgetcompare->addTab(tabcompare, QString());
        tabhighfre = new QWidget();
        tabhighfre->setObjectName(QString::fromUtf8("tabhighfre"));
        tabWidgetcompare->addTab(tabhighfre, QString());

        horizontalLayout->addWidget(tabWidgetcompare);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        retranslateUi(WorkAreaClass);

        tabWidgetcompare->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WorkAreaClass);
    } // setupUi

    void retranslateUi(QWidget *WorkAreaClass)
    {
        WorkAreaClass->setWindowTitle(QApplication::translate("WorkAreaClass", "WorkArea", nullptr));
        groupBox_2->setTitle(QApplication::translate("WorkAreaClass", "\346\225\260\346\215\256\347\264\242\345\274\225\347\256\241\347\220\206", nullptr));
        label->setText(QApplication::translate("WorkAreaClass", "\346\220\234\347\264\242", nullptr));
        pushButton->setText(QApplication::translate("WorkAreaClass", "\346\270\205\347\251\272\351\200\211\346\213\251", nullptr));
        label_2->setText(QApplication::translate("WorkAreaClass", "\345\275\223\345\211\215\351\200\211\346\213\251", nullptr));
        labelcurrent->setText(QApplication::translate("WorkAreaClass", "TextLabel", nullptr));
        groupBox->setTitle(QApplication::translate("WorkAreaClass", "\345\261\202\347\272\247\346\240\221", nullptr));
        tabWidgetcompare->setTabText(tabWidgetcompare->indexOf(tabfrac), QApplication::translate("WorkAreaClass", "\345\216\213\350\243\202\346\225\260\346\215\256", nullptr));
        tabWidgetcompare->setTabText(tabWidgetcompare->indexOf(tabresult), QApplication::translate("WorkAreaClass", "\350\247\243\351\207\212\347\273\223\346\236\234", nullptr));
        tabWidgetcompare->setTabText(tabWidgetcompare->indexOf(tabcompare), QApplication::translate("WorkAreaClass", "\347\273\223\346\236\234\345\257\271\346\257\224", nullptr));
        tabWidgetcompare->setTabText(tabWidgetcompare->indexOf(tabhighfre), QApplication::translate("WorkAreaClass", "\351\253\230\351\242\221\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkAreaClass: public Ui_WorkAreaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKAREA_H
