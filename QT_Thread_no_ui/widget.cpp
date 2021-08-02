#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("this"));
    this->resize(800, 600);

    this->obj = new Thread_obj;// 创建线程对象
    // 将对象应用到新的线程上
#ifndef SingleThread
    this->thread = new QThread;
    this->obj->moveToThread(thread);
#endif
    // 输出当前UI的线程
    qDebug()<<QThread::currentThreadId();


    this->gridLayout = new QGridLayout(this);
    this->gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    this->pushButton = new QPushButton(this);
    this->pushButton->setObjectName(QString::fromUtf8("pushButton"));
    QFont font;
    font.setPointSize(20);
    this->pushButton->setFont(font);

    // 将按钮的信号与另一线程对象的槽函数关联
    QObject::connect(pushButton,SIGNAL(clicked()),obj,SLOT(slot()),Qt::QueuedConnection);


    this->gridLayout->addWidget(pushButton, 1, 0, 1, 1);

    this->lineEdit = new QLineEdit(this);
    this->lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    this->lineEdit->setFont(font);

    this->gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

    this->label = new QLabel(this);
    this->label->setObjectName(QString::fromUtf8("label"));
    this->label->setFont(font);
    this->obj->init(label);

    this->gridLayout->addWidget(label, 2, 0, 1, 1);


    this->retranslateUi();

    QMetaObject::connectSlotsByName(this);
#ifndef SingleThread
    this->thread->start();// 启动线程
#endif
}

Widget::~Widget()
{
#ifndef SingleThread
    // 关闭线程
    this->thread->deleteLater();
    //this->thread->exit();
#endif
}


void Widget::retranslateUi(){
    this->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
    this->pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
    this->lineEdit->setText(QString());
    this->label->setText(QString());
}
