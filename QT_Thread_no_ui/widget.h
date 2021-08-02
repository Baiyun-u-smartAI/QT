#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QThread>
#include <QDebug>
#include "thread_obj.h"
#define SingleThread
class Widget : public QWidget
{
    Q_OBJECT
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
#ifndef SingleThread
    QThread *thread;// 用于新建子线程
#endif
    Thread_obj *obj;// 自定义用于独立线程的对象
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void retranslateUi();

};
#endif // WIDGET_H
