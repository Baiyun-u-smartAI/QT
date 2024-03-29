#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpSocket>
#include <QTcpServer>
class TcpServer : public QTcpServer {
    Q_OBJECT

public:
    TcpServer(QObject *parent = nullptr);
    ~TcpServer();

protected slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();

public:
    void closeServer();

private:
    QTcpSocket* clientSocket = nullptr;  // 保留单一客户端连接
};













#endif // TCPSERVER_H
