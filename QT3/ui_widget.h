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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QtDebug>
#include <QMessageBox>
#define LAST_TIME (1)
QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QProgressBar *progressBar;
    QTimer* timer;
    QMessageBox *FinishedInfo;
    QTime set;
    QTime begin;
    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(637, 109);
        Widget->setStyleSheet("QProgressBar {border: 3px solid blue;}");
        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(70, 30, 431, 31));

        progressBar->setMinimum(0);
        progressBar->setMaximum(10000);
        progressBar->setValue(10000);
        progressBar->setFormat("");


        begin=QTime::currentTime();
        set=begin.addSecs(LAST_TIME);
        timer = new QTimer(Widget);
        timer->setInterval(100);
        timer->start();
        QObject::connect(timer,&QTimer::timeout,[=](){
            timer->stop();
            if (QTime::currentTime()<set){
                int last_s=QTime::currentTime().msecsTo(begin);
                progressBar->setValue(10000+int((last_s+.0)/LAST_TIME*10) );
            }
            else{
                progressBar->setValue(0);
                //const QTime& a=QTime::currentTime();
                //qDebug()<<a.hour()<<":"<<a.minute()<<":"<<a.second();
                FinishedInfo = new QMessageBox(Widget);
                this->FinishedInfo->setWindowFlags(Qt::WindowTitleHint|Qt::WindowStaysOnTopHint);
                this->FinishedInfo->warning(this->FinishedInfo,QString("TimeUp"),QString("Have to relax!"),QMessageBox::Ok,QMessageBox::NoButton);
                this->FinishedInfo->show();
                begin=QTime::currentTime();
                set=begin.addSecs(LAST_TIME);
            }
            timer->setInterval(100);
            timer->start();
        });
        //qDebug()<<set.hour()<<":"<<set.minute()<<":"<<set.second();
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
