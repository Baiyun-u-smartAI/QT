/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QButtonGroup>
#include <QtDebug>
QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;

    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_4;
    QButtonGroup *group1;
    QButtonGroup *group2;
    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 326);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        radioButton_2 = new QRadioButton(Widget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 0, 1, 1, 1);

        radioButton_3 = new QRadioButton(Widget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 0, 2, 1, 1);



        radioButton_1 = new QRadioButton(Widget);
        radioButton_1->setObjectName(QString::fromUtf8("radioButton_1"));
        radioButton_1->setChecked(true);

        gridLayout->addWidget(radioButton_1, 0, 0, 1, 1);

        group1 = new QButtonGroup(Widget);
        group1->addButton(radioButton_1,1);
        group1->addButton(radioButton_2,2);
        group1->addButton(radioButton_3,3);
        QObject::connect(group1,static_cast<void(QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonClicked),[=](){
            qDebug()<<group1->checkedId();
        });

        radioButton_5 = new QRadioButton(Widget);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        gridLayout->addWidget(radioButton_5, 1, 1, 1, 1);

        radioButton_4 = new QRadioButton(Widget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout->addWidget(radioButton_4, 1, 0, 1, 1);

        radioButton_6 = new QRadioButton(Widget);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

        gridLayout->addWidget(radioButton_6, 1, 2, 1, 1);

        group2 = new QButtonGroup(Widget);
        group2->addButton(radioButton_4,4);
        group2->addButton(radioButton_5,5);
        group2->addButton(radioButton_6,6);
        QObject::connect(group2,static_cast<void(QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonClicked),[=](){
            qDebug()<<group2->checkedId();
        });



        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "2", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Widget", "3", nullptr));
        radioButton_6->setText(QCoreApplication::translate("Widget", "6", nullptr));
        radioButton_1->setText(QCoreApplication::translate("Widget", "1", nullptr));
        radioButton_5->setText(QCoreApplication::translate("Widget", "5", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Widget", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
