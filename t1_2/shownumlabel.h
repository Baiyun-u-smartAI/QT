#ifndef SHOWNUMLABEL_H
#define SHOWNUMLABEL_H

#include <QWidget>
#include <QtWidgets/QLabel>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QDebug>
class showNumLabel : public QLabel
{
    Q_OBJECT
public:
    explicit showNumLabel(QWidget *parent = nullptr);
signals:
    void debug_sender(int);
public slots:
    void minus_1(bool);
private slots:
    void debug_shower(int);
};

#endif // SHOWNUMLABEL_H
