#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include "ChessInterface/BaseChess.h"


namespace Ui {
class ControlWidget;
}

class ControlWidget : public QWidget
{
    Q_OBJECT

public:
    BaseChess* _chess ;

public:
    explicit ControlWidget(BaseChess* c,QWidget *parent = 0);
    ~ControlWidget();

private slots:
    void on_peace_btn_pressed();

    void on_peace_btn_released();

    void on_surrender_btn_pressed();

    void on_surrender_btn_released();

    void on_undo_btn_pressed();

    void on_undo_btn_released();

    void on_peace_btn_clicked();

    void on_surrender_btn_clicked();

    void on_undo_btn_clicked();

private:
    Ui::ControlWidget *ui;
};

#endif // CONTROLWIDGET_H
