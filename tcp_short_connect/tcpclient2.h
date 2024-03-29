#ifndef TCPCLIENT2_H
#define TCPCLIENT2_H

#include <QTcpSocket>
#include <QCoreApplication>
#include <QDebug>
namespace another {


class TcpClient : public QObject {
    Q_OBJECT
public:
    TcpClient(const QString &host, quint16 port, QObject *parent = nullptr);

    void connectToServer();

protected slots:
    void onConnected();

private:
    QTcpSocket *socket;
    QString m_host;
    quint16 m_port;
};
}
#endif // TCPCLIENT2_H
