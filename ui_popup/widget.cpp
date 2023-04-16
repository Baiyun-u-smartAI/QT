#include "widget.h"
#include "ui_widget.h"

#include <QCloseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    ui2 = new pop_up(this);
    ui2->setModal(true);
    ui2->show();

}

void QWidget::closeEvent(QCloseEvent *event)
{
    event->ignore();
}
