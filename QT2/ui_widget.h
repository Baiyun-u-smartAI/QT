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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <QTime>
#include <QTimer>
#include <QtDebug>
QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
//    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QTimer* timer;
    bool changeGreen;
    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
//        gridLayoutWidget = new QWidget(Widget);
//        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
//        gridLayoutWidget->setGeometry(QRect(50, 110, 571, 171));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 2);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

//        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/75f24a.jpg);"));

        gridLayout->addWidget(label, 0, 2, 3, 2);

        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setDigitCount(8);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->display(QTime::currentTime().toString("hh:mm:ss"));
        lcdNumber->setStyleSheet("color: green");
        changeGreen=true;
        gridLayout->addWidget(lcdNumber,1,0,1,2);


        timer = new QTimer(Widget);
        timer->setInterval(100);
        timer->start();
        QObject::connect(timer,&QTimer::timeout,[=](){
            timer->stop();
            changeGreen=!changeGreen;
            if (!changeGreen){
                lcdNumber->setStyleSheet("color: default");
            }else{
                lcdNumber->setStyleSheet("color: green");
            }

            lcdNumber->display(QTime::currentTime().toString("hh:mm:ss"));
            timer->setInterval(100);
            timer->start();
        });

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
