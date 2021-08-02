#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "page1.h"
#include "page2.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QDebug>
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    page1* W_page1;
    page2* W_page2;
    QStackedWidget* mainstack;

};

#endif // WIDGET_H
