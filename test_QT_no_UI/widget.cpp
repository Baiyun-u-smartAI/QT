#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    this->setObjectName(QString::fromUtf8("Widget"));
    this->mainstack=new QStackedWidget(this);
    this->mainstack->setObjectName(QString::fromUtf8("stackedWidget"));
    this->W_page1 = new page1;
    this->W_page2 = new page2;
    mainstack->addWidget(W_page1);
    mainstack->addWidget(W_page2);
    mainstack->setCurrentIndex(0);
}
Widget::~Widget()
{
    qDebug()<<"Widget has been deleted"<<endl;
}
