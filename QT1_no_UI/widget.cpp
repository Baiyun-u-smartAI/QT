#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    this->setWindowOpacity(1);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->resize(637, 109);
    this->setStyleSheet("QProgressBar {border: 3px solid blue;}");
    unlock = false;
    progressBar = new QProgressBar(this);
    progressBar->setObjectName(QString::fromUtf8("progressBar"));
    progressBar->setGeometry(QRect(70, 30, 431, 31));

    progressBar->setMinimum(0);
    progressBar->setMaximum(10000);
    progressBar->setValue(10000);
    progressBar->setFormat("");


    begin=QTime::currentTime();
    set=begin.addSecs(LAST_TIME);
    timer = new QTimer(this);
    timer->setInterval(100);
    timer->start();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(change_progressBar()));
    retranslateUi();

    QMetaObject::connectSlotsByName(this);
}

Widget::~Widget()
{

}



void Widget::retranslateUi()
{
    this->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
} // retranslateUi

//鼠标按下
void Widget::mousePressEvent(QMouseEvent *e)
{
    last = new QPoint;
    *last = e->globalPos();
}

//鼠标移动
void Widget::mouseMoveEvent(QMouseEvent *e)
{

    int dx = e->globalX() - last->x();
    int dy = e->globalY() - last->y();
    *last = e->globalPos();
    move(x()+dx,y()+dy);
}

void Widget::change_progressBar(){
    timer->stop();
    if (QTime::currentTime()<set){
        int last_s=QTime::currentTime().msecsTo(begin);
        progressBar->setValue(10000+int((last_s+.0)/LAST_TIME*10) );
    }
    else{
        progressBar->setValue(0);
        //const QTime& a=QTime::currentTime();
        //qDebug()<<a.hour()<<":"<<a.minute()<<":"<<a.second();
        FinishedInfo = new QMessageBox();
        this->FinishedInfo->setWindowFlags(Qt::WindowTitleHint|Qt::WindowStaysOnTopHint);
        this->FinishedInfo->warning(this->FinishedInfo,QString("TimeUp"),QString("Have to relax!"),QMessageBox::Ok,QMessageBox::NoButton);
        this->FinishedInfo->raise();
        begin=QTime::currentTime();
        set=begin.addSecs(LAST_TIME);
    }
    timer->setInterval(100);
    timer->start();
}

void Widget::closeEvent (QCloseEvent *e){
    // 默认unlock的值为false，所以不能关闭界面
    if ( !unlock ){
        qDebug()<<"cannot close";
        e->ignore();//忽略关闭事件
    }
    else
       QWidget::closeEvent(e);
}

void Widget::keyPressEvent(QKeyEvent *event){
    //按下esc后，unlock为真，关闭事件将恢复正常
    if ( event->key()==Qt::Key_Escape){
        unlock = true;
        this->close();//发送关闭事件，实现退出
    }
}
