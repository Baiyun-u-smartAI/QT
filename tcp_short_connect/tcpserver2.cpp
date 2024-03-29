#include "tcpserver2.h"
using namespace another;

TcpServer::TcpServer(QObject *parent) : QTcpServer(parent) {
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void TcpServer::closeServer()
{
    this->close();
}

void TcpServer::onNewConnection() {
    socket = this->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
}

void TcpServer::onReadyRead() {
    QByteArray data = socket->readAll();
    qDebug() << "Received:" << data;
    // 处理数据...
}

void TcpServer::onDisconnected()
{
    qDebug() << "Client disconnected";
    socket->deleteLater();
}
