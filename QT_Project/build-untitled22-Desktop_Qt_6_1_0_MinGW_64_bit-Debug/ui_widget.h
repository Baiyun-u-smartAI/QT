/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>
#include <QTimer>
#include <QDebug>
QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPlainTextEdit *plainTextEdit;
    QTimer *delay;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(50, 70, 571, 321));
        delay = new QTimer;
        delay->setInterval(3000);
        delay->start();
        QObject::connect(delay,&QTimer::timeout,[=](){
            delay->stop();

            QTextCursor cursor=plainTextEdit->textCursor();
            int pos=cursor.position();
            //cursor.setVerticalMovementX(1);
            plainTextEdit->setPlainText("!!"+plainTextEdit->toPlainText());
            cursor.setPosition(pos+2);
            plainTextEdit->setTextCursor(cursor);

            delay->setInterval(3000);
            delay->start();
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
