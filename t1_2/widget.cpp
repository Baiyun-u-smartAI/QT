#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("Widget"));
    this->resize(308, 143);
    gridLayout = new QGridLayout(this);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    showNum = new showNumLabel(this);
//    showNum->setObjectName(QString::fromUtf8("showNum"));
//    QFont font;
//    font.setPointSize(18);
//    showNum->setFont(font);
//    showNum->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(showNum, 1, 1, 1, 1);

    add1 = new QPushButton(this);
    add1->setObjectName(QString::fromUtf8("add1"));
    QFont font;
    font.setPointSize(15);
    add1->setFont(font);

    // 点击后显示数字+1
    QObject::connect(add1,SIGNAL(clicked(bool)),this,SLOT(pushbutton_add1(bool)));




    gridLayout->addWidget(add1, 2, 0, 1, 1);

    minus1 = new QPushButton(this);
    minus1->setObjectName(QString::fromUtf8("minus1"));
    minus1->setFont(font);

    // 点击后显示数字-1
    connect(minus1,SIGNAL(clicked(bool)),showNum,SLOT(minus_1(bool)));


    gridLayout->addWidget(minus1, 2, 2, 1, 1);

    label_2 = new QLabel(this);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    QFont font2;
    font2.setPointSize(11);
    label_2->setFont(font2);
    label_2->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_2, 0, 1, 1, 1);

    resetBtn = new QPushButton(this);
    resetBtn->setObjectName(QString::fromUtf8("resetBtn"));
    resetBtn->setFont(font);

    thd = new reset_thread;
    thread = new QThread;
    this->thd->moveToThread(thread);
    thread->start();
    qDebug()<<"main UI thread:"<<QThread::currentThreadId();
    thd->addLabel(this->showNum);
    connect(resetBtn,SIGNAL(clicked()),thd,SLOT(thisSlot()),Qt::QueuedConnection);

    gridLayout->addWidget(resetBtn, 3, 0, 1, 3);

    retranslateUi();

    QMetaObject::connectSlotsByName(this);
}

void Widget::retranslateUi(){
    this->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
//    showNum->setText(QCoreApplication::translate("Widget", "0", nullptr));
    add1->setText(QCoreApplication::translate("Widget", "+1", nullptr));
    minus1->setText(QCoreApplication::translate("Widget", "-1", nullptr));
    label_2->setText(QCoreApplication::translate("Widget", "\344\277\241\345\217\267\346\247\275\346\265\213\350\257\225", nullptr));
    resetBtn->setText(QCoreApplication::translate("Widget", "reset", nullptr));
}


void Widget::pushbutton_add1(bool){
    uint8_t temp =  this->showNum->text().toInt();// uint8_t 相当于unsigned char
    this->showNum->setText(QString::number(++temp));
}

Widget::~Widget()
{
}

