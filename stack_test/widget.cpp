#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(797, 600);
    this->setObjectName(QString::fromUtf8("Widget"));
    mainstack = new QStackedWidget(this);
    mainstack->resize(797, 600);
    mainstack->setObjectName(QString::fromUtf8("stackedWidget"));
    page = new page1;
    nextpage = new page2;

    mainstack->addWidget(page);
    mainstack->addWidget(nextpage);
    mainstack->setCurrentIndex(0);
    connect(this->page->radioButton_3,SIGNAL(clicked()),this,SLOT(switchpage()));
    connect(this->nextpage->radioButton_3,SIGNAL(clicked()),this,SLOT(switchpage()));
}

Widget::~Widget()
{
    qDebug()<<"Widget has been deleted"<<endl;
}

void Widget::switchpage()
{
    int val=mainstack->currentIndex();
    mainstack->setCurrentIndex(!val);
}



