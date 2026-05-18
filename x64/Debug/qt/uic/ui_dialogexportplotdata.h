/********************************************************************************
** Form generated from reading UI file 'dialogexportplotdata.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEXPORTPLOTDATA_H
#define UI_DIALOGEXPORTPLOTDATA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "tablewidgetexportdata.h"

QT_BEGIN_NAMESPACE

class Ui_DialogExportPlotDataClass
{
public:
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBoxratetime;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonperiod;
    QRadioButton *radioButtonelapsed;
    QGroupBox *groupBoxdatetime;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBoxdatetime;
    QLabel *label_6;
    QDateTimeEdit *dateTimeEdit;
    QGroupBox *groupBoxtimesetting;
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxtmin;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBoxtmax;
    QLabel *label_3;
    QLabel *labeltmin;
    QLabel *label_4;
    QLabel *labeltmax;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioButtonclipboard;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonfile;
    QGroupBox *groupBoxfile;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QToolButton *toolButtontxt;
    QRadioButton *radioButtontxt;
    QToolButton *toolButtonexcel;
    QRadioButton *radioButtonexcel;
    QGridLayout *gridLayout_2;
    QLabel *labelfilename;
    QLabel *label_5;
    QGroupBox *groupBoxdatasetting;
    QVBoxLayout *verticalLayout;
    TableWidgetExportData *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonsure;
    QPushButton *pushButtonclose;

    void setupUi(QDialog *DialogExportPlotDataClass)
    {
        if (DialogExportPlotDataClass->objectName().isEmpty())
            DialogExportPlotDataClass->setObjectName(QString::fromUtf8("DialogExportPlotDataClass"));
        DialogExportPlotDataClass->resize(839, 657);
        verticalLayout_8 = new QVBoxLayout(DialogExportPlotDataClass);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBoxratetime = new QGroupBox(DialogExportPlotDataClass);
        groupBoxratetime->setObjectName(QString::fromUtf8("groupBoxratetime"));
        verticalLayout_2 = new QVBoxLayout(groupBoxratetime);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButtonperiod = new QRadioButton(groupBoxratetime);
        radioButtonperiod->setObjectName(QString::fromUtf8("radioButtonperiod"));

        verticalLayout_2->addWidget(radioButtonperiod);

        radioButtonelapsed = new QRadioButton(groupBoxratetime);
        radioButtonelapsed->setObjectName(QString::fromUtf8("radioButtonelapsed"));

        verticalLayout_2->addWidget(radioButtonelapsed);


        horizontalLayout_2->addWidget(groupBoxratetime);

        groupBoxdatetime = new QGroupBox(DialogExportPlotDataClass);
        groupBoxdatetime->setObjectName(QString::fromUtf8("groupBoxdatetime"));
        gridLayout_3 = new QGridLayout(groupBoxdatetime);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        checkBoxdatetime = new QCheckBox(groupBoxdatetime);
        checkBoxdatetime->setObjectName(QString::fromUtf8("checkBoxdatetime"));

        gridLayout_3->addWidget(checkBoxdatetime, 0, 0, 1, 1);

        label_6 = new QLabel(groupBoxdatetime);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(groupBoxdatetime);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        gridLayout_3->addWidget(dateTimeEdit, 2, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBoxdatetime);


        verticalLayout_7->addLayout(horizontalLayout_2);

        groupBoxtimesetting = new QGroupBox(DialogExportPlotDataClass);
        groupBoxtimesetting->setObjectName(QString::fromUtf8("groupBoxtimesetting"));
        gridLayout = new QGridLayout(groupBoxtimesetting);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBoxtimesetting);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        doubleSpinBoxtmin = new QDoubleSpinBox(groupBoxtimesetting);
        doubleSpinBoxtmin->setObjectName(QString::fromUtf8("doubleSpinBoxtmin"));
        doubleSpinBoxtmin->setDecimals(6);
        doubleSpinBoxtmin->setMinimum(-10000000000.000000000000000);
        doubleSpinBoxtmin->setMaximum(100000000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxtmin, 0, 1, 1, 1);

        label_2 = new QLabel(groupBoxtimesetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        doubleSpinBoxtmax = new QDoubleSpinBox(groupBoxtimesetting);
        doubleSpinBoxtmax->setObjectName(QString::fromUtf8("doubleSpinBoxtmax"));
        doubleSpinBoxtmax->setDecimals(6);
        doubleSpinBoxtmax->setMinimum(-1000000.000000000000000);
        doubleSpinBoxtmax->setMaximum(10000000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxtmax, 1, 1, 1, 1);

        label_3 = new QLabel(groupBoxtimesetting);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        labeltmin = new QLabel(groupBoxtimesetting);
        labeltmin->setObjectName(QString::fromUtf8("labeltmin"));

        gridLayout->addWidget(labeltmin, 2, 1, 1, 1);

        label_4 = new QLabel(groupBoxtimesetting);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        labeltmax = new QLabel(groupBoxtimesetting);
        labeltmax->setObjectName(QString::fromUtf8("labeltmax"));

        gridLayout->addWidget(labeltmax, 3, 1, 1, 1);


        verticalLayout_7->addWidget(groupBoxtimesetting);


        horizontalLayout_4->addLayout(verticalLayout_7);

        groupBox_2 = new QGroupBox(DialogExportPlotDataClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        radioButtonclipboard = new QRadioButton(groupBox_2);
        radioButtonclipboard->setObjectName(QString::fromUtf8("radioButtonclipboard"));

        verticalLayout_6->addWidget(radioButtonclipboard);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButtonfile = new QRadioButton(groupBox_2);
        radioButtonfile->setObjectName(QString::fromUtf8("radioButtonfile"));

        horizontalLayout->addWidget(radioButtonfile);


        verticalLayout_6->addLayout(horizontalLayout);

        groupBoxfile = new QGroupBox(groupBox_2);
        groupBoxfile->setObjectName(QString::fromUtf8("groupBoxfile"));
        verticalLayout_3 = new QVBoxLayout(groupBoxfile);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(groupBoxfile);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        toolButtontxt = new QToolButton(groupBox_3);
        toolButtontxt->setObjectName(QString::fromUtf8("toolButtontxt"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/Icon/txt.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtontxt->setIcon(icon);

        gridLayout_4->addWidget(toolButtontxt, 0, 0, 1, 1);

        radioButtontxt = new QRadioButton(groupBox_3);
        radioButtontxt->setObjectName(QString::fromUtf8("radioButtontxt"));

        gridLayout_4->addWidget(radioButtontxt, 0, 1, 1, 1);

        toolButtonexcel = new QToolButton(groupBox_3);
        toolButtonexcel->setObjectName(QString::fromUtf8("toolButtonexcel"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("res/Icon/excel.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonexcel->setIcon(icon1);

        gridLayout_4->addWidget(toolButtonexcel, 1, 0, 1, 1);

        radioButtonexcel = new QRadioButton(groupBox_3);
        radioButtonexcel->setObjectName(QString::fromUtf8("radioButtonexcel"));

        gridLayout_4->addWidget(radioButtonexcel, 1, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelfilename = new QLabel(groupBoxfile);
        labelfilename->setObjectName(QString::fromUtf8("labelfilename"));

        gridLayout_2->addWidget(labelfilename, 4, 1, 1, 1);

        label_5 = new QLabel(groupBoxfile);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);


        verticalLayout_6->addWidget(groupBoxfile);


        horizontalLayout_4->addWidget(groupBox_2);


        verticalLayout_8->addLayout(horizontalLayout_4);

        groupBoxdatasetting = new QGroupBox(DialogExportPlotDataClass);
        groupBoxdatasetting->setObjectName(QString::fromUtf8("groupBoxdatasetting"));
        verticalLayout = new QVBoxLayout(groupBoxdatasetting);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new TableWidgetExportData(groupBoxdatasetting);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_8->addWidget(groupBoxdatasetting);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButtonsure = new QPushButton(DialogExportPlotDataClass);
        pushButtonsure->setObjectName(QString::fromUtf8("pushButtonsure"));

        horizontalLayout_3->addWidget(pushButtonsure);

        pushButtonclose = new QPushButton(DialogExportPlotDataClass);
        pushButtonclose->setObjectName(QString::fromUtf8("pushButtonclose"));

        horizontalLayout_3->addWidget(pushButtonclose);


        verticalLayout_8->addLayout(horizontalLayout_3);


        retranslateUi(DialogExportPlotDataClass);

        QMetaObject::connectSlotsByName(DialogExportPlotDataClass);
    } // setupUi

    void retranslateUi(QDialog *DialogExportPlotDataClass)
    {
        DialogExportPlotDataClass->setWindowTitle(QApplication::translate("DialogExportPlotDataClass", "DialogExportPlotData", nullptr));
        groupBoxratetime->setTitle(QApplication::translate("DialogExportPlotDataClass", "\344\272\247\351\207\217\346\227\266\351\227\264\347\261\273\345\236\213", nullptr));
        radioButtonperiod->setText(QApplication::translate("DialogExportPlotDataClass", "\351\230\266\346\256\265\346\227\266\351\227\264", nullptr));
        radioButtonelapsed->setText(QApplication::translate("DialogExportPlotDataClass", "\346\214\201\347\273\255\346\227\266\351\227\264", nullptr));
        groupBoxdatetime->setTitle(QApplication::translate("DialogExportPlotDataClass", "\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        checkBoxdatetime->setText(QApplication::translate("DialogExportPlotDataClass", "\350\275\254\346\215\242\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        label_6->setText(QApplication::translate("DialogExportPlotDataClass", "\350\265\267\345\247\213\346\227\245\346\234\237\346\227\266\351\227\264\357\274\232", nullptr));
        groupBoxtimesetting->setTitle(QApplication::translate("DialogExportPlotDataClass", "\346\227\266\351\227\264\350\214\203\345\233\264\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("DialogExportPlotDataClass", "\345\210\235\345\247\213\346\227\266\351\227\264-hr", nullptr));
        label_2->setText(QApplication::translate("DialogExportPlotDataClass", "\347\273\223\346\235\237\346\227\266\351\227\264-hr", nullptr));
        label_3->setText(QApplication::translate("DialogExportPlotDataClass", "\346\234\200\345\260\217\346\227\266\351\227\264-hr", nullptr));
        labeltmin->setText(QString());
        label_4->setText(QApplication::translate("DialogExportPlotDataClass", "\346\234\200\345\244\247\346\227\266\351\227\264-hr", nullptr));
        labeltmax->setText(QString());
        groupBox_2->setTitle(QApplication::translate("DialogExportPlotDataClass", "\344\277\235\345\255\230\350\256\276\347\275\256", nullptr));
        radioButtonclipboard->setText(QApplication::translate("DialogExportPlotDataClass", "\345\211\252\345\210\207\346\235\277", nullptr));
        radioButtonfile->setText(QApplication::translate("DialogExportPlotDataClass", "\346\226\207\344\273\266", nullptr));
        groupBoxfile->setTitle(QApplication::translate("DialogExportPlotDataClass", "\346\226\207\344\273\266\350\256\276\347\275\256", nullptr));
        groupBox_3->setTitle(QApplication::translate("DialogExportPlotDataClass", "\347\261\273\345\236\213", nullptr));
        toolButtontxt->setText(QApplication::translate("DialogExportPlotDataClass", "...", nullptr));
        radioButtontxt->setText(QApplication::translate("DialogExportPlotDataClass", "Txt", nullptr));
        toolButtonexcel->setText(QApplication::translate("DialogExportPlotDataClass", "...", nullptr));
        radioButtonexcel->setText(QApplication::translate("DialogExportPlotDataClass", "Excel", nullptr));
        labelfilename->setText(QString());
        label_5->setText(QApplication::translate("DialogExportPlotDataClass", "\346\226\207\344\273\266\345\220\215", nullptr));
        groupBoxdatasetting->setTitle(QApplication::translate("DialogExportPlotDataClass", "\345\257\274\345\207\272\346\225\260\346\215\256\350\256\276\347\275\256", nullptr));
        pushButtonsure->setText(QApplication::translate("DialogExportPlotDataClass", "\347\241\256\350\256\244", nullptr));
        pushButtonclose->setText(QApplication::translate("DialogExportPlotDataClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogExportPlotDataClass: public Ui_DialogExportPlotDataClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEXPORTPLOTDATA_H
