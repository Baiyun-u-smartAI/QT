#include "widget.h"

#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 600);
    setStyleSheet("font-size: 40px");
    QGridLayout* grid = new QGridLayout(this);
    this->setLayout(grid);
    showL = new QLabel(this);
    grid->addWidget(showL, 0, 0);

    for (auto& i : btns){
        static int pos = 1;
        i = new QPushButton(this);
        grid->addWidget(i, pos++, 0);
    }

    const QString data[2]{"1", "2"};

    for (int i = 0; i < 2; i++){
        this->btns[i]->setText(data[i]);
        this->connect(btns[i], &QPushButton::clicked, this, std::bind(&Widget::changeShow, this, btns[i]->text()));
    }


}

Widget::~Widget()
{
}

void Widget::changeShow(QString data)
{
    this->showL->setText(data);
}
