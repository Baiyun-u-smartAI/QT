#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
class HttpServer : public QTcpServer
{
    Q_OBJECT
public:
    HttpServer(QObject *parent = nullptr);
    ~HttpServer();
protected:
    void incomingConnection(qintptr socketDescriptor) override;
private slots:
    void onNewConnection();
    void onDataReceived(QTcpSocket *socket) ;

};

#endif // HTTPSERVER_H
