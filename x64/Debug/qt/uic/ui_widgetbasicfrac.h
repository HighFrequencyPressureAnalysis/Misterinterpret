/********************************************************************************
** Form generated from reading UI file 'widgetbasicfrac.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBASICFRAC_H
#define UI_WIDGETBASICFRAC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBasicFracClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBoxfraopera;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdittime;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QComboBox *comboBoxpstype;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxemulsion;
    QDoubleSpinBox *doubleSpinBoxpowder;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBoxslickwater;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBoxlineargel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBoxCfluid;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelall;
    QDoubleSpinBox *doubleSpinBoxall;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QSpinBox *spinBoxper;
    QSpinBox *spinBoxpercount;
    QLabel *label_7;
    QSpinBox *spinBoxallper;
    QLabel *labelallper;

    void setupUi(QWidget *WidgetBasicFracClass)
    {
        if (WidgetBasicFracClass->objectName().isEmpty())
            WidgetBasicFracClass->setObjectName(QString::fromUtf8("WidgetBasicFracClass"));
        WidgetBasicFracClass->resize(513, 278);
        verticalLayout = new QVBoxLayout(WidgetBasicFracClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox = new QGroupBox(WidgetBasicFracClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBoxfraopera = new QComboBox(groupBox);
        comboBoxfraopera->setObjectName(QString::fromUtf8("comboBoxfraopera"));

        gridLayout->addWidget(comboBoxfraopera, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        dateTimeEdittime = new QDateTimeEdit(groupBox);
        dateTimeEdittime->setObjectName(QString::fromUtf8("dateTimeEdittime"));

        gridLayout->addWidget(dateTimeEdittime, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(WidgetBasicFracClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        comboBoxpstype = new QComboBox(groupBox_2);
        comboBoxpstype->setObjectName(QString::fromUtf8("comboBoxpstype"));

        gridLayout_2->addWidget(comboBoxpstype, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        doubleSpinBoxemulsion = new QDoubleSpinBox(groupBox_2);
        doubleSpinBoxemulsion->setObjectName(QString::fromUtf8("doubleSpinBoxemulsion"));
        doubleSpinBoxemulsion->setDecimals(3);
        doubleSpinBoxemulsion->setMaximum(10.000000000000000);
        doubleSpinBoxemulsion->setValue(1.000000000000000);

        gridLayout_2->addWidget(doubleSpinBoxemulsion, 1, 1, 1, 1);

        doubleSpinBoxpowder = new QDoubleSpinBox(groupBox_2);
        doubleSpinBoxpowder->setObjectName(QString::fromUtf8("doubleSpinBoxpowder"));
        doubleSpinBoxpowder->setDecimals(3);
        doubleSpinBoxpowder->setMaximum(10.000000000000000);
        doubleSpinBoxpowder->setValue(1.000000000000000);

        gridLayout_2->addWidget(doubleSpinBoxpowder, 2, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 0, 1, 2, 1);

        groupBox_4 = new QGroupBox(WidgetBasicFracClass);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        doubleSpinBoxslickwater = new QDoubleSpinBox(groupBox_4);
        doubleSpinBoxslickwater->setObjectName(QString::fromUtf8("doubleSpinBoxslickwater"));
        doubleSpinBoxslickwater->setMaximum(2500.000000000000000);
        doubleSpinBoxslickwater->setValue(1500.000000000000000);

        horizontalLayout->addWidget(doubleSpinBoxslickwater);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);

        doubleSpinBoxlineargel = new QDoubleSpinBox(groupBox_4);
        doubleSpinBoxlineargel->setObjectName(QString::fromUtf8("doubleSpinBoxlineargel"));
        doubleSpinBoxlineargel->setMaximum(1000.000000000000000);
        doubleSpinBoxlineargel->setValue(500.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBoxlineargel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_3->addWidget(label_11);

        doubleSpinBoxCfluid = new QDoubleSpinBox(groupBox_4);
        doubleSpinBoxCfluid->setObjectName(QString::fromUtf8("doubleSpinBoxCfluid"));

        horizontalLayout_3->addWidget(doubleSpinBoxCfluid);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelall = new QLabel(groupBox_4);
        labelall->setObjectName(QString::fromUtf8("labelall"));

        horizontalLayout_4->addWidget(labelall);

        doubleSpinBoxall = new QDoubleSpinBox(groupBox_4);
        doubleSpinBoxall->setObjectName(QString::fromUtf8("doubleSpinBoxall"));
        doubleSpinBoxall->setEnabled(false);
        doubleSpinBoxall->setMaximum(5000.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBoxall);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_5->addWidget(groupBox_4, 1, 0, 2, 1);

        groupBox_3 = new QGroupBox(WidgetBasicFracClass);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        spinBoxper = new QSpinBox(groupBox_3);
        spinBoxper->setObjectName(QString::fromUtf8("spinBoxper"));
        spinBoxper->setMaximum(20);

        gridLayout_3->addWidget(spinBoxper, 0, 1, 1, 1);

        spinBoxpercount = new QSpinBox(groupBox_3);
        spinBoxpercount->setObjectName(QString::fromUtf8("spinBoxpercount"));
        spinBoxpercount->setMaximum(10);

        gridLayout_3->addWidget(spinBoxpercount, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        spinBoxallper = new QSpinBox(groupBox_3);
        spinBoxallper->setObjectName(QString::fromUtf8("spinBoxallper"));
        spinBoxallper->setEnabled(false);

        gridLayout_3->addWidget(spinBoxallper, 2, 1, 1, 1);

        labelallper = new QLabel(groupBox_3);
        labelallper->setObjectName(QString::fromUtf8("labelallper"));

        gridLayout_3->addWidget(labelallper, 2, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_5);


        retranslateUi(WidgetBasicFracClass);

        QMetaObject::connectSlotsByName(WidgetBasicFracClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetBasicFracClass)
    {
        WidgetBasicFracClass->setWindowTitle(QApplication::translate("WidgetBasicFracClass", "WidgetBasicFrac", nullptr));
        groupBox->setTitle(QApplication::translate("WidgetBasicFracClass", "\345\237\272\347\241\200\344\277\241\346\201\257", nullptr));
        label->setText(QApplication::translate("WidgetBasicFracClass", "\346\226\275\345\267\245\345\267\245\350\211\272", nullptr));
        label_2->setText(QApplication::translate("WidgetBasicFracClass", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        dateTimeEdittime->setDisplayFormat(QApplication::translate("WidgetBasicFracClass", "yyyy/MM/dd HH:mm:ss", nullptr));
        groupBox_2->setTitle(QApplication::translate("WidgetBasicFracClass", "\350\215\257\345\211\202\344\277\241\346\201\257", nullptr));
        label_3->setText(QApplication::translate("WidgetBasicFracClass", "\347\261\273\345\236\213", nullptr));
        label_4->setText(QApplication::translate("WidgetBasicFracClass", "\344\271\263\345\211\202\357\274\210\345\220\250/T\357\274\211", nullptr));
        label_5->setText(QApplication::translate("WidgetBasicFracClass", "\347\262\211\345\211\202(\345\220\250/T)", nullptr));
        groupBox_4->setTitle(QApplication::translate("WidgetBasicFracClass", "\346\266\262\344\275\223\347\224\250\351\207\217", nullptr));
        label_9->setText(QApplication::translate("WidgetBasicFracClass", "\346\273\221\346\272\234\346\260\264(m\302\263)", nullptr));
        label_10->setText(QApplication::translate("WidgetBasicFracClass", "\347\272\277\346\200\247\350\203\266(m\302\263)", nullptr));
        label_11->setText(QApplication::translate("WidgetBasicFracClass", "\344\272\244\350\201\224\346\266\262(m\302\263)", nullptr));
        labelall->setText(QApplication::translate("WidgetBasicFracClass", "\346\200\273\346\266\262\351\207\217(m\302\263)", nullptr));
        groupBox_3->setTitle(QApplication::translate("WidgetBasicFracClass", "\345\255\224\347\260\207\344\277\241\346\201\257", nullptr));
        label_8->setText(QApplication::translate("WidgetBasicFracClass", "\345\215\225\347\260\207\345\255\224\346\225\260", nullptr));
        label_7->setText(QApplication::translate("WidgetBasicFracClass", "\347\260\207\346\225\260", nullptr));
        labelallper->setText(QApplication::translate("WidgetBasicFracClass", "\346\200\273\345\255\224\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetBasicFracClass: public Ui_WidgetBasicFracClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBASICFRAC_H
