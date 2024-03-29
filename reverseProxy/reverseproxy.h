#ifndef REVERSEPROXY_H
#define REVERSEPROXY_H

#include <QObject>

#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>

class ReverseProxyServer : public QTcpServer {
    Q_OBJECT
public:
    ReverseProxyServer(QObject *parent = nullptr);

private slots:
    void onNewConnection();
};



#endif // REVERSEPROXY_H
