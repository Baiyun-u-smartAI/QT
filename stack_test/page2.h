#ifndef PAGE2_H
#define PAGE2_H
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtCore/QVariant>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QButtonGroup>
#include <QFont>
#include <QDebug>
#include <QKeyEvent>

class page2 : public QWidget
{
    Q_OBJECT
public:
    friend class Widget;
    explicit page2(QWidget *parent = nullptr);
    ~page2();
private:
    QPushButton *pushButton;
    QMessageBox *ButtonChangedInfo;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QButtonGroup *group1;
    void retranslateUi();
public slots:
    void changeName(bool);/*{
        this->pushButton->setText("no haha");
        this->pushButton->resize(QString("no haha").size()*this->pushButton->font().weight()/3,this->pushButton->height());
        this->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
    }*/
    void showid(int);
protected:
    void keyPressEvent(QKeyEvent *);

};

#endif // PAGE2_H
