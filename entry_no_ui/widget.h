#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QRegExpValidator>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>
// 延时的宏
#define DELAY(interval,Func) QTimer::singleShot(interval,this,SLOT(Func()))

class Widget;
// 为了覆盖按键事件 定义一个继承QLineEdit的对象 作为新的控件
class QLineEdit_2: public QLineEdit{
    Widget* parent;
public:
    QLineEdit_2(Widget*);
protected:
    void keyPressEvent(QKeyEvent *);
    void contextMenuEvent(QContextMenuEvent *);
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    friend class QLineEdit_2;
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;


    QLineEdit_2 *lineEdit;

    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QMetaObject::Connection connection1;
    void retranslateUi();
    void delay(unsigned interval,std::function<void(void)>);


public slots:
    void release();
    void change2red(const QString &);
    void show_answer();
    void button_clicked_activated(bool);

};





#endif // WIDGET_H
