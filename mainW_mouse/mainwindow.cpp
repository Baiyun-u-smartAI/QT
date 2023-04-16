#include "mainwindow.h"
#include <QMouseEvent>
#include <QStatusBar>
#include <QWheelEvent>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QTime>
#include <QDragEnterEvent>
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mouseLabel = new QLabel(this);
    keyLabel = new QLabel(this);
    centralLabel = new QLabel(this);
    centralLabel->setFont(QFont("", 22));
    centralLabel->setMouseTracking(true); // CentralWidget的mouseMoveEvent不在单击的时候触发
    centralLabel->setAcceptDrops(true);//CentralWidget接受拖拽

    this->setCentralWidget(centralLabel);
    QStatusBar* statusBar = new QStatusBar(this);

    statusBar->addWidget(mouseLabel); // 设置statusbar的mouseLabel
    statusBar->addWidget(keyLabel); // 设置statusbar的keyLabel
    this->setStatusBar(statusBar);
    this->statusBar()->show();
    this->setMouseTracking(true);// mouseMoveEvent不在单击的时候触发
    this->setAcceptDrops(true);//主窗口接受拖拽

}

MainWindow::~MainWindow()
{
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // 更新statusBar
    this->mouseLabel->setText(QString::number(event->pos().x())+"," + QString::number(event->pos().y()));
}



void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0) // 如果滑轮向上，放大
        this->resize(this->size()*1.01);
    else // 如果滑轮向下，缩小
        this->resize(this->size()*0.99);
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    this->keyLabel->clear();
    if(event->modifiers() & Qt::ControlModifier)
        this->keyLabel->setText("Control+");
    else if (event->modifiers() & Qt::AltModifier)
        this->keyLabel->setText("Alt+");
//    else if (event->modifiers() & Qt::ShiftModifier)
//        this->keyLabel->setText("Shift+");
    this->keyLabel->setText(this->keyLabel->text() + QKeySequence(event->key()).toString());
}

// 左右键、中键
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        setStyleSheet("background-color: lightblue");
    if (event->button() == Qt::RightButton)
    {
        setStyleSheet("");

    }
}

// 改变界面的任何显示会触发，或者手动调用update()会触发
void MainWindow::paintEvent(QPaintEvent*)
{
    qDebug()<<QTime::currentTime().msecsSinceStartOfDay()<<"  已经重新绘制";
}


void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    this->centralLabel->setText( event->mimeData()->urls().first().toLocalFile() );

}

// 鼠标离开界面会触发
void MainWindow::leaveEvent(QEvent *event)
{
    this->centralLabel->clear();
}
