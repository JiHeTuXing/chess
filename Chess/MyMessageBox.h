#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>
#include<QMouseEvent>


namespace Ui {
class MyMessageBox;
}

class MyMessageBox : public QDialog
{
    Q_OBJECT

public:
    enum MessageType
    {
        Sure  = 0 ,
        Error = 1 ,
        Question = 2,
        Info  = 3
    } ;

public:
    explicit MyMessageBox(QWidget *parent = 0);
    ~MyMessageBox();

    void setMessage(const QString& msg,MessageType type) ;

protected:
    void mouseMoveEvent(QMouseEvent *e) ;

    void mousePressEvent(QMouseEvent *e) ;

    void mouseReleaseEvent(QMouseEvent *) ;

private slots:
    void on_sure_btn_clicked();

private:
    Ui::MyMessageBox *ui;

    QPoint _mousePoint;              //鼠标拖动自定义标题栏时的坐标
    bool _isMousePressed;              //鼠标是否按下


};

#endif // MESSAGEBOX_H
