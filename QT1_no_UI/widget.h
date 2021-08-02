#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QtDebug>
#include <QMessageBox>
#include <QPoint>
#include <QMouseEvent>  //引用鼠标类头文件
#include <QCloseEvent>
#include <QKeyEvent>
#define LAST_TIME (30*60)

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QProgressBar *progressBar;
    QTimer* timer;
    QMessageBox *FinishedInfo;
    QTime set;
    QTime begin;
    QPoint* last;
    bool unlock;
    void retranslateUi();
protected:
    //鼠标按下
    void mousePressEvent(QMouseEvent *e);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *e);

    void closeEvent (QCloseEvent *e);

    void keyPressEvent(QKeyEvent *event);
private slots:
    void change_progressBar();
};
#endif // WIDGET_H
