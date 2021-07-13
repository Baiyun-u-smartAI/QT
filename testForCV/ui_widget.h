/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
// 用于计时计时
#include <QTimer>
#include <QTime>
#include <QtDebug>
// 绘制和加载svg
#include <QImage>
#include <QPainter>
#include <QSvgRenderer>

// 用于产生随机数
#include <algorithm>
#include <random>
#include <string>
#define NUM 16
QT_BEGIN_NAMESPACE

class Ui_Widget : public QWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *begin_page;
    QPushButton *beginButton;
    QWidget *page4counting;
    QLabel *number4count;
    QWidget *detectPage;
    QWidget *gridLayoutWidget_2;
    QGridLayout *PageShowGroup;
    QLabel *Random1display;
    QLabel *Random2display;
    QLabel *Random3display;
    QPushButton *enterAns;
    QWidget *checkPage;
    QWidget *gridLayoutWidget_3;
    QGridLayout *EnterAnsGroup;
    QComboBox *ShapeSelect;
    QComboBox *ColorSelect;
    QPushButton *DisplayRes;
    QWidget *SucessPage;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *LastTimeText;
    QLCDNumber *LastTime4second;
    QLabel *CorrectText;
    QWidget *WrongPage;
    QPushButton *RetryButton;
    QTimer* timer3s;
    QTime begin,end;
    QPixmap** SvgGrp;
    QPixmap** ShapeGrp;
    int* Ans;
    QEventLoop* sleepLoop;

    void setupUi(QWidget *Widget)
    {
        Widget->move(30,30);
        Widget->setStyleSheet("background-color:");
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 800));
        begin=QTime();// 加载时把begin初始化为null

        // 开始页
        begin_page = new QWidget();
        begin_page->setObjectName(QString::fromUtf8("begin_page"));
        beginButton = new QPushButton(begin_page);
        beginButton->setObjectName(QString::fromUtf8("beginButton"));
        beginButton->setGeometry(QRect(170, 460, 381, 71));

        QFont font;
        font.setPointSize(20);
        beginButton->setFont(font);

        stackedWidget->addWidget(begin_page);
        QObject::connect(beginButton, &QPushButton::clicked, [=]() {
            stackedWidget->setCurrentIndex(1);
            QTime begin3s = QTime::currentTime();
            timer3s = new QTimer;
            timer3s->setInterval(100);
            number4count->setPixmap(*(SvgGrp[0]));
            timer3s->start();
            QObject::connect(timer3s, &QTimer::timeout, [=]() {
                timer3s->stop();
                int last_s = -QTime::currentTime().msecsTo(begin3s);
                if (last_s < 3000){

                    number4count->setPixmap(*(SvgGrp[last_s/1000]));// 显示倒计时 3 2 1
//                    number4count->setPixmap(QPixmap(""));
                    timer3s->setInterval(100);
                    timer3s->start();
                }
                else {
                    if (begin.isNull())
                        begin = QTime::currentTime();// 只记录第一次开始时间
                //    qDebug()<<"begin:"<<begin;
                    stackedWidget->setCurrentIndex(2);// 进入下一页

                }
            });

        });


        // 倒计时页的布局
        page4counting = new QWidget();
        page4counting->setObjectName(QString::fromUtf8("page4counting"));
        number4count = new QLabel(page4counting);
        number4count->setObjectName(QString::fromUtf8("number4count"));
        number4count->setGeometry(QRect(170, 54, 481, 631));

        stackedWidget->addWidget(page4counting);




        // 生成图案的槽函数
        QObject::connect(stackedWidget,&QStackedWidget::currentChanged,[=]() {
            // 如果显示第二页时才执行
            if (stackedWidget->currentIndex() == 2) {
                // 产生答案
                Ans=new int(generator());
                std::vector<uchar> seq(NUM);
                for (unsigned i = 0; i < seq.size(); i++) {
                    seq[i] = uchar(i);
                }
                seq.erase(seq.begin()+*Ans);
                sleepLoop=new QEventLoop;


                int step = 0;//用于设置逐渐递增的延时变量

                while(stackedWidget->currentIndex() == 2) // QTimer计时直至激活的页面不是第二页为止
                {
                    Shuffle(seq);
                    setRandomDisplay(seq, 0);// 显示图案
                    QTimer::singleShot(20+step,sleepLoop,SLOT(quit())); // 逐渐增加的延时
                    sleepLoop->exec();

                    setRandomDisplay(seq, 1);// 显示图案
                    QTimer::singleShot(20+step,sleepLoop,SLOT(quit())); // 逐渐增加的延时
                    sleepLoop->exec();

                    setRandomDisplay(seq, 2);// 显示图案
                    QTimer::singleShot(20+step,sleepLoop,SLOT(quit())); // 逐渐增加的延时
                    sleepLoop->exec();

                    setRandomDisplay(seq, 3);// 显示图案
                    QTimer::singleShot(20+step,sleepLoop,SLOT(quit())); // 逐渐增加的延时
                    sleepLoop->exec();

                    setRandomDisplay(seq, 4);// 显示图案
                    QTimer::singleShot(20+step,sleepLoop,SLOT(quit())); // 逐渐增加的延时
                    sleepLoop->exec();


                    if (step<1000) step+=30;

                }
                delete sleepLoop;

            }

        });

        detectPage = new QWidget();
        detectPage->setObjectName(QString::fromUtf8("detectPage"));
        detectPage->setStyleSheet("background-color:black");
        gridLayoutWidget_2 = new QWidget(detectPage);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 310, 751, 301));
        PageShowGroup = new QGridLayout(gridLayoutWidget_2);
        PageShowGroup->setObjectName(QString::fromUtf8("PageShowGroup"));
        PageShowGroup->setContentsMargins(0, 0, 0, 0);
        Random1display = new QLabel(gridLayoutWidget_2);
        Random1display->setObjectName(QString::fromUtf8("Random1display"));

        PageShowGroup->addWidget(Random1display, 0, 0, 1, 1);

        Random2display = new QLabel(gridLayoutWidget_2);
        Random2display->setObjectName(QString::fromUtf8("Random2display"));

        PageShowGroup->addWidget(Random2display, 0, 1, 1, 1);

        Random3display = new QLabel(gridLayoutWidget_2);
        Random3display->setObjectName(QString::fromUtf8("Random3display"));

        PageShowGroup->addWidget(Random3display, 0, 2, 1, 1);

        enterAns = new QPushButton(gridLayoutWidget_2);
        enterAns->setObjectName(QString::fromUtf8("enterAns"));
        font.setPointSize(25);
        enterAns->setFont(font);
        enterAns->setStyleSheet("background-color: rgb(10,10,10) ; color:pink; ");
        PageShowGroup->addWidget(enterAns, 1, 0, 1, 3);

        stackedWidget->addWidget(detectPage);


        QObject::connect(enterAns, &QPushButton::clicked, [=]() {  
            end=QTime::currentTime();// 记录结束时间点
         //   qDebug()<<"end:"<<end;
            stackedWidget->setCurrentIndex(3);
        });


        // 输入答案页
        checkPage = new QWidget();
        checkPage->setObjectName(QString::fromUtf8("checkPage"));
        gridLayoutWidget_3 = new QWidget(checkPage);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(140, 310, 521, 291));
        EnterAnsGroup = new QGridLayout(gridLayoutWidget_3);
        EnterAnsGroup->setObjectName(QString::fromUtf8("EnterAnsGroup"));
        EnterAnsGroup->setContentsMargins(0, 0, 0, 0);
        ShapeSelect = new QComboBox(gridLayoutWidget_3);
        ShapeSelect->addItem(QString());
        ShapeSelect->addItem(QString());
        ShapeSelect->addItem(QString());
        ShapeSelect->addItem(QString());
        ShapeSelect->setObjectName(QString::fromUtf8("ShapeSelect"));
        QFont font1;
        font1.setPointSize(24);
        ShapeSelect->setFont(font1);

        EnterAnsGroup->addWidget(ShapeSelect, 0, 1, 1, 1);

        ColorSelect = new QComboBox(gridLayoutWidget_3);
        ColorSelect->addItem(QString());
        ColorSelect->addItem(QString());
        ColorSelect->addItem(QString());
        ColorSelect->addItem(QString());
        ColorSelect->setObjectName(QString::fromUtf8("ColorSelect"));
        ColorSelect->setFont(font1);

        EnterAnsGroup->addWidget(ColorSelect, 0, 0, 1, 1);

        DisplayRes = new QPushButton(gridLayoutWidget_3);
        DisplayRes->setObjectName(QString::fromUtf8("DisplayRes"));
        QFont font2;
        font2.setPointSize(18);
        DisplayRes->setFont(font2);

        EnterAnsGroup->addWidget(DisplayRes, 1, 0, 1, 2);

        stackedWidget->addWidget(checkPage);

        QObject::connect(DisplayRes,&QPushButton::clicked,[=]() {
            const int& color_i = ColorSelect->currentIndex();
            const int& shape_i = ShapeSelect->currentIndex();
            if (color_i*4+shape_i==*Ans){
                // 答案正确
                delete Ans;
                stackedWidget->setCurrentIndex(4);
                // 显示耗时
                unsigned last_ms=unsigned(-end.msecsTo(begin));
               // qDebug()<<end.msecsTo(begin);
                LastTime4second->display(QString("%1").arg(last_ms/1000,6,10,QChar('0'))+"."
                                         +QString("%1").arg(last_ms%1000,3,10,QChar('0')));
                sleepLoop=new QEventLoop;
                QTimer::singleShot(10000,sleepLoop,SLOT(quit()));// 延时10s
                sleepLoop->exec(); // 结束sleepLoop，防止还未结束的循环
                Widget->close();// 退出
            }else {
                delete Ans;
                // 答错了 请重新答
                stackedWidget->setCurrentIndex(5);
            }
        });



        SucessPage = new QWidget();
        SucessPage->setObjectName(QString::fromUtf8("SucessPage"));
        gridLayoutWidget_4 = new QWidget(SucessPage);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(110, 120, 571, 361));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        LastTimeText = new QLabel(gridLayoutWidget_4);
        LastTimeText->setObjectName(QString::fromUtf8("LastTimeText"));
        QFont font3;
        font3.setPointSize(30);
        LastTimeText->setFont(font3);

        gridLayout_4->addWidget(LastTimeText, 1, 0, 1, 1);

        LastTime4second = new QLCDNumber(gridLayoutWidget_4);
        LastTime4second->setObjectName(QString::fromUtf8("LastTime4second"));
        LastTime4second->setDigitCount(10);//显示十位数据

        gridLayout_4->addWidget(LastTime4second, 1, 1, 1, 4);

        CorrectText = new QLabel(gridLayoutWidget_4);
        CorrectText->setObjectName(QString::fromUtf8("CorrectText"));
        CorrectText->setFont(font3);

        gridLayout_4->addWidget(CorrectText, 0, 0, 1, 5);

        stackedWidget->addWidget(SucessPage);





        WrongPage = new QWidget();
        WrongPage->setObjectName(QString::fromUtf8("WrongPage"));
        RetryButton = new QPushButton(WrongPage);
        RetryButton->setObjectName(QString::fromUtf8("RetryButton"));
        RetryButton->setGeometry(QRect(170, 530, 401, 61));
        RetryButton->setFont(font2);
        RetryButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        stackedWidget->addWidget(WrongPage);

        QObject::connect(RetryButton, &QPushButton::clicked, [=]() {
            // 点击重试后发送开始信号，重新开始计时
           emit beginButton->clicked();// 发送信号，重新倒计时
  /*        stackedWidget->setCurrentIndex(1);
            QTime begin3s = QTime::currentTime();
            timer3s = new QTimer;
            timer3s->setInterval(100);
            number4count->setPixmap(*(SvgGrp[0]));
            timer3s->start();
            QObject::connect(timer3s, &QTimer::timeout, [=]() {
                timer3s->stop();
                int last_s = -QTime::currentTime().msecsTo(begin3s);
                if (last_s < 3000){

                    number4count->setPixmap(*(SvgGrp[last_s/1000]));
                    timer3s->setInterval(100);
                    timer3s->start();
                }
                else {
                    stackedWidget->setCurrentIndex(2);
                    QList<QMetaObject::Connection> connections;
                    connections<<stackConnect;
                }
            });*/
        });




        Imageinit();

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        beginButton->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        number4count->setText(QString());
        Random1display->setText(QString());
        Random2display->setText(QString());
        Random3display->setText(QString());
        enterAns->setText(QCoreApplication::translate("Widget", "点击输入没出现的颜色/图案 禁止退出", nullptr));
        ShapeSelect->setItemText(0, QCoreApplication::translate("Widget", "\342\226\210", nullptr));
        ShapeSelect->setItemText(1, QCoreApplication::translate("Widget", "\342\227\217", nullptr));
        ShapeSelect->setItemText(2, QCoreApplication::translate("Widget", "\xE2\x96\xBC", nullptr));
        ShapeSelect->setItemText(3, QCoreApplication::translate("Widget", "\xE2\x9C\x9A", nullptr));
        ColorSelect->setItemText(0, QCoreApplication::translate("Widget", "\347\273\277\350\211\262", nullptr));
        ColorSelect->setItemText(1, QCoreApplication::translate("Widget", "\347\272\242\350\211\262", nullptr));
        ColorSelect->setItemText(3, QCoreApplication::translate("Widget", "\350\223\235\350\211\262", nullptr));
        ColorSelect->setItemText(2, QCoreApplication::translate("Widget", "\xE9\xBB\x84\350\211\262", nullptr));
        DisplayRes->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244", nullptr));
        LastTimeText->setText(QCoreApplication::translate("Widget", "\350\200\227\346\227\266", nullptr));
        CorrectText->setText(QCoreApplication::translate("Widget", "\345\233\236\347\255\224\346\255\243\347\241\256", nullptr));
        RetryButton->setText(QCoreApplication::translate("Widget", "\345\233\236\347\255\224\351\224\231\350\257\257\357\274\214\347\202\271\345\207\273\351\207\215\350\257\225", nullptr));
    } // retranslateUi

    int generator(int size=NUM){
        //srand(QTime::currentTime().msec());

        std::mt19937 engine{static_cast<long unsigned int>(QTime::currentTime().second()*1000+QTime::currentTime().msec())};
        static std::uniform_int_distribution<int> distr(0,size-1);
        return distr(engine);
    }

    // 初始化SvgGrp和ShapeGrp
    void Imageinit(){
        SvgGrp = new QPixmap*[3];
        for(int i = 0; i < 3; i++){
            if (i==2) {
                SvgGrp[i]=new QPixmap(QSize(301, 631));
                continue;
            }
            SvgGrp[i]=new QPixmap(QSize(451, 631));
        }

        {
            QSvgRenderer renderer(QString(":/new/svg/3.svg"));

            QPainter painter;// 创建画笔
            SvgGrp[0]->fill(Qt::transparent);//底色透明
            // 开始绘制
            painter.begin(SvgGrp[0]);
            renderer.render(&painter);
            painter.end();//结束绘制
        }

        {
            QSvgRenderer renderer(QString(":/new/svg/2.svg"));

            QPainter painter;// 创建画笔
            SvgGrp[1]->fill(Qt::transparent);//底色透明
            // 开始绘制
            painter.begin(SvgGrp[1]);
            renderer.render(&painter);
            painter.end();//结束绘制
        }

        {
            QSvgRenderer renderer(QString(":/new/svg/1.svg"));

            QPainter painter;// 创建画笔
            SvgGrp[2]->fill(Qt::transparent);//底色透明
            // 开始绘制
            painter.begin(SvgGrp[2]);
            renderer.render(&painter);
            painter.end();//结束绘制
        }

        ShapeGrp = new QPixmap*[16];
        for(int i =0; i<16; i++){
            ShapeGrp[i]=new QPixmap(QSize(200, 200));
        }

        for (int i = 0; i < 16; i++) {
            QSvgRenderer renderer(QString(":/new/svg/b"+QString::number(i)+".svg"));

            QPainter painter;// 创建画笔
            ShapeGrp[i]->fill(Qt::transparent);//底色透明
            // 开始绘制
            painter.begin(ShapeGrp[i]);
            renderer.render(&painter);
            painter.end();//结束绘制
        }

    }


    // 随机显示颜色与图案的函数
    void setRandomDisplay(std::vector<uchar> src,unsigned id){
        unsigned i = 3*id;
        while(  i<3*(id+1) ){
            Random1display->setPixmap(*ShapeGrp[src[i]]);
            i++;

            if (i>=src.size()) Random2display->setPixmap(QPixmap(""));// 如果访问越界就显示空白
            else Random2display->setPixmap(*ShapeGrp[src[i]]);
            i++;

            if (i>=src.size()) Random3display->setPixmap(QPixmap(""));// 如果访问越界就显示空白
            else Random3display->setPixmap(*ShapeGrp[src[i]]);
            i++;
        }
    }

    // 打乱数组序列函数
    void Shuffle(std::vector<uchar>& src){

        static std::mt19937 engine{static_cast<long unsigned int>(QTime::currentTime().second()*1000+QTime::currentTime().msec())};

        std::shuffle(src.begin(),src.end(),engine);

    }

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
