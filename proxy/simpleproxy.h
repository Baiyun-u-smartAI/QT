#ifndef SIMPLEPROXY_H
#define SIMPLEPROXY_H

#include <QObject>

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class SimpleProxyServer : public QTcpServer {
    Q_OBJECT
public:
    SimpleProxyServer(QObject *parent = nullptr);

    void startServer(quint16 port);

private slots:
    void onNewConnection();
};

#endif // SIMPLEPROXY_H
