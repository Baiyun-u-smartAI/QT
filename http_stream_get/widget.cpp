#include "widget.h"

#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    sensorClient = new SensorClient(this);
    httpServer = new HttpServer(this);
    httpServer->listen(QHostAddress::AnyIPv4, 8080);
    // 水平布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    this->setLayout(layout);
    // 初始化labels
    for (int i = 0; i < 3; i++)
    {
        labels[i] = new QLabel(this);
        labels[i]->setFont(QFont("", 25));
        layout->addWidget(labels[i]);
    }

    // connect(sensorClient, SIGNAL(dataUpdated(QList<float>)), this, SLOT(onDataUpdated(QList<float>)));

}

Widget::~Widget() {}

void Widget::onDataUpdated(const QList<float> &data)
{
    QStringList prefix{"X轴加速度","Y轴加速度","Z轴加速度"};
    // 将data[0]~[2] 分别设置为labels[0]~[2]的文本内容
    for (int i = 0; i < 3; i++)
    {
        labels[i]->setText(prefix[i] + QString::number(data[i]));
    }
}
