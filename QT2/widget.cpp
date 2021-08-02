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
    delete ui;
}

void Widget::wheelEvent(QWheelEvent *event){

       if ( QApplication::keyboardModifiers () == Qt::ControlModifier)
        {
           if (event->delta() > 0) {
               qDebug() << "wheel up";
           } else {
               qDebug() << "wheel down";
           }
        }
}
