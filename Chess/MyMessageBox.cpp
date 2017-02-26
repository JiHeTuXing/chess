#include "MyMessageBox.h"
#include "ui_MyMessageBox.h"
#include"UIHelp/IconHelp.h"
#include"UIHelp/UiHelp.h"

MyMessageBox::MyMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyMessageBox)
{
    ui->setupUi(this);


    //初始化,表示鼠标没有按下
    this->_isMousePressed = false ;

    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint);

    //设置关闭后自动释放内存
    this->setAttribute(Qt::WA_DeleteOnClose);

    //设置图形字体
    IconHelp::instance()->SetIcon(ui->ico_label,QChar(0xf015), 12);
    IconHelp::instance()->SetIcon(ui->close_btn,QChar(0xf00d), 10);

    //信号与槽
    connect(ui->close_btn,SIGNAL(clicked()),this,SLOT(close())) ;
    connect(ui->cancle_btn,SIGNAL(clicked()),this,SLOT(close())) ;

    UiHelp::FormInCenter(this) ;
}

MyMessageBox::~MyMessageBox()
{
    delete ui;
}

void MyMessageBox::setMessage(const QString &msg, MyMessageBox::MessageType type)
{
    if(MyMessageBox::Sure==type)
    {
        ui->ico2_label->setStyleSheet("border-image: url(:/ui/image/dialog/sure.png);");
        ui->title_label->setText(tr("确定"));
    }
    else if(MyMessageBox::Error==type)
    {
        ui->ico2_label->setStyleSheet("border-image: url(:/ui/image/dialog/error.png);");
        ui->title_label->setText(tr("错误"));
    }
    else if(MyMessageBox::Question==type)
    {
        ui->ico2_label->setStyleSheet("border-image: url(:/ui/image/dialog/question.png);");
        ui->title_label->setText(tr("问题"));
    }
    else if(MyMessageBox::Info==type)
    {
        ui->ico2_label->setStyleSheet("border-image: url(:/ui/image/dialog/info.png);");
        ui->title_label->setText(tr("提示"));
    }
    ui->content_label->setText(msg);
}

void MyMessageBox::mouseMoveEvent(QMouseEvent *e)
{
    if(this->_isMousePressed && (e->buttons() && Qt::LeftButton) )
    {
        this->move(e->globalPos()-this->_mousePoint);
        e->accept();
    }
}

void MyMessageBox::mousePressEvent(QMouseEvent *e)
{
    if(Qt::LeftButton==e->button())
    {
        this->_mousePoint = e->globalPos()-this->pos() ;
        this->_isMousePressed = true ;
        e->accept();
    }
}

void MyMessageBox::mouseReleaseEvent(QMouseEvent *)
{
    this->_isMousePressed = false ;
}

void MyMessageBox::on_sure_btn_clicked()
{
    done(1) ;
    this->close();
}
