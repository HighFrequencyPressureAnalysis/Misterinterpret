/********************************************************************************
** Form generated from reading UI file 'dialogloaddata.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLOADDATA_H
#define UI_DIALOGLOADDATA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "tableviewloadhistory.h"

QT_BEGIN_NAMESPACE

class Ui_DialogLoadDataClass
{
public:
    QVBoxLayout *verticalLayout_13;
    QLabel *labelreminder;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_3;
    QLineEdit *lineEditindex;
    QGroupBox *groupBoxfre;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QComboBox *comboBoxfre;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_8;
    QStackedWidget *stackedWidgetsetting;
    QWidget *pagenormal;
    QVBoxLayout *verticalLayout_15;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtontxt;
    QPushButton *pushButtonexcel;
    QPushButton *pushButtonclipboard;
    QPushButton *pushButtontable;
    QGroupBox *groupBoxexcel;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QComboBox *comboBoxsheet;
    QLabel *label_6;
    QGroupBox *groupBoxtable;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBoxrow;
    QSpinBox *spinBoxcolumn;
    QLabel *label;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QStackedWidget *stackedWidgetshow;
    QWidget *pagetable;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_9;
    QLabel *labelfilepath;
    QLabel *label_7;
    TableViewLoadHistory *tableView;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonnext;
    QPushButton *pushButtonclose;

    void setupUi(QDialog *DialogLoadDataClass)
    {
        if (DialogLoadDataClass->objectName().isEmpty())
            DialogLoadDataClass->setObjectName(QString::fromUtf8("DialogLoadDataClass"));
        DialogLoadDataClass->resize(1238, 895);
        verticalLayout_13 = new QVBoxLayout(DialogLoadDataClass);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        labelreminder = new QLabel(DialogLoadDataClass);
        labelreminder->setObjectName(QString::fromUtf8("labelreminder"));
        labelreminder->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));

        verticalLayout_13->addWidget(labelreminder);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupBox_5 = new QGroupBox(DialogLoadDataClass);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(groupBox_4);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        gridLayout_2->addWidget(dateTimeEdit, 0, 1, 1, 2);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 2);

        lineEditindex = new QLineEdit(groupBox_4);
        lineEditindex->setObjectName(QString::fromUtf8("lineEditindex"));

        gridLayout_2->addWidget(lineEditindex, 1, 2, 1, 1);


        horizontalLayout_2->addWidget(groupBox_4);


        verticalLayout_10->addWidget(groupBox_5);

        groupBoxfre = new QGroupBox(DialogLoadDataClass);
        groupBoxfre->setObjectName(QString::fromUtf8("groupBoxfre"));
        horizontalLayout_5 = new QHBoxLayout(groupBoxfre);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(groupBoxfre);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        comboBoxfre = new QComboBox(groupBoxfre);
        comboBoxfre->setObjectName(QString::fromUtf8("comboBoxfre"));

        horizontalLayout_5->addWidget(comboBoxfre);


        verticalLayout_10->addWidget(groupBoxfre);

        groupBox_6 = new QGroupBox(DialogLoadDataClass);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_8 = new QVBoxLayout(groupBox_6);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        stackedWidgetsetting = new QStackedWidget(groupBox_6);
        stackedWidgetsetting->setObjectName(QString::fromUtf8("stackedWidgetsetting"));
        pagenormal = new QWidget();
        pagenormal->setObjectName(QString::fromUtf8("pagenormal"));
        verticalLayout_15 = new QVBoxLayout(pagenormal);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox_3 = new QGroupBox(pagenormal);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtontxt = new QPushButton(groupBox_3);
        pushButtontxt->setObjectName(QString::fromUtf8("pushButtontxt"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/Icon/txt.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtontxt->setIcon(icon);
        pushButtontxt->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(pushButtontxt);

        pushButtonexcel = new QPushButton(groupBox_3);
        pushButtonexcel->setObjectName(QString::fromUtf8("pushButtonexcel"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("res/Icon/excel.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonexcel->setIcon(icon1);
        pushButtonexcel->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(pushButtonexcel);

        pushButtonclipboard = new QPushButton(groupBox_3);
        pushButtonclipboard->setObjectName(QString::fromUtf8("pushButtonclipboard"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("res/Icon/clipborad.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonclipboard->setIcon(icon2);
        pushButtonclipboard->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(pushButtonclipboard);

        pushButtontable = new QPushButton(groupBox_3);
        pushButtontable->setObjectName(QString::fromUtf8("pushButtontable"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("res/Icon/table.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtontable->setIcon(icon3);
        pushButtontable->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(pushButtontable);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_7->addWidget(groupBox_3);

        groupBoxexcel = new QGroupBox(pagenormal);
        groupBoxexcel->setObjectName(QString::fromUtf8("groupBoxexcel"));
        verticalLayout_5 = new QVBoxLayout(groupBoxexcel);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(groupBoxexcel);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        comboBoxsheet = new QComboBox(groupBoxexcel);
        comboBoxsheet->setObjectName(QString::fromUtf8("comboBoxsheet"));

        verticalLayout_5->addWidget(comboBoxsheet);

        label_6 = new QLabel(groupBoxexcel);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_5->addWidget(label_6);


        verticalLayout_7->addWidget(groupBoxexcel);

        groupBoxtable = new QGroupBox(pagenormal);
        groupBoxtable->setObjectName(QString::fromUtf8("groupBoxtable"));
        gridLayout_3 = new QGridLayout(groupBoxtable);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        spinBoxrow = new QSpinBox(groupBoxtable);
        spinBoxrow->setObjectName(QString::fromUtf8("spinBoxrow"));
        spinBoxrow->setMinimum(1);
        spinBoxrow->setMaximum(1000);
        spinBoxrow->setValue(2);

        gridLayout_3->addWidget(spinBoxrow, 0, 1, 1, 1);

        spinBoxcolumn = new QSpinBox(groupBoxtable);
        spinBoxcolumn->setObjectName(QString::fromUtf8("spinBoxcolumn"));
        spinBoxcolumn->setMinimum(1);
        spinBoxcolumn->setMaximum(1000);
        spinBoxcolumn->setValue(2);

        gridLayout_3->addWidget(spinBoxcolumn, 1, 1, 1, 1);

        label = new QLabel(groupBoxtable);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(groupBoxtable);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);


        verticalLayout_7->addWidget(groupBoxtable);

        verticalSpacer_2 = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);


        verticalLayout_15->addLayout(verticalLayout_7);

        stackedWidgetsetting->addWidget(pagenormal);

        verticalLayout_8->addWidget(stackedWidgetsetting);


        verticalLayout_10->addWidget(groupBox_6);


        horizontalLayout_3->addLayout(verticalLayout_10);

        stackedWidgetshow = new QStackedWidget(DialogLoadDataClass);
        stackedWidgetshow->setObjectName(QString::fromUtf8("stackedWidgetshow"));
        pagetable = new QWidget();
        pagetable->setObjectName(QString::fromUtf8("pagetable"));
        verticalLayout_11 = new QVBoxLayout(pagetable);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        labelfilepath = new QLabel(pagetable);
        labelfilepath->setObjectName(QString::fromUtf8("labelfilepath"));
        labelfilepath->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));

        verticalLayout_9->addWidget(labelfilepath);

        label_7 = new QLabel(pagetable);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_9->addWidget(label_7);

        tableView = new TableViewLoadHistory(pagetable);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_9->addWidget(tableView);


        verticalLayout_11->addLayout(verticalLayout_9);

        stackedWidgetshow->addWidget(pagetable);

        horizontalLayout_3->addWidget(stackedWidgetshow);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        verticalLayout_13->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButtonnext = new QPushButton(DialogLoadDataClass);
        pushButtonnext->setObjectName(QString::fromUtf8("pushButtonnext"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("C:/Users/SoftWare/WellTest/WellTest/Resources/Icon/page/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonnext->setIcon(icon4);

        horizontalLayout_4->addWidget(pushButtonnext);

        pushButtonclose = new QPushButton(DialogLoadDataClass);
        pushButtonclose->setObjectName(QString::fromUtf8("pushButtonclose"));

        horizontalLayout_4->addWidget(pushButtonclose);


        verticalLayout_13->addLayout(horizontalLayout_4);

        verticalLayout_13->setStretch(0, 1);
        verticalLayout_13->setStretch(1, 10);
        verticalLayout_13->setStretch(2, 1);

        retranslateUi(DialogLoadDataClass);

        stackedWidgetsetting->setCurrentIndex(0);
        stackedWidgetshow->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogLoadDataClass);
    } // setupUi

    void retranslateUi(QDialog *DialogLoadDataClass)
    {
        DialogLoadDataClass->setWindowTitle(QApplication::translate("DialogLoadDataClass", "DialogLoadData", nullptr));
        labelreminder->setText(QString());
        groupBox_5->setTitle(QApplication::translate("DialogLoadDataClass", "\345\237\272\347\241\200\350\256\276\347\275\256", nullptr));
        groupBox_4->setTitle(QApplication::translate("DialogLoadDataClass", "\347\264\242\345\274\225\346\227\266\351\227\264\350\256\276\347\275\256", nullptr));
        label_2->setText(QApplication::translate("DialogLoadDataClass", "\345\210\235\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        dateTimeEdit->setDisplayFormat(QApplication::translate("DialogLoadDataClass", "yyyy/MM/dd HH:mm:ss", nullptr));
        label_3->setText(QApplication::translate("DialogLoadDataClass", "\350\256\276\347\275\256\347\264\242\345\274\225\345\220\215\347\247\260\357\274\232", nullptr));
        groupBoxfre->setTitle(QApplication::translate("DialogLoadDataClass", "\346\225\260\346\215\256\351\207\207\346\240\267\351\242\221\347\216\207", nullptr));
        label_8->setText(QApplication::translate("DialogLoadDataClass", "\351\207\207\346\240\267\351\242\221\347\216\207\357\274\210Hz\357\274\211", nullptr));
        groupBox_6->setTitle(QApplication::translate("DialogLoadDataClass", "\345\257\274\345\205\245\346\226\271\345\274\217\350\256\276\347\275\256", nullptr));
        groupBox_3->setTitle(QApplication::translate("DialogLoadDataClass", "\351\200\211\346\213\251\346\225\260\346\215\256\346\235\245\346\272\220", nullptr));
        pushButtontxt->setText(QString());
        pushButtonexcel->setText(QString());
        pushButtonclipboard->setText(QString());
        pushButtontable->setText(QString());
        groupBoxexcel->setTitle(QApplication::translate("DialogLoadDataClass", "ExcelSheet\350\256\276\347\275\256", nullptr));
        label_5->setText(QApplication::translate("DialogLoadDataClass", "Sheet\351\200\211\346\213\251", nullptr));
        label_6->setText(QApplication::translate("DialogLoadDataClass", "*\350\257\273\345\217\226EXCEL\350\277\207\347\250\213\344\274\232\345\207\272\347\216\260\346\240\207\345\207\206\346\227\266\351\227\264\344\270\272\345\260\217\346\225\260\346\240\274\345\274\217\357\274\214\345\217\257\344\273\245\351\200\211\346\213\251\345\257\271\345\272\224\346\226\271\345\274\217\350\277\233\350\241\214\350\275\254\346\215\242", nullptr));
        groupBoxtable->setTitle(QApplication::translate("DialogLoadDataClass", "\350\241\214\345\210\227\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("DialogLoadDataClass", "\350\241\214\346\225\260", nullptr));
        label_4->setText(QApplication::translate("DialogLoadDataClass", "\345\210\227\346\225\260", nullptr));
        labelfilepath->setText(QApplication::translate("DialogLoadDataClass", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        label_7->setText(QApplication::translate("DialogLoadDataClass", "*\350\241\250\346\240\274\345\217\252\346\230\276\347\244\272\351\203\250\345\210\206\346\225\260\346\215\256", nullptr));
        pushButtonnext->setText(QApplication::translate("DialogLoadDataClass", "\347\241\256\350\256\244\350\275\275\345\205\245", nullptr));
        pushButtonclose->setText(QApplication::translate("DialogLoadDataClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogLoadDataClass: public Ui_DialogLoadDataClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLOADDATA_H
