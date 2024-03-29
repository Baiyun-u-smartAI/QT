#include "httpserver.h"


HttpServer::HttpServer(QObject *parent): QTcpServer{parent}
{
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

HttpServer::~HttpServer()
{

}

void HttpServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    addPendingConnection(socket);
}

void HttpServer::onNewConnection()
{
    QTcpSocket *socket = nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead,  [=]() { onDataReceived(socket); });
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
}

void HttpServer::onDataReceived(QTcpSocket *socket)
{
    if (socket->canReadLine()) {
        // 读取请求行和头部，忽略它们（在实际应用中，你可能需要根据这些信息进行处理）
        while (socket->canReadLine()) {
            QString line = socket->readLine();
            if (line == "\r\n") break; // 空行标志着头部结束
        }

        // 读取剩余的数据作为正文
        QByteArray body = socket->readAll();

        // 解析JSON正文
        QJsonDocument jsonDoc = QJsonDocument::fromJson(body);
        QJsonObject jsonObj = jsonDoc.object();

        // 在这里处理JSON对象
        qDebug() << "Received: " << jsonObj;

        // 发送响应
        QString response = "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n{\"status\":\"received\"}";
        socket->write(response.toUtf8());
        socket->flush();
        socket->disconnectFromHost();
    }
}
