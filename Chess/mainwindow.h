#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPushButton>
#include"ChessInterface/ChessImpl.h"
#include"Chess.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    void mouseMoveEvent(QMouseEvent *e) ;

    void mousePressEvent(QMouseEvent *e) ;

    void mouseReleaseEvent(QMouseEvent *) ;

private slots:
    void on_actionBlue_triggered();

    void on_actionBlack_triggered();

    void on_actionNavy_triggered();

    void on_actionGray_triggered();

    void on_shot_action_triggered();

private:
    Ui::MainWindow *ui;

    Chess *chess ;

    QPushButton *close_btn ;

    QPoint _mousePoint;              //鼠标拖动自定义标题栏时的坐标
    bool _isMousePressed;              //鼠标是否按下
};

#endif // MAINWINDOW_H
