#include "tcpserver.h"



TcpServer::TcpServer(QObject *parent) : QTcpServer(parent) {
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

TcpServer::~TcpServer() {
    closeServer();  // 确保在析构时关闭连接
}

void TcpServer::onNewConnection() {
    if (clientSocket == nullptr) {  // 仅当没有现有连接时接受新连接
        clientSocket = this->nextPendingConnection();
        qDebug() << "New connection from:" << clientSocket->peerAddress().toString() << clientSocket->peerPort();
        connect(clientSocket, &QTcpSocket::readyRead, this, &TcpServer::onReadyRead);
        connect(clientSocket, &QTcpSocket::disconnected, this, &TcpServer::onClientDisconnected);
    }
}

void TcpServer::onReadyRead() {
    QByteArray data = clientSocket->readAll();
    qDebug() << "Received:" << data;
    // 转化为字符串
    QString str = QString::fromUtf8(data);
    // 转化为int
    int num = str.toInt();
    // 如果大于80，回消息ERROR，其他回消息OK
    if (num > 80) {
        clientSocket->write("ERROR");
    } else {
        clientSocket->write("OK");
    }
}

// 当客户端意外断开连接时
void TcpServer::onClientDisconnected() {
    clientSocket->deleteLater();  // 断开连接后删除socket
    clientSocket = nullptr;  // 重置客户端socket指针
}

void TcpServer::closeServer() {
    if (clientSocket && clientSocket->state() == QTcpSocket::ConnectedState) {
        clientSocket->disconnectFromHost();
        clientSocket->waitForDisconnected();  // 可选的，等待断开连接完成
    }
    this->close();  // 关闭服务器
}
