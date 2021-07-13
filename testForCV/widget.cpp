#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
//    this->setWindowOpacity(1);
    //    this->setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{

    delete ui;
}


void Widget::closeEvent(QCloseEvent *event){
    if (this->ui->stackedWidget->currentIndex()!=2)
        event->accept();
    else{
        event->ignore();
        this->ui->stackedWidget->setCurrentIndex(0);
        this->ui->sleepLoop=new QEventLoop;// 重新开启新的延时。
        QTimer::singleShot(1,this->ui->sleepLoop,SLOT(quit()));// 延时1ms
        this->ui->sleepLoop->exec(); // 结束sleepLoop，防止还未结束的循环
        event->accept();
    }

}
