#ifndef RESET_THREAD_H
#define RESET_THREAD_H

#include <QObject>
#include <QtWidgets/QLabel>
#include <QDebug>
#include <QThread>
class reset_thread : public QObject
{
    Q_OBJECT
public:
    explicit reset_thread(QObject *parent = nullptr);
    void addLabel(QLabel*);
signals:

public slots:
    void thisSlot();

private:
    QLabel* thisLabel;
};

#endif // RESET_THREAD_H
