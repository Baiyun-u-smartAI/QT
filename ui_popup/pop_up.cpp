#include "pop_up.h"
#include "ui_pop_up.h"

pop_up::pop_up(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pop_up)
{
    ui->setupUi(this);
}

pop_up::~pop_up()
{
    delete ui;
}
