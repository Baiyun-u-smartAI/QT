#include "thread_obj.h"

Thread_obj::Thread_obj()
{
}


void Thread_obj::init(QLabel* srcLabel){
    this->label=srcLabel;
}
void Thread_obj::slot()
{
    static quint8 i=0;

    if (!timer){
        // 第一次运行slot函数
        timer = new QTimer;
        timer->setInterval(1000);


        timer->start();
        qDebug()<<"from thread slot:" <<QThread::currentThreadId();
        QObject::connect(timer,&QTimer::timeout,[&]{
            timer->stop();
            if (i==255){
                i=0;
            }
            label->setText(QString::number(i++));
            timer->setInterval(1000);
            timer->start();
        });
    }
    else{
        // 停止循环计时和信号槽函数
        timer->stop();
        timer->disconnect();
    }



}
