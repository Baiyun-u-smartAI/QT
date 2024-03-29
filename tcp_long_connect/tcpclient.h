#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>


class TcpClient : public QObject {
    Q_OBJECT
public:
    TcpClient(const QString &host, quint16 port, QObject *parent = nullptr);

    void connectToServer();

protected slots:
    void onConnected();
    void onReadyRead();
private:
    QTcpSocket *socket;
    QString m_host;
    quint16 m_port;
};

#endif // TCPCLIENT_H
