#include "sensorclient.h"

SensorClient::SensorClient(QObject *parent)
    : QObject{parent}
{
    manager = new QNetworkAccessManager(this);

    // 设置定时器定期请求数据
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(fetchData()));
    timer->start(100); // 设置更新频率，例如每100ms更新一次

}

SensorClient::~SensorClient()
{

}

void SensorClient::fetchData()
{
    QNetworkRequest request;
    // 假设传感器数据可通过以下URL获取
    request.setUrl(QUrl("http://192.168.1.99:8000/data"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, &SensorClient::onDataReceived);
}

void SensorClient::onDataReceived()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        // 解析接收到的数据
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
        QJsonObject jsonObject = jsonResponse.object();
        // 输出全部内容
        // qDebug() << "Response: " << jsonObject; // QJsonObject({"accel_x":0.1060476266188437,"accel_y":0.25153057400393997,"accel_z":0.5895850067024462,"timestamp":1708331781.6169848})
        // 分别提取accel_x...数据到列表data4emit
        QList<float> data4emit;
        data4emit.append(jsonObject["accel_x"].toDouble());
        data4emit.append(jsonObject["accel_y"].toDouble());
        data4emit.append(jsonObject["accel_z"].toDouble());
        emit dataUpdated(data4emit);

    } else {
        // 处理错误
        qDebug() << "Error: " << reply->errorString();
    }
    reply->deleteLater();
}
