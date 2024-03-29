#include "tcpclient1.h"



TcpClient::TcpClient(const QString &host, quint16 port, QObject *parent) : QObject(parent), m_host(host), m_port(port) {
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
}

void TcpClient::connectToServer() {
    socket->connectToHost(m_host, m_port);
}

void TcpClient::onConnected() {
    qDebug() << "Connected to server";
    socket->write("Hello from client");
}

void TcpClient::onReadyRead() {
    QByteArray data = socket->readAll();
    qDebug() << "Received:" << data;
}

void TcpClient::onDisconnected() {
    qDebug() << "Disconnected from server";

}
