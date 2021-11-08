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


//QPixmap convert2QT(const cv::Mat &src)
//{
//    cv::cvtColor(src,src,cv::COLOR_BGR2RGB);
//    QImage imdisplay((uchar*)src.data, src.cols, src.rows, src.step, QImage::Format_RGB888);
//    return QPixmap::fromImage(imdisplay);
//}
