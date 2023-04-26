#include "widget.h"
#ifdef WIDGET_STYLE
#include <QJsonArray>
#include <QJsonParseError>
#include <QMovie>
#include <QPainter>
#include <QDebug>
#include <QFile>
void Widget::paintEvent(QPaintEvent*)
{
    static QPixmap bg(":/wallpaper/ai2023_geometric_border_with_background_dark_and_blue_abstract__e668a276-c42e-404d-8d42-cf12bf94cf86.png");
    QPainter painter(this);
    painter.drawPixmap(this->rect(), bg);
}

void Widget::init()
{
    /* 原始测试
    //    resize(860, 640);

    //    setStyleSheet("font-size: 60px");
    //    title[0]->setText("Temperature Control System");
    //    title[0]->setGeometry(10, 10, 840, 62);
    //    title[1]->setText("Mode: OFF");
    //    title[1]->setGeometry(10, 88, 840, 62);
    //    title[2]->setText("Temperature: 25");
    //    title[2]->setGeometry(10, 168, 840, 62);


    //    middle->setGeometry(10, 240, 840, 120);
    //    middle->setAlignment(Qt::AlignmentFlag::AlignCenter);
    //    gif = new QMovie(QLatin1String(":/wallpaper/ezgif.com-gif-maker.gif"), QByteArray(), this);
    //    middle->setMovie(gif); // 应用gif图
    //    gif->start();

    //    power->setGeometry(10, 360, 840, 62);
    //    power->setText("On/Off");

    //    mode[0]->setGeometry(10, 432, 270, 62);
    //    mode[0]->setText("Air-blow");
    //    mode[1]->setGeometry(295, 432, 270, 62);
    //    mode[1]->setText("Heat");
    //    mode[2]->setGeometry(580, 432, 270, 62);
    //    mode[2]->setText("Cool");

    //    tControl[0]->setGeometry(10, 544, 415, 62);
    //    tControl[0]->setText("+");
    //    tControl[1]->setGeometry(435, 544, 415, 62);
    //    tControl[1]->setText("-");
    */


    // 读文件
    QFile json(":/var/var.json");
    if (!json.open(QFile::ReadOnly)) {
            qWarning("Couldn't open json file.");
            return;
    }
    QByteArray data = json.readAll();
    QJsonParseError err;
    QJsonDocument json_doc = QJsonDocument::fromJson(data, &err);
    if (json_doc.isNull()) {
        qDebug() << err.errorString();
        return;
    }

    // 转成QJson对象
    QJsonObject echo_info = json_doc.object();

    if (echo_info.contains("app-name") && echo_info["app-name"].isString() )
    {
        this->setWindowTitle(echo_info["app-name"].toString());
    }

    // 设置大小
    if (echo_info.contains("size") && echo_info["size"].isArray() )
    {
        QJsonArray main_size_array = echo_info["size"].toArray();
        this->resize(main_size_array[0].toInt(), main_size_array[1].toInt());
        this->setMaximumSize(this->size());
        this->setMinimumSize(this->size());
    }

    // 设置全局样式
    if (echo_info.contains("style") && echo_info["style"].isString() )
    {
        this->setStyleSheet(echo_info["style"].toString());
    }

    // 设置label显示的颜色
    if (echo_info.contains("label-style") && echo_info["label-style"].isString() )
    {
        for (auto& i: this->title)
        {
            i->setStyleSheet(echo_info["label-style"].toString());
        }
    }

    // 设置标题前三行
    if (echo_info.contains("title") && echo_info["title"].isArray() )
    {
        QJsonArray title_array = echo_info["title"].toArray();
        for (int i = 0; i < title_array.size(); i++)
        {
            const auto& rect = title_array[i].toObject()["geometry"].toArray();
//            qDebug()<<title_array[i].toObject()["geometry"].toArray();
            this->title[i]->setText(title_array[i].toObject()["text"].toString());
            this->title[i]->setGeometry(rect[0].toInt(), rect[1].toInt(), rect[2].toInt(), rect[3].toInt());
            this->title[i]->setObjectName(QString("title_") + QString::number(i));
        }
    }

    // 设置gif动画
    if (echo_info.contains("gif") && echo_info["gif"].isObject() )
    {
        const auto& rect = echo_info["gif"].toObject()["geometry"].toArray();
        this->middle->setGeometry(rect[0].toInt(), rect[1].toInt(), rect[2].toInt(), rect[3].toInt());
        this->middle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        this->gif = new QMovie(echo_info["gif"].toObject()["url"].toString(), QByteArray(), this);
        this->middle->setMovie(gif); // 应用gif图
        this->gif->start(); // 载入动画，并播放
        this->gif->setPaused(true); // 暂停动画
//        this->gif->setSpeed(100);
    }



    if (echo_info.contains("button") && echo_info["button"].isArray() )
    {
        QJsonArray button_info = echo_info["button"].toArray();

        // 设置power按钮
        if (button_info[0].toObject().contains("power") && button_info[0].toObject()["power"].isObject() )
        {
            QJsonObject power_info = button_info[0].toObject()["power"].toObject();
            const auto& rect = power_info["geometry"].toArray();
            this->power->setGeometry(rect[0].toInt(), rect[1].toInt(), rect[2].toInt(), rect[3].toInt());
            this->power->setText(power_info["text"].toString());
            this->power->setObjectName("power_btn");
        }

        // 设置mode按钮
        if (button_info[1].toObject().contains("mode") && button_info[1].toObject()["mode"].isArray() )
        {
            QJsonArray mode_info = button_info[1].toObject()["mode"].toArray();
            for (int i = 0; i < mode_info.size(); i++)
            {
                const auto& rect = mode_info[i].toObject()["geometry"].toArray();
                this->mode[i]->setGeometry(rect[0].toInt(), rect[1].toInt(), rect[2].toInt(), rect[3].toInt());
                this->mode[i]->setText(mode_info[i].toObject()["text"].toString());
                this->mode[i]->setObjectName(QString("mode_btn_") + QString::number(i));
            }
        }

        // 设置tControl按钮
        if (button_info[2].toObject().contains("tControl") && button_info[2].toObject()["tControl"].isArray() )
        {
            QJsonArray tControl_info = button_info[2].toObject()["tControl"].toArray();
            for (int i = 0; i < tControl_info.size(); i++)
            {
                const auto& rect = tControl_info[i].toObject()["geometry"].toArray();
                this->tControl[i]->setGeometry(rect[0].toInt(), rect[1].toInt(), rect[2].toInt(), rect[3].toInt());
                this->tControl[i]->setText(tControl_info[i].toObject()["text"].toString());
                this->tControl[i]->setObjectName(QString("tControl_btn_") + QString::number(i));
            }
        }

    }
    json.close();
}

void Widget::gifControl()
{
    if (this->gif->isValid())
    {
        if (this->title[1]->text().indexOf("OFF") < 0) // 如果正在播放
        {
            this->gif->setPaused(true); // 暂停动画
            this->gif->setSpeed(100);
        }
        else
        {
            this->gif->setPaused(false); // 继续播放
        }
    }
}

void Widget::gifControl(QString id)
{
    if (id == "tControl_btn_0" && this->title[1]->text().indexOf("Cool") > 0)
    {
        this->gif->setSpeed(this->gif->speed()*0.88);
    }
    else if (id == "tControl_btn_1" && this->title[1]->text().indexOf("Cool") > 0)
    {
        this->gif->setSpeed(this->gif->speed()/0.88);
    }
    if (id == "tControl_btn_0" && this->title[1]->text().indexOf("Heat") > 0)
    {
        this->gif->setSpeed(this->gif->speed()/0.88);
    }
    else if (id == "tControl_btn_1" && this->title[1]->text().indexOf("Heat") > 0)
    {
        this->gif->setSpeed(this->gif->speed()*0.88);
    }
}



#endif
