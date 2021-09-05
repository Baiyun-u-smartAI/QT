#include "reset_thread.h"

reset_thread::reset_thread(QObject *parent) : QObject(parent)
{
    thisLabel=nullptr;
}

void reset_thread::addLabel(QLabel *src){
    this->thisLabel=src;
}


void reset_thread::thisSlot(){
    static bool once = true;
    if (once){
        qDebug()<<"reset Slot ID"<<QThread::currentThreadId();
        once = false;
    }

    if (thisLabel!=nullptr){
        this->thisLabel->setText("0");
    }
}
