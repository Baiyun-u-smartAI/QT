#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    // 关闭线程
    ui->thread->deleteLater();
    ui->thread->exit();

    delete ui;
}

