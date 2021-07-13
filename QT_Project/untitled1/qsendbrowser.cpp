#include "qsendbrowser.h"

QsendBrowser::QsendBrowser(QWidget *parent) : QPlainTextEdit(parent)
{

}

void QsendBrowser::keyPressEvent(QKeyEvent *e){
    if( (e->modifiers()& Qt::ControlModifier)!=0 && (e->key()==Qt::Key_Enter || e->key() == Qt::Key_Return)){
        emit send2file();
    }
    else {
        QPlainTextEdit::keyPressEvent(e);
    }
}
