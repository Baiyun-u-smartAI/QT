#ifndef TCPSERVER2_H
#define TCPSERVER2_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QCoreApplication>
#include <QDebug>
namespace another {


class TcpServer : public QTcpServer {
    Q_OBJECT
public:
    TcpServer(QObject *parent = nullptr);
public slots:
    void closeServer();

private slots:
    void onReadyRead();
    void onDisconnected();
    void onNewConnection();
private:
    QTcpSocket *socket;
};

}

#endif // TCPSERVER2_H
