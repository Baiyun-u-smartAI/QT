#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QThread>
#include "shownumlabel.h"
#include "reset_thread.h"
class Widget : public QWidget
{
    Q_OBJECT

public:

    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void pushbutton_add1(bool);
private:
    QGridLayout *gridLayout;
//    QLabel *showNum;
    showNumLabel *showNum;
    QPushButton *add1;
    QPushButton *minus1;
    QLabel *label_2;
    QPushButton *resetBtn;
    reset_thread *thd;
    QThread *thread;
    void retranslateUi();
};
#endif // WIDGET_H
