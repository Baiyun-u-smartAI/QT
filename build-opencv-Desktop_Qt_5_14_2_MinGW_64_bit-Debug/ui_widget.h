/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include <opencv2/opencv.hpp>
#include <QFile>
#include <QTimer>
#include "wrapper.h"
QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QGraphicsScene *graphicsScene;
    QTimer * timer;
    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(272, 217);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        // 创建显示图片的窗口
        graphicsScene = new QGraphicsScene(Widget);
        cv::Mat show = wrapper::loadFromQrc(":/Windows-1-0-1.jpg");
        graphicsScene->addPixmap(wrapper::convert2QT(show));//  将opencv Mat转化成布景

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);
        graphicsView->setScene(graphicsScene);// 应用布局


        timer = new QTimer(Widget);
        timer->setInterval(3000);
        timer->start();
        QObject::connect(timer,&QTimer::timeout,[=]{
            graphicsScene->clear();
            graphicsView->setScene(graphicsScene);// 应用布局
        });

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
