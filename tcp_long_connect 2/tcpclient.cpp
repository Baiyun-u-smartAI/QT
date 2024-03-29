#include "tcpclient.h"
#include <QThread>
#include <QRandomGenerator>
TcpClient::TcpClient(const QString &host, quint16 port, QObject *parent) : QObject(parent), m_host(host), m_port(port) {
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void TcpClient::connectToServer() {
    socket->connectToHost(m_host, m_port);
}

void TcpClient::onConnected() {
    // 随机发一个40-100之间的整数给服务器
    int num = QRandomGenerator::global()->bounded(61) + 40;

    qDebug() << "Connected to server, send:" << num;
    socket->write(QByteArray::number(num));

}

void TcpClient::onReadyRead() {
    QByteArray data = socket->readAll();
    qDebug() << "Received:" << data;
    // 延时50ms
    QThread::msleep(50);

    // 继续发消息
    int num = QRandomGenerator::global()->bounded(61) + 40;
    qDebug() << "Connected to server, send:" << num;
    socket->write(QByteArray::number(num));
}
