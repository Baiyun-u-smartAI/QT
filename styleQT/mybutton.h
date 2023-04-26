#ifndef MYBUTTON_H
#define MYBUTTON_H

#define WIDGET_STYLE

#include <QPushButton>
#include <QObject>
#include <QWidget>
#include <QPropertyAnimation>
class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QWidget* parent=nullptr);
    ~MyButton();
    QRect origin;
    QPropertyAnimation *animation;
    bool isOk;
     void setEnabled(bool);
protected:
    void enterEvent(QEvent*) override;
    void resizeEvent(QResizeEvent *event) override;
};

#endif // MYBUTTON_H
