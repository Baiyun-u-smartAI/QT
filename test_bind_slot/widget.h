#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
    QLabel* showL;
    QPushButton * btns[2];
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void changeShow(QString data);
};
#endif // WIDGET_H
