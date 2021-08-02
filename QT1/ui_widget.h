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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include <QList>
#include <QStandardItemModel> // 用于生成表格模型
#include <QDateTime> //用于记录时间
#include <QToolTip> //输入框的提示
#include <QTextStream>// 用于读取文件
#include <QDebug>
QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *RegisiterButton;
    QLineEdit *UsrEdit;
    QLineEdit *PwdEdit;
    QLabel *UsrLabel;
    QLabel *PwdLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *PwdLabel_again;
    QSpacerItem *horizontalSpacer;
    QLineEdit *PwdEdit_again;
    QLabel *ResultLabel;
    QList<QString> UsernameGroup;



    QTableView *tableView;// 表格显示注册客户的信息
    QStandardItemModel* model;// 表格模型
    qint16 length;// 注册用户量
    void setupUi(QWidget *Widget)
    {

        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(618, 559);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        RegisiterButton = new QPushButton(Widget);
        RegisiterButton->setObjectName(QString::fromUtf8("RegisiterButton"));
        QFont font;
        font.setPointSize(25);
        RegisiterButton->setFont(font);
        QObject::connect(RegisiterButton,&QPushButton::clicked,[=]{

            if (UsrEdit->text()==""){
                ResultLabel->setText("用户名为空");
            }
            else if (UsrEdit->text().length()<7){
                // UsrEdit提示用户名长度需不小于7
                QToolTip::showText(UsrEdit->mapToGlobal(QPoint())+QPoint(0,UsrEdit->height()/2), "用户名长度需不小于7");

            }
            else if (PwdEdit->text()==""){
                ResultLabel->setText("密码为空");
            }
            else if (PwdEdit->text().length()<8){
                // PwdEdit提示密码长度需不小于8"
                QToolTip::showText(PwdEdit->mapToGlobal(QPoint())+QPoint(0,UsrEdit->height()/2), "密码长度需不小于8");
            }
            else if (PwdEdit_again->text()!=PwdEdit->text()){
                ResultLabel->setText("两次密码不匹配");
            }
            else if (UsernameGroup.indexOf(UsrEdit->text())>=0){
                ResultLabel->setText("用户名已经存在");
            }
            else{

                UsernameGroup.push_back(UsrEdit->text());

                // 更新表格的数据
                model->setItem(length, 1, new QStandardItem(UsrEdit->text()));
                model->setItem(length++, 0, new QStandardItem(QDateTime::currentDateTime().toString("yyyy年MM月dd日 HH时mm分")));

                // 将数据保存到文件中
                this->save(QDateTime::currentDateTime(),UsrEdit->text());

                ResultLabel->setText("注册成功");
                // 清空数据
                UsrEdit->setText("");
                PwdEdit->setText("");
                PwdEdit_again->setText("");
            }
        }

        );
        gridLayout->addWidget(RegisiterButton, 4, 1, 1, 2);

        UsrEdit = new QLineEdit(Widget);
        UsrEdit->setObjectName(QString::fromUtf8("UsrEdit"));
        QFont font1;
        font1.setPointSize(21);
        UsrEdit->setFont(font1);
        UsrEdit->setMaxLength(20);

        gridLayout->addWidget(UsrEdit, 1, 2, 1, 1);

        PwdEdit = new QLineEdit(Widget);
        PwdEdit->setObjectName(QString::fromUtf8("PwdEdit"));
        PwdEdit->setMinimumSize(QSize(0, 44));
        QFont font2;
        font2.setPointSize(10);
        PwdEdit->setFont(font2);
        PwdEdit->setMaxLength(20);
        PwdEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(PwdEdit, 2, 2, 1, 1);

        UsrLabel = new QLabel(Widget);
        UsrLabel->setObjectName(QString::fromUtf8("UsrLabel"));
        UsrLabel->setFont(font1);

        gridLayout->addWidget(UsrLabel, 1, 1, 1, 1);

        PwdLabel = new QLabel(Widget);
        PwdLabel->setObjectName(QString::fromUtf8("PwdLabel"));
        PwdLabel->setFont(font1);

        gridLayout->addWidget(PwdLabel, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 8, 1, 1, 1);

        PwdLabel_again = new QLabel(Widget);
        PwdLabel_again->setObjectName(QString::fromUtf8("PwdLabel_again"));
        PwdLabel_again->setFont(font1);

        gridLayout->addWidget(PwdLabel_again, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        PwdEdit_again = new QLineEdit(Widget);
        PwdEdit_again->setObjectName(QString::fromUtf8("PwdEdit_again"));
        PwdEdit_again->setMinimumSize(QSize(0, 44));
        PwdEdit_again->setFont(font2);
        PwdEdit_again->setMaxLength(20);
        PwdEdit_again->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(PwdEdit_again, 3, 2, 1, 1);

        ResultLabel = new QLabel(Widget);
        ResultLabel->setObjectName(QString::fromUtf8("ResultLabel"));
        ResultLabel->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(ResultLabel, 6, 1, 1, 2);

        model = new QStandardItemModel;   //创建一个标准的表格模型
        model->setHorizontalHeaderItem(0, new QStandardItem("时间") );// 第一列表头是时间
        model->setHorizontalHeaderItem(1, new QStandardItem("用户名") );// 第二轮表头是用户名

        tableView = new QTableView(Widget);
        tableView->setModel(model);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setColumnWidth(0, 250);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


        length=0;
        QFile file("test.data");// 从文件读取用户注册信息
        if (file.open(QIODevice::ReadOnly)){
            // 按行读取
            QTextStream in(&file);
            in.setCodec("UTF-8");
            while (!in.atEnd()){
                QString line = in.readLine();
                QStringList data = line.split(",");// 以逗号为界限分割时间和用户名数据
                model->setItem(length, 1, new QStandardItem(data[1]));
                model->setItem(length, 0, new QStandardItem(QDateTime::fromString(data[0]).toString("yyyy年MM月dd日 HH时mm分")));
                length++;
            }
        }


        gridLayout->addWidget(tableView, 7, 1, 1, 2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        RegisiterButton->setText(QCoreApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        UsrLabel->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        PwdLabel->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", nullptr));
        PwdLabel_again->setText(QCoreApplication::translate("Widget", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232", nullptr));
        ResultLabel->setText("");// 初始值为空
    } // retranslateUi

    // 保存数据到test.data
    void save(QDateTime RegisteTime, QString Username){
        QFile file("test.data");
        file.open(QIODevice::WriteOnly|QIODevice::Append);

        file.write(RegisteTime.toString().toUtf8(),qstrlen(RegisteTime.toString().toUtf8()));// 写入文件test.data时间
        file.write(",",1);
        file.write(Username.toUtf8(),qstrlen(Username.toUtf8()));// 写入文件test.data 用户名
        file.write("\n",1);// 另起一行


        file.close();
    }
};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
