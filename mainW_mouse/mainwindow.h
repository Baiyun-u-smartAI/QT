#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QLabel* mouseLabel; // statusbar 显示鼠标位置的控件
    QLabel* keyLabel; // statusbar 显示鼠标位置的控件
    QLabel* centralLabel;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
};
#endif // MAINWINDOW_H
