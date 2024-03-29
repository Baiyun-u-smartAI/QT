#include "tcpserver1.h"


TcpServer::TcpServer(QObject *parent) : QTcpServer(parent) {
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void TcpServer::onNewConnection() {
    socket = this->nextPendingConnection();
    qDebug() << "New connection from:" << socket->peerAddress().toString() << socket->peerPort();
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
}

void TcpServer::onReadyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << "Received:" << data;
    // 处理数据...
    // 当准备好断开连接时:
    socket->disconnectFromHost();
}

// 关闭服务器
void TcpServer::closeServer() {
    this->close();
}
