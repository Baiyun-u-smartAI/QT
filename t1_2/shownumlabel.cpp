#include "shownumlabel.h"

showNumLabel::showNumLabel(QWidget *parent) : QLabel(parent)
{
    this->setObjectName(QString::fromUtf8("showNum"));
    QFont font;
    font.setPointSize(18);
    this->setFont(font);
    this->setAlignment(Qt::AlignCenter);
    this->setText(QCoreApplication::translate("Widget", "0", nullptr));
    connect(this,SIGNAL(debug_sender(int)),this,SLOT(debug_shower(int)));
}


void showNumLabel::minus_1(bool){
    uint8_t temp =  this->text().toInt();
    this->setText(QString::number(--temp));
    emit debug_sender(temp);
}

void showNumLabel::debug_shower(int n){
    qDebug()<<n;
}
