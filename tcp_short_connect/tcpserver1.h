#ifndef TCPSERVER1_H
#define TCPSERVER1_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class TcpServer : public QTcpServer {
    Q_OBJECT
public:
    TcpServer(QObject *parent = nullptr);

public slots:
    void closeServer();

private:
    QTcpSocket *socket;

private slots:
    void onReadyRead();
    void onNewConnection();

};

#endif // TCPSERVER1_H
