#ifndef SENSORCLIENT_H
#define SENSORCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
class SensorClient : public QObject
{
    Q_OBJECT
public:
    explicit SensorClient(QObject *parent = nullptr);
    ~SensorClient();
signals:
    void dataUpdated(const QList<float> &data);
public slots:
    void fetchData();
    void onDataReceived();
private:
    QNetworkAccessManager *manager;
};

#endif // SENSORCLIENT_H
