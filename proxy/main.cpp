#include <QCoreApplication>
#include <QDebug>
#include <QSocketNotifier>
#include <csignal>
#include "simpleproxy.h"

// 全局变量，用于存储应用程序实例的指针
QCoreApplication* g_coreApp = nullptr;

// SIGINT处理函数
void handleSIGINT(int)
{
    if(g_coreApp)
        g_coreApp->quit();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    g_coreApp = &a;

    // 安装SIGINT处理函数
    std::signal(SIGINT, &handleSIGINT);

    SimpleProxyServer server;
    server.startServer(18080);
    return a.exec();
}
