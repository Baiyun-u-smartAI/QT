#include "simpleproxy.h"


SimpleProxyServer::SimpleProxyServer(QObject *parent) : QTcpServer(parent) {
    connect(this, &QTcpServer::newConnection, this, &SimpleProxyServer::onNewConnection);
}

void SimpleProxyServer::startServer(quint16 port) {
    if (!this->listen(QHostAddress::AnyIPv4, port)) {
        qDebug() << "Server could not start on port" << port;
    } else {
        qDebug() << "Server started on port" << port;
    }
}

void SimpleProxyServer::onNewConnection() {
    QTcpSocket* clientSocket = this->nextPendingConnection();
    QTcpSocket* serverSocket = new QTcpSocket(this);

    connect(clientSocket, &QTcpSocket::readyRead, [=]() {
        QByteArray data = clientSocket->readAll();
        serverSocket->write(data);
    });
    connect(serverSocket, &QTcpSocket::readyRead, [=]() {
        QByteArray data = serverSocket->readAll();
        clientSocket->write(data);
    });
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
    connect(serverSocket, SIGNAL(disconnected()), serverSocket, SLOT(deleteLater()));
    serverSocket->connectToHost("127.0.0.1", 3000); // 连接到目标服务器
}
