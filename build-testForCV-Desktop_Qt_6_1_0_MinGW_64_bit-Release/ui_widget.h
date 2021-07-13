/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
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

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *begin_page;
    QPushButton *beginButton;
    QWidget *page4counting;
    QLabel *number4count;
    QWidget *checkPage;
    QWidget *gridLayoutWidget_2;
    QGridLayout *PageShowGroup;
    QLabel *Random1display;
    QLabel *Random2display;
    QLabel *Random3display;
    QPushButton *enterAns;
    QWidget *page_3;
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

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 800);
        Widget->setMinimumSize(QSize(800, 800));
        Widget->setMaximumSize(QSize(800, 800));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 800));
        begin_page = new QWidget();
        begin_page->setObjectName(QString::fromUtf8("begin_page"));
        beginButton = new QPushButton(begin_page);
        beginButton->setObjectName(QString::fromUtf8("beginButton"));
        beginButton->setGeometry(QRect(190, 450, 381, 71));
        QFont font;
        font.setPointSize(20);
        beginButton->setFont(font);
        beginButton->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 18, 18);\n"
"gridline-color: rgb(60, 255, 0);"));
        stackedWidget->addWidget(begin_page);
        page4counting = new QWidget();
        page4counting->setObjectName(QString::fromUtf8("page4counting"));
        number4count = new QLabel(page4counting);
        number4count->setObjectName(QString::fromUtf8("number4count"));
        number4count->setGeometry(QRect(170, 54, 481, 631));
        stackedWidget->addWidget(page4counting);
        checkPage = new QWidget();
        checkPage->setObjectName(QString::fromUtf8("checkPage"));
        gridLayoutWidget_2 = new QWidget(checkPage);
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

        PageShowGroup->addWidget(enterAns, 1, 1, 1, 1);

        stackedWidget->addWidget(checkPage);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayoutWidget_3 = new QWidget(page_3);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(140, 310, 521, 291));
        EnterAnsGroup = new QGridLayout(gridLayoutWidget_3);
        EnterAnsGroup->setObjectName(QString::fromUtf8("EnterAnsGroup"));
        EnterAnsGroup->setContentsMargins(0, 0, 0, 0);
        ShapeSelect = new QComboBox(gridLayoutWidget_3);
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
        ColorSelect->setObjectName(QString::fromUtf8("ColorSelect"));
        ColorSelect->setFont(font1);

        EnterAnsGroup->addWidget(ColorSelect, 0, 0, 1, 1);

        DisplayRes = new QPushButton(gridLayoutWidget_3);
        DisplayRes->setObjectName(QString::fromUtf8("DisplayRes"));
        QFont font2;
        font2.setPointSize(18);
        DisplayRes->setFont(font2);

        EnterAnsGroup->addWidget(DisplayRes, 1, 0, 1, 2);

        stackedWidget->addWidget(page_3);
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
        LastTime4second->setDigitCount(10);

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
        enterAns->setText(QCoreApplication::translate("Widget", "\347\202\271\345\207\273\350\276\223\345\205\245\347\273\223\346\236\234", nullptr));
        ShapeSelect->setItemText(0, QCoreApplication::translate("Widget", "\342\226\210", nullptr));
        ShapeSelect->setItemText(1, QCoreApplication::translate("Widget", "\342\227\217", nullptr));

        ColorSelect->setItemText(0, QCoreApplication::translate("Widget", "\347\273\277\350\211\262", nullptr));
        ColorSelect->setItemText(1, QCoreApplication::translate("Widget", "\347\272\242\350\211\262", nullptr));
        ColorSelect->setItemText(2, QCoreApplication::translate("Widget", "\350\223\235\350\211\262", nullptr));

        DisplayRes->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244", nullptr));
        LastTimeText->setText(QCoreApplication::translate("Widget", "\350\200\227\346\227\266", nullptr));
        CorrectText->setText(QCoreApplication::translate("Widget", "\345\233\236\347\255\224\346\255\243\347\241\256", nullptr));
        RetryButton->setText(QCoreApplication::translate("Widget", "\345\233\236\347\255\224\351\224\231\350\257\257\357\274\214\347\202\271\345\207\273\351\207\215\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
