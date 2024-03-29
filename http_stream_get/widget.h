#ifndef WIDGET_H
#define WIDGET_H

#include "httpserver.h"
#include "sensorclient.h"

#include <QLabel>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
    SensorClient *sensorClient;
    HttpServer *httpServer;
    QLabel* labels[3];
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void onDataUpdated(const QList<float> &data);
};
#endif // WIDGET_H
