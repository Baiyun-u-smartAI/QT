#ifndef QSENDBROWSER_H
#define QSENDBROWSER_H

#include <QObject>
#include <QWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QKeyEvent>
class QsendBrowser : public QPlainTextEdit
{
    Q_OBJECT



public:
    explicit QsendBrowser(QWidget *parent = nullptr);

signals:
    void send2file();
protected:
    void keyPressEvent ( QKeyEvent * e ) override;
};

#endif // QSENDBROWSER_H
