#include <QCoreApplication>
#include <QSocketNotifier>
#include <csignal>
#include "reverseproxy.h"
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

    ReverseProxyServer server;

    return a.exec();
}
