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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QRegExpValidator>
#include <QTimer>
#include <QDebug>
QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    //QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(606, 69);// 设置总窗口初始大小
//        horizontalLayoutWidget = new QWidget(Widget);

//        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));

//        horizontalLayoutWidget->setGeometry(QRect(0, 0, 606, 69));
        // 不允许缩放窗口
        Widget->setMinimumHeight(69);
        Widget->setMaximumHeight(69);

        // 横式布局
        horizontalLayout_2 = new QHBoxLayout;
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        // horizontalLayout_2自适应窗口调整大小
        Widget->setLayout(horizontalLayout_2);

        // 新建输入框标题“密码”的标签
        label = new QLabel;
        label->setObjectName(QString::fromUtf8("label"));

        // 调整字体
        {
            QFont font;
            font.setPointSize(15);
            label->setFont(font);
        }

        horizontalLayout_2->addWidget(label);

        //纵式布局
        verticalLayout_3 = new QVBoxLayout;
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        // 输入框
        lineEdit = new QLineEdit;
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(9);// 最多可输入9个字符

        lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,}"),lineEdit));// 输入的内容要匹配正则 [0-9]{0,}
        verticalLayout_3->addWidget(lineEdit); //在 verticalLayout_3 生成输入框

        horizontalLayout_4 = new QHBoxLayout;
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        // 空白区域 高固定 宽自动延伸
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        horizontalLayout_4->addItem(horizontalSpacer);

        // 创建按钮
        pushButton = new QPushButton;
        pushButton->setObjectName(QString::fromUtf8("pushButton"));


        // 动作1：只要输入有改变 就lineEdit就变红 并隐藏输入内容
        auto connection1 = QObject::connect(lineEdit,&QLineEdit::textChanged,[=](){
            lineEdit->setEchoMode(QLineEdit::Password);
            lineEdit->setStyleSheet("color:red;");
        }
        );


        QObject::connect(pushButton, &QPushButton::clicked,[=](){
//            qDebug() << pushButton->text() << endl;
            // 如果lineEdit不被修改 则不执行任何动作
            if (lineEdit->text()==QCoreApplication::translate("Widget", "\xE7\xA9\xBA\xE7\x99\xBD", nullptr)) return ;


            QObject::disconnect(connection1);// 取消激活动作1
            if (pushButton->text()!="close") { // 当按钮名称不是close的时候
                QTimer::singleShot(1000,[=](){ //延时1000ms后运行
                    label->setText("");// 清空label文字
                    //重新调整大小
                    Widget->resize(601, 80);
                    Widget->setMinimumHeight(80);
                    Widget->setMaximumHeight(80);
                    horizontalLayout_2->removeWidget(label); // 删除label
                    lineEdit->setStyleSheet("color:green;");// lineEdit输入框文字设置成绿色
                    // 改变字体大小
                    {
                        QFont font;
                        font.setPointSize(26);
                        lineEdit->setFont(font);
                    }
                    lineEdit->setEchoMode(QLineEdit::Normal);// lineEdit 恢复显示正常

                    lineEdit->setText("answer:");
                    lineEdit->setReadOnly(true); // 不允许修改lineEdit的文字
                    pushButton->setText("close"); // 按钮名称改为close
                }
                );
            }
            else{// 第二次点击按钮时
                    lineEdit->setText("closing...");
                    lineEdit->setStyleSheet("color:black;");
                    QTimer::singleShot(3000, [=](){
                        Widget->close();
                    }
                    );

            }

        }
        );


        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        // 初始化lineEdit的值是 “空白”
        lineEdit->setText(QCoreApplication::translate("Widget", "\xE7\xA9\xBA\xE7\x99\xBD", nullptr));
        lineEdit->setEchoMode(QLineEdit::Normal); // 正常显示模式
        lineEdit->selectAll();// 光标全选

        label->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201\r\n", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244\xE2\x80\xBC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
