/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H
#include "widget.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QThread>
#include <QDebug>

QT_BEGIN_NAMESPACE


class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QThread *thread;// 用于新建线程
    Thread_obj *obj;// 自定义用于独立线程的对象
    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);

        obj = new Thread_obj;// 创建线程对象
        // 将对象应用到新的线程上
        thread = new QThread;
        obj->moveToThread(thread);

        // 输出当前UI的线程
        qDebug()<<QThread::currentThreadId();


        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font;
        font.setPointSize(20);
        pushButton->setFont(font);

        // 将按钮的信号与另一线程对象的槽函数关联
        QObject::connect(pushButton,SIGNAL(clicked()),obj,SLOT(slot()),Qt::QueuedConnection);


        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        obj->init(label);

        gridLayout->addWidget(label, 2, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);

        thread->start();// 启动线程

    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        lineEdit->setText(QString());
        label->setText(QString());
    } // retranslateUi




};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
