#include "reverseproxy.h"



ReverseProxyServer::ReverseProxyServer(QObject *parent) : QTcpServer(parent) {
    if (!listen(QHostAddress("192.168.1.85"), 999)) {
        qCritical() << "Unable to start the server";
        return;
    }
    connect(this, &QTcpServer::newConnection, this, &ReverseProxyServer::onNewConnection);
}

void ReverseProxyServer::onNewConnection() {
    QTcpSocket *clientSocket = nextPendingConnection();
    QTcpSocket *serverSocket = new QTcpSocket(this);

    // 当从客户端接收到数据时，等待连接建立后再写入数据到目标服务器
    connect(clientSocket, &QTcpSocket::readyRead, [this, clientSocket, serverSocket]() {
        QByteArray data = clientSocket->readAll();
        if (serverSocket->state() == QAbstractSocket::ConnectedState) {
            serverSocket->write(data);
        } else {
            // 连接目标服务器
            connect(serverSocket, &QTcpSocket::connected, [serverSocket, data]() {
                serverSocket->write(data);
            });
            serverSocket->connectToHost("127.0.0.1", 3000);
        }
    });

    // 当从目标服务器接收到数据时，写入数据到客户端
    connect(serverSocket, &QTcpSocket::readyRead, [serverSocket, clientSocket]() {
        QByteArray data = serverSocket->readAll();
        clientSocket->write(data);
    });

    // 清理
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
    connect(serverSocket, SIGNAL(disconnected()), serverSocket, SLOT(deleteLater()));
}
