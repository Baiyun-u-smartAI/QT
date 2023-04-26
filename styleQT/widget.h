#ifndef WIDGET_H
#define WIDGET_H

#include "mybutton.h"
#include <QLabel>
#include <QWidget>
#ifndef MYBUTTON_H
#define MyButton QPushButton
#include <QPushButton>
#endif


class Widget : public QWidget
{
    Q_OBJECT
    MyButton* mode[3];
    MyButton* power;
    MyButton* tControl[2];
    QLabel* title[3];
    QLabel* middle;
    QMovie* gif;
    int temperature;
    bool isOn;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *e) override;
private slots:
    void gifControl();
    void changeMode(QString statusText);
    void gifControl(QString id);
public slots:
    void switchPower();
private:
    void init();

};
#endif // WIDGET_H
