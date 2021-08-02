#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(606, 69);
    // 不允许缩放窗口
    this->setMinimumHeight(69);
    this->setMaximumHeight(69);

    // 横式布局
    this->horizontalLayout_2 = new QHBoxLayout;
    this->horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    this->horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

    // horizontalLayout_2自适应窗口调整大小
    this->setLayout(horizontalLayout_2);

    // 新建输入框标题“密码”的标签
    this->label = new QLabel;
    this->label->setObjectName(QString::fromUtf8("label"));

    // 调整字体
    {
        QFont font;
        font.setPointSize(15);
        this->label->setFont(font);
    }

    this->horizontalLayout_2->addWidget(this->label);

    //纵式布局
    this->verticalLayout_3 = new QVBoxLayout;
    this->verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

    // 输入框
    this->lineEdit = new QLineEdit_2(this);
    this->lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    this->lineEdit->setMaxLength(9);// 最多可输入9个字符

    this->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,}"),this->lineEdit));// 输入的内容要匹配正则 [0-9]{0,}



    this->verticalLayout_3->addWidget(this->lineEdit); //在 verticalLayout_3 生成输入框

    this->horizontalLayout_4 = new QHBoxLayout;
    this->horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

    // 空白区域 高固定 宽自动延伸
    this->horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    this->horizontalLayout_4->addItem(this->horizontalSpacer);

    // 创建按钮
    this->pushButton = new QPushButton;
    this->pushButton->setObjectName(QString::fromUtf8("pushButton"));


    // 动作1：只要输入有改变 就lineEdit就变红 并隐藏输入内容
    this->connection1 = QObject::connect(this->lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(change2red(const QString &)));

    // 定义按钮激活函数
    QObject::connect(this->pushButton,SIGNAL(clicked(bool)),this,SLOT(button_clicked_activated(bool)));


    this->horizontalLayout_4->addWidget(this->pushButton);

    this->horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    this->horizontalLayout_4->addItem(this->horizontalSpacer_2);


    this->verticalLayout_3->addLayout(this->horizontalLayout_4);


    this->horizontalLayout_2->addLayout(this->verticalLayout_3);


    this->retranslateUi();

    QMetaObject::connectSlotsByName(this);

}

Widget::~Widget()
{
    delete this->pushButton;
    qDebug()<<__LINE__<<":sucess!!"<<endl;
    delete this->label;
    qDebug()<<__LINE__<<":sucess!!"<<endl;
    delete this->lineEdit;
    qDebug()<<__LINE__<<":sucess!!"<<endl;
    delete this->horizontalSpacer;
    qDebug()<<__LINE__<<":sucess!!"<<endl;
    delete this->horizontalSpacer_2;
    qDebug()<<__LINE__<<":sucess!!"<<endl;
    delete this->horizontalLayout_4;
    qDebug()<<__LINE__<<":sucess!!"<<endl;
    delete this->verticalLayout_3;
    qDebug()<<__LINE__<<":sucess!!"<<endl;
    delete this->horizontalLayout_2;
    qDebug()<<__LINE__<<":sucess!!"<<endl;
}

void Widget::retranslateUi(){
    this->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
    // 初始化lineEdit的值是 “空白”
    this->lineEdit->setText(QCoreApplication::translate("Widget", "\xE7\xA9\xBA\xE7\x99\xBD", nullptr));
    this->lineEdit->setEchoMode(QLineEdit::Normal); // 正常显示模式
    this->lineEdit->selectAll();// 光标全选

    this->label->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201\r\n", nullptr));
    this->pushButton->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244\xE2\x80\xBC", nullptr));


}

//void Widget::delay(unsigned interval,std::function<void(void)> Func1){
//    QTimer::singleShot(interval,this,SLOT(Func1()));
//}



void Widget::release(){
    this->close();
}



void Widget::change2red(const QString &){
    this->lineEdit->setEchoMode(QLineEdit::Password);
    this->lineEdit->setStyleSheet("color:red;");
}


void Widget::show_answer(){
    this->label->setText("");// 清空label文字
    //重新调整大小
    this->resize(601, 80);
    this->setMinimumHeight(80);
    this->setMaximumHeight(80);
    this->horizontalLayout_2->removeWidget(this->label); // 删除label
    this->lineEdit->setStyleSheet("color:green;");// lineEdit输入框文字设置成绿色
    // 改变字体大小
    {
        QFont font;
        font.setPointSize(26);
        this->lineEdit->setFont(font);
    }
    this->lineEdit->setEchoMode(QLineEdit::Normal);// lineEdit 恢复显示正常

    this->lineEdit->setText("answer:");
    this->lineEdit->setReadOnly(true); // 不允许修改lineEdit的文字
    this->pushButton->setText("close"); // 按钮名称改为close
}

void Widget::button_clicked_activated(bool){
    // 如果lineEdit不被修改 则不执行任何动作
    if (lineEdit->text()==QCoreApplication::translate("Widget", "\xE7\xA9\xBA\xE7\x99\xBD", nullptr)) return ;


    QObject::disconnect(this->connection1);// 取消激活动作1
    if (pushButton->text()!="close") { // 当按钮名称不是close的时候
        DELAY(1000,show_answer);
    }
    else{// 第二次点击按钮时
            this->lineEdit->setText("closing...");
            this->lineEdit->setStyleSheet("color:black;");
            DELAY(3000,release);
    }
}

void QLineEdit_2::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_V && event->modifiers()== Qt::ControlModifier) return;
    QLineEdit::keyPressEvent(event);//保留事件原动作
    if(event->key() == Qt::Key_Left) {
        qDebug()<<"left"<<endl;
        this->parent->label->setStyleSheet("color:blue;");
    }
    else if (event->key() == Qt::Key_Right) {
        qDebug()<<"right"<<endl;
        this->parent->label->setStyleSheet("color:black;");
    }
}

QLineEdit_2::QLineEdit_2(Widget* src):parent(src){}



// 禁止右键菜单
#define BLOCKED
void QLineEdit_2::contextMenuEvent(QContextMenuEvent *){
    BLOCKED
}
#undef BLOCKED
