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
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QTime>
#include <QFile>
#include "qsendbrowser.h"
QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *portEdit;
    QLineEdit *ipEdit;
    QsendBrowser *sendBrowser;
    QTextBrowser *receiveBrowser;
    QCommandLinkButton *Click2send;
    QSpacerItem* VSpacer1;
    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(492, 381);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        portEdit = new QLineEdit(Widget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        QFont font1;
        font1.setPointSize(17);
        portEdit->setFont(font1);
        portEdit->setAlignment(Qt::AlignCenter);
        {
            portEdit->setStyleSheet("background-color:");
            auto reg=QRegularExpression("^([1-9][0-9]{0,4})$");
            portEdit->setValidator(new QRegularExpressionValidator(reg,Widget));
        }
        portEdit->setToolTip(QString("0~65535之间"));
        portEdit->setToolTipDuration(5000);
        gridLayout->addWidget(portEdit, 0, 2, 1, 1);
        QObject::connect(portEdit,&QLineEdit::textChanged,[=](){
            int digit = portEdit->text().toInt();
            if (digit>65535){
                portEdit->setStyleSheet("background-color:rgb(255, 100,100);");
            }else{
                portEdit->setStyleSheet("background-color:");
            }
        });


        ipEdit = new QLineEdit(Widget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        ipEdit->setFont(font1);
        ipEdit->setAlignment(Qt::AlignCenter);
        {
            auto reg=QRegularExpression("^(1[0-9]{2}|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[1-9])\\."
"(1[0-9]{2}|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9])\\."
"(1[0-9]{2}|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9])\\."
"(1[0-9]{2}|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9])$");
            ipEdit->setValidator(new QRegularExpressionValidator(reg,Widget));
        }
        gridLayout->addWidget(ipEdit, 0, 0, 1, 1);

        sendBrowser = new QsendBrowser(Widget);
        sendBrowser->setObjectName(QString::fromUtf8("sendBrowser"));
        QObject::connect(sendBrowser,&QsendBrowser::send2file,[=](){

            if (sendBrowser->toPlainText().size()!=0){
                QFile file(QString("1.log"));

                file.open(QIODevice::Append);
                file.write("<font color=blue>[");
                file.write(QTime::currentTime().toString().toUtf8().data());
                file.write(".");
                std::string msec = std::to_string(QTime::currentTime().msec());
                msec.insert(0,3-msec.size(),'0');
                file.write(msec.c_str());
                file.write("]<font color = red> @admin </font> </font> :");
                file.write(sendBrowser->toPlainText().toUtf8().data());
                file.write("\n\n");
                file.close();
                sendBrowser->clear();
                file.open(QIODevice::ReadOnly|QIODevice::Text);



                receiveBrowser->setMarkdown(file.readAll());
                file.close();
            }

        });
        gridLayout->addWidget(sendBrowser, 1, 0, 2, 1);

        receiveBrowser = new QTextBrowser(Widget);
        receiveBrowser->setObjectName(QString::fromUtf8("receiveBrowser"));

        gridLayout->addWidget(receiveBrowser, 1, 2, 2, 1);

        Click2send = new QCommandLinkButton(Widget);
        Click2send->setObjectName(QString::fromUtf8("Click2send"));
        Click2send->setMaximumSize(QSize(30, 16777215));
        QObject::connect(Click2send,&QCommandLinkButton::clicked,[=](){
            emit sendBrowser->send2file();


        });


        gridLayout->addWidget(Click2send, 1, 1, 1, 1);


        VSpacer1=new QSpacerItem(20,40, QSizePolicy::Minimum,QSizePolicy::Expanding);
        gridLayout->addItem(VSpacer1, 2, 1, 1, 1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", ":", nullptr));
        Click2send->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
