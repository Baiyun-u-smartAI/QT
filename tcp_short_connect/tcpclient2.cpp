#include "tcpclient2.h"
using namespace another;

TcpClient::TcpClient(const QString &host, quint16 port, QObject *parent) : QObject(parent), m_host(host), m_port(port) {
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(onConnected()));
}

void TcpClient::connectToServer() {
    socket->connectToHost(m_host, m_port);
}

void TcpClient::onConnected() {
    qDebug() << "Connected to server";
    socket->write("Hello from client");
    socket->disconnectFromHost(); // 客户端发送完消息后主动断开连接
}
