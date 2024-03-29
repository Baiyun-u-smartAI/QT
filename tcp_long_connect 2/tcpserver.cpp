#include "tcpserver.h"



TcpServer::TcpServer(QObject *parent) : QTcpServer(parent) {
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

TcpServer::~TcpServer() {
    closeServer();  // 确保在析构时关闭连接
}

void TcpServer::onNewConnection() {
    while (this->hasPendingConnections()) {
        QTcpSocket *socket = this->nextPendingConnection();
        qDebug() << "New connection from:" << socket->peerAddress().toString() << socket->peerPort();
        connect(socket, &QTcpSocket::readyRead, this, &TcpServer::onReadyRead);
        connect(socket, &QTcpSocket::disconnected, this, &TcpServer::onClientDisconnected);
        clients.append(socket);  // 将新的连接添加到列表中
    }
}

void TcpServer::onReadyRead() {
    QTcpSocket *socket = (QTcpSocket *)this->sender();
    if (socket) { // 确保socket不为空
        QByteArray data = socket->readAll();
        qDebug() << "Received from"<< socket->peerAddress().toString() << socket->peerPort() << ":" << data;
        // 转化为字符串
        QString str = QString::fromUtf8(data);
        // 转化为int
        int num = str.toInt();
        // 如果大于80，回消息ERROR，其他回消息OK
        if (num > 80) {
            socket->write("ERROR");
        } else {
            socket->write("OK");
        }
    }
}

// 当客户端意外断开连接时
void TcpServer::onClientDisconnected() {
    QTcpSocket *socket = (QTcpSocket *)this->sender();
    if (socket) {
        clients.removeAll(socket);
        socket->deleteLater();  // 断开连接后删除socket
    }
}

void TcpServer::closeServer() {
    for (auto &socket : clients) {
        if (socket->state() == QTcpSocket::ConnectedState) {
            socket->disconnectFromHost();
        }
        socket->deleteLater();  // 删除socket对象
    }
    clients.clear();  // 清空客户端列表
    this->close();  // 关闭服务器
}
