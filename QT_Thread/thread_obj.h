#ifndef THREAD_OBJ_H
#define THREAD_OBJ_H
#include <QObject>
#include <QtWidgets/QLabel>
#include <QThread>
#include <QDebug>
#include <QTimer>
class Thread_obj :public QObject {
    Q_OBJECT
public:
    Thread_obj();
    void init(QLabel* srcLabel);// 加载要修改的label地址
public slots:
    void slot();

private:
    QLabel* label;// 需要激活改变的对象地址
    QTimer* timer;// 用于定时
};

#endif // THREAD_OBJ_H
