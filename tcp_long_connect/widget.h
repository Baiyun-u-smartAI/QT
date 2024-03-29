#ifndef WIDGET_H
#define WIDGET_H

#include "tcpclient.h"
#include "tcpserver.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_openServer_clicked();

    void on_connect_clicked();

    void on_closeServer_clicked();

private:
    Ui::Widget *ui;
    TcpServer *server;
    TcpClient *client;

};
#endif // WIDGET_H
