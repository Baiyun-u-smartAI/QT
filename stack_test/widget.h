#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtCore/QVariant>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QButtonGroup>
#include <QFont>
#include <QDebug>
#include <QKeyEvent>
#include "page1.h"
#include "page2.h"



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    page1* page;
    page2* nextpage;
//    QWidget* page1;
//    QLabel* label1;
//    QWidget* page0;
//    QLabel* label0;
    QStackedWidget* mainstack;
protected:
public slots:
    void switchpage();
};
#endif // WIDGET_H
