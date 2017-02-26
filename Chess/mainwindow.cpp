#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Controlwidget.h"
#include"UIHelp/IconHelp.h"
#include"UIHelp/UiHelp.h"
#include<QPalette>
#include<QPixmap>
#include<QHBoxLayout>
#include<QStandardPaths>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1100,620);
    //在窗口中放入主面板
    //在主面板中放入水平布局


    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    //在水平布局中放入游戏和按键
    QHBoxLayout *hlayout = new QHBoxLayout(ui->centralWidget) ;

    chess = new Chess(Chess::ChineseChessGame,BaseChess::SingleGame,true) ;

    hlayout->addWidget(chess);

    ControlWidget *controlWidget = new ControlWidget(chess->chess()) ;
    controlWidget->setFixedHeight(chess->height()+25);
    hlayout->addWidget(controlWidget);

    //设置关闭按键
    close_btn = new QPushButton ;
    close_btn->setFixedWidth(22);
    close_btn->setFlat(true);
    IconHelp::instance()->SetIcon(close_btn,QChar(0xf00d), 10) ;
    ui->menuBar->setCornerWidget(close_btn);
    connect(close_btn,SIGNAL(clicked()),this,SLOT(close())) ;

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(this->_isMousePressed && (e->buttons() && Qt::LeftButton) )
    {
        this->move(e->globalPos()-this->_mousePoint);
        e->accept();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(Qt::LeftButton==e->button())
    {
        this->_mousePoint = e->globalPos()-this->pos() ;
        this->_isMousePressed = true ;
        e->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    this->_isMousePressed = false ;
}

/**
 * 设置皮肤
 */
void MainWindow::on_actionBlue_triggered()
{
    UiHelp::SetStyle(qApp,"blue") ;
}

void MainWindow::on_actionBlack_triggered()
{
    UiHelp::SetStyle(qApp,"black") ;
}

void MainWindow::on_actionNavy_triggered()
{
    UiHelp::SetStyle(qApp,"navy") ;
}

void MainWindow::on_actionGray_triggered()
{
    UiHelp::SetStyle(qApp,"gray") ;
}

void MainWindow::on_shot_action_triggered()
{
    QPixmap pixmap = QPixmap::grabWidget(this->chess,0,0,this->chess->width(),this->chess->height()) ;
    QString fileName = QFileDialog::getSaveFileName(this,"save picture",QStandardPaths::displayName(QStandardPaths::DesktopLocation),tr("Images (*.png *.xpm *.jpg)")) ;
    pixmap.save(fileName) ;
}
