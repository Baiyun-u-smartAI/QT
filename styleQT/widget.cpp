#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 各种控件的初始化
    for (auto& i: title)
    {
        i = new QLabel(this);
        i->setAlignment(Qt::AlignmentFlag::AlignCenter);
    }


    for (auto& i: mode)
    {
        i = new MyButton(this);
    }


    for (auto& i: tControl)
    {
        i = new MyButton(this);
    }

    middle = new QLabel(this);
    power = new MyButton(this);
    this->init(); // 初始化各个控件的样式、位置、文字....

#ifdef WIDGET_STYLE

    this->connect(power, SIGNAL(clicked()), this, SLOT(gifControl())); // 用ON/OFF按钮控制动画播放

#endif

    this->connect(power, SIGNAL(clicked()), this, SLOT(switchPower())); // 用ON/OFF按钮控制标题变化



    // 输出控件的先后顺序
    foreach(auto i, this->children())
    {
        if (!i->objectName().isEmpty())
        {
            qDebug() << i->objectName();
        }
        if (i->objectName().indexOf("mode") != -1)
        {
            this->connect((QPushButton*)i, &QPushButton::clicked, this, std::bind(&Widget::changeMode, this, ((QPushButton*)i)->text())); // 设置mode按钮能改变显示内容
        }

#ifdef WIDGET_STYLE


        if (i->objectName().indexOf("tControl") != -1)
        {
            this->connect((QPushButton*)i, &QPushButton::clicked, this, std::bind(static_cast<void(Widget::*)(QString)>(&Widget::gifControl), this, ((QPushButton*)i)->objectName()));// 用 + - 控制动画快慢
        }

#endif
    }

}

Widget::~Widget()
{
}

void Widget::changeMode(QString statusText)
{
    // 获取冒号的位置
    int colonPos = title[1]->text().indexOf(":");

    // 删除原有状态值
    auto newTitle1 = title[1]->text();
    newTitle1.resize(colonPos+2);

    // 添加显示的状态值
    title[1]->setText(newTitle1 + statusText);
}

void Widget::switchPower()
{
    // 获取冒号的位置
    int colonPos = title[1]->text().indexOf(":");

    // 删除原有状态值
    auto newTitle1 = title[1]->text();
    newTitle1.resize(colonPos+2);


//    static QRect origin[3]{};
//    static QSize originW(0, 0);
//    static QSize originP(0, 0);

    if (title[1]->text().indexOf("OFF") >= 0) {
        title[1]->setText(newTitle1 + "ON");

//        if (!originP.isEmpty()) {
//            power->resize(originP);
//        }

//        if (!originW.isEmpty()) {
//            this->setMaximumSize(12288, 6480); // 12K
//            this->resize(originW);
//            this->setMinimumSize(this->size());
//            this->setMaximumSize(this->size());
//        }


//        for (int i = 0; i < 3; i++) {
//            if (!origin[i].isEmpty())
//                mode[i]->setGeometry(origin[i]);
//        }
    }
    else {
        title[1]->setText(newTitle1 + "OFF");

//        originP = power->size();
//        power->resize(power->width(), tControl[0]->y()+tControl[0]->height()-power->y());

//        originW = this->size();
//        this->setMinimumSize(QSize(0, 0));
//        this->resize(this->width(), power->y()+power->height()+10);
//        this->setMinimumSize(this->size());
//        this->setMaximumSize(this->size());

//        for (int i = 0; i < 3; i++) {
//            origin[i] = this->mode[i]->geometry();
//            mode[i]->setGeometry(this->power->geometry());
//        }
    }
}
