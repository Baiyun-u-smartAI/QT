#ifndef TCPCLIENT1_H
#define TCPCLIENT1_H

#include <QObject>

#include <QTcpSocket>
#include <QCoreApplication>
#include <QDebug>

class TcpClient : public QObject {
    Q_OBJECT
public:
    TcpClient(const QString &host, quint16 port, QObject *parent = nullptr);

    void connectToServer();

protected slots:
    void onConnected();

    void onReadyRead();

    void onDisconnected();

private:
    QTcpSocket* socket;
    QString m_host;
    quint16 m_port;
};

#endif // TCPCLIENT1_H
