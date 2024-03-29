#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server = new another::TcpServer(this);
    client = new another::TcpClient("127.0.0.1", 12345, this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_openServer_clicked()
{
    server->listen(QHostAddress::AnyIPv4, 12345);
}


void Widget::on_closeServer_clicked()
{
    server->closeServer();
}


void Widget::on_clientConnect_clicked()
{
    client->connectToServer();
}

