#ifndef WIDGET_H
#define WIDGET_H

#include <QTableWidgetItem>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

    // 创建表格
    QTableWidget *item;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void xml_read();
    void json_read();
};
#endif // WIDGET_H
