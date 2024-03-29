#include "simplehttpproxy.h"



SimpleHttpProxy::SimpleHttpProxy(QObject *parent) : QObject(parent) {
    connect(&server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    if (!server.listen(QHostAddress::AnyIPv4, 18080)) { // 代理服务器监听18080端口
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started!";
    }
}

void SimpleHttpProxy::onNewConnection() {
    QTcpSocket *clientSocket = server.nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, [=]() {
        QByteArray requestData = clientSocket->readAll();
        // 解析HTTP请求的第一行
        QString requestLine = QString(requestData).split("\r\n").first();
        QStringList requestParts = requestLine.split(" ");
        if (requestParts.length() < 3) return; // 简单的错误检查

        // 假设代理不修改请求的目标URL
        QString method = requestParts[0];
        QString url = requestParts[1];
        QString version = requestParts[2];

        // 构造QNetworkRequest
        QUrl qurl(url);
        qDebug() << "Request URL:" << qurl;
        QNetworkRequest request(qurl);
        QNetworkReply *reply = manager.get(request);

        connect(reply, &QNetworkReply::finished, [=]() {
            QByteArray responseData = reply->readAll();
            if (!responseData.isEmpty()) {
                // 简单的响应，没有处理HTTP响应头
                clientSocket->write("HTTP/1.1 200 OK\r\n\r\n");
                clientSocket->write(responseData);
                qDebug() << "Response sent:" << responseData.length() << "bytes";
                clientSocket->disconnectFromHost();
                reply->deleteLater();
            }
        });
    });
}

