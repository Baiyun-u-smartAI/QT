#include "mybutton.h"

#include <QResizeEvent>
#include <QDebug>

MyButton::MyButton(QWidget* parent):QPushButton(parent), isOk(false)
{
    animation = new QPropertyAnimation(this, "geometry");

    //设置动画时间间隔
    animation->setDuration(100);

    QFile qssF(":/button/button.qss");
    if (qssF.open(QFile::ReadOnly))
        this->setStyleSheet(qssF.readAll());
    qssF.close();


    this->setIconSize(this->size());
    this->setCursor(Qt::PointingHandCursor);
}

MyButton::~MyButton()
{
}

void MyButton::setEnabled(bool status)
{
    if (!status)
        qDebug() << this->objectName() << "被禁用";
    QPushButton::setEnabled(status);
}


void MyButton::enterEvent(QEvent*)
{
//    static bool first = true;
//    if (first) {
//        this->origin = this->geometry();
//        first = false;
//    }


    //if (animation->state() == QPropertyAnimation::Running) return;

    if (isOk && this->isEnabled())
        //执行动画
        animation->start();


}

void MyButton::resizeEvent(QResizeEvent *event)
{
//    static bool first = true;
    if (!event->size().isEmpty()) {
        //设置动画对象起始位置
        animation->setStartValue(QRect(this->x(),this->y()-10,this->width(),this->height()));

        //设置动画对象结束位置
        animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

        //设置曲线
        animation->setEasingCurve(QEasingCurve::OutBounce);
        this->isOk = true;
    }
}


