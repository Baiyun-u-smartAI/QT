#include "widget.h"
#include "ui_widget.h"
// 正则表达式
#include <QRegExp>
#include <QRegularExpression>
#include <QDebug>
#include <QRegularExpressionMatch>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置spinbox作为翻页
    ui->spinBox->setMaximum(ui->stackedWidget->count()-1);
    ui->spinBox->setMinimum(0);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_qqmail_input_textChanged(const QString &arg1)
{
    static QString output;
    output.clear();

    // 1. 用正则表达式匹配
    // 判断arg1里面是否以"@qq.com"结尾 （正则匹配）
    QRegExp rx("^[0-9a-zA-Z]+@qq\\.com$");
    //  如果不是以@qq.com结尾,则output输出邮箱格式错误
    if(!rx.exactMatch(arg1))
    {
        output = "邮箱格式错误";
    }

    // 2. 用正则表达式搜索
    // 使用正则表达式搜索多个邮箱，分别以@qq.com结尾的
    QRegExp rx2("[0-9a-zA-Z]+@qq\\.com");
    QStringList search_result;

    int pos = 0;
    while((pos = rx2.indexIn(arg1, pos)) != -1)// 从pos开始搜索，如果结果为-1，说明没有找到
    {
        search_result << rx2.cap(0);// cap(0)表示匹配的整个字符串，<< 表示把匹配的字符串放到search_result里面
        pos += rx2.matchedLength();// 更新pos的值
    }

    if(search_result.size() > 0)
    {
        output.clear();
        output = "找到了" + QString::number(search_result.size()) + "个邮箱：\n";
        // 针对每一个search_result使用正则表达式，进行文本替换，把@qq.com删除
        for(auto &email : search_result)
        {
            email.replace(QRegExp("@qq\\.com"),"");// 替换
        }
        output += "用户名是";
        for(int i = 0; i < search_result.size(); i++)
        {
            output += search_result[i] + " ";
        }
    }

    ui->qqmail_output->setText(output); // 设置输出框的文字
}


void Widget::on_id_input_textChanged(const QString &arg1)
{
    // 用正则表达式匹配18位身份证号，最后一位可为X，其他均为数字
    QRegExp rx("^[0-9]{17}[0-9X]$");
    static QString output;
    output.clear();
    if(!rx.exactMatch(arg1))
    {
        output = "身份证格式错误";
    }
    // 将arg1的内容分成3个捕获组，分别是前6位数字，中间8位数字，最后4位数字
    QRegExp rx2("^(\\d{6})(\\d{8})(\\d{3}.+)$");
    QString bornDate;
    if (rx2.indexIn(arg1) != -1)
    {
        bornDate = rx2.cap(2);
        output += "出生日期是" + bornDate.left(4) + "年" + bornDate.mid(4,2).replace(QRegExp("^0"), "") + "月" + bornDate.right(2).replace(QRegExp("^0"), "") + "日\n";
        // 将bornDate的内容分成2部分，第一部分是前4位数字（非捕获组），第二部分是后4位数字
        QRegExp rx3("^(?:\\d{4})(\\d{4})$");
        // 将第一个捕获组内容删掉，只保留第二个捕获组内容（现在是唯一的捕获组）
        bornDate.replace(rx3,"\\1");
        QRegExp Aries("\\b(03(2[1-9]|3[0-1]))|(04(0[1-9]|1[0-9]|20))\\b");
        if (Aries.exactMatch(bornDate))
        {
            output += "白羊座";
        }
    }

    ui->id_output->setText(output);
}




void Widget::on_run_clicked()
{
    QString text = ui->textEdit->toPlainText();
    // 正则表达式匹配1到3个汉字长度的重复词
    QRegExp re("([\u4e00-\u9fa5]{1,3})\\1");

    qDebug() << "原文:" << text;
    int length_bf = text.length();
    int length_aft = 0;
    while (length_aft!= length_bf)
    {
        length_bf = text.length();
        // 替换所有匹配的重复词为单个词
        text.replace(re, "\\1");// 去重一次
        length_aft = text.length();
    }
    qDebug() << "修改后:" << text;
    ui->text_result->setText(text);
}

