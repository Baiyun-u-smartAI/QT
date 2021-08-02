#include "page2.h"

page2::page2(QWidget *parent) : QWidget(parent)
{
    this->resize(797, 600);

    this->setCursor(QCursor(Qt::ArrowCursor));

    this->gridLayout = new QGridLayout;
    this->gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    this->gridLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(this->gridLayout);

    radioButton_3 = new QRadioButton;
    radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
    radioButton_3->setCursor(QCursor(Qt::PointingHandCursor));

    gridLayout->addWidget(radioButton_3, 0, 2, 1, 1);

    group1 = new QButtonGroup(this);


    radioButton_2 = new QRadioButton;
    radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
    radioButton_2->setCursor(QCursor(Qt::PointingHandCursor));
    group1->addButton(radioButton_2,1);
    gridLayout->addWidget(radioButton_2, 0, 1, 1, 1);


    radioButton = new QRadioButton;
    radioButton->setObjectName(QString::fromUtf8("radioButton"));
    radioButton->setCursor(QCursor(Qt::PointingHandCursor));
    group1->addButton(radioButton,0);
    gridLayout->addWidget(radioButton, 0, 0, 1, 1);


    QObject::connect(group1,SIGNAL(buttonClicked(int)),this,SLOT(showid(int)));



    this->pushButton = new QPushButton;
    this->pushButton->setObjectName("haha button");

    {
        QFont font;
        font.setPointSize(15);
        this->pushButton->setFont(font);
    }
    this->gridLayout->addWidget(this->pushButton,1,0,1,3);
    connect(pushButton,SIGNAL(clicked(bool)),this,SLOT(changeName(bool)));

    retranslateUi();

    QMetaObject::connectSlotsByName(this);


}

page2::~page2()
{
    qDebug()<<"closing..."<<endl;
    delete this->pushButton;
    if (!this->ButtonChangedInfo){
        delete this->ButtonChangedInfo;
        qDebug()<<"Info deleted!"<<endl;
    }
    qDebug()<<"success!!"<<endl;
    this->destroy();
}

void page2::changeName(bool){
    static bool RunFirst=true;
    this->pushButton->setText("no haha");
    if (RunFirst) {
        this->ButtonChangedInfo = new QMessageBox;
        this->ButtonChangedInfo->warning(this->ButtonChangedInfo,QString("hello"),QString("world!"),QMessageBox::Ok,QMessageBox::NoButton);
        RunFirst=false;
    }

}
void page2::retranslateUi(){
    this->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
    this->pushButton->setText("haha");
    this->radioButton_3->setText(QCoreApplication::translate("Widget", "第二页", nullptr));
    this->radioButton_2->setText(QCoreApplication::translate("Widget", "二选一按钮2", nullptr));
    this->radioButton->setText(QCoreApplication::translate("Widget", "二选一按钮1", nullptr));
}

void page2::showid(int x){
    qDebug()<<x<<endl;
}

void page2::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape) this->close();
    if(event->key() == Qt::Key_G && event->modifiers()==Qt::ControlModifier ) qDebug()<<"!!"<<endl;
}
