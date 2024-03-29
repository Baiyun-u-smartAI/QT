#ifndef SIMPLEHTTPPROXY_H
#define SIMPLEHTTPPROXY_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class SimpleHttpProxy : public QObject {
    Q_OBJECT
public:
    SimpleHttpProxy(QObject *parent = nullptr);

private slots:
    void onNewConnection();

private:
    QTcpServer server;
    QNetworkAccessManager manager;
};



#endif // SIMPLEHTTPPROXY_H
