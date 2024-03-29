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
    QList<QTcpSocket*> clients;  // 用于存储所有客户端连接的列表
};













#endif // TCPSERVER_H
