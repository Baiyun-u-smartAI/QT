#ifndef POP_UP_H
#define POP_UP_H

#include <QDialog>

namespace Ui {
class pop_up;
}

class pop_up : public QDialog
{
    Q_OBJECT

public:
    explicit pop_up(QWidget *parent = nullptr);
    ~pop_up();

private:
    Ui::pop_up *ui;
};

#endif // POP_UP_H
