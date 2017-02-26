#include "Controlwidget.h"
#include "ui_Controlwidget.h"
#include"UIHelp/UiHelp.h"

ControlWidget::ControlWidget(BaseChess *c, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlWidget)
{
    ui->setupUi(this);
    _chess = c ;
}

ControlWidget::~ControlWidget()
{
    delete ui;
}

/**
 *求和按键
 */

void ControlWidget::on_peace_btn_pressed()
{
    ui->peace_btn->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/button/draw_press.png);"));
}

void ControlWidget::on_peace_btn_released()
{
    ui->peace_btn->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/button/draw_nor.png);"));
}

/**
 * 认输按键
 */

void ControlWidget::on_surrender_btn_pressed()
{
    ui->surrender_btn->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/button/surrender_press.png);"));
}

void ControlWidget::on_surrender_btn_released()
{
    ui->surrender_btn->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/button/surrender_nor.png);"));
}


/**
 * 悔棋按键
 */

void ControlWidget::on_undo_btn_pressed()
{
    ui->undo_btn->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/button/undo_press.png);"));
}

void ControlWidget::on_undo_btn_released()
{
    ui->undo_btn->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/button/undo_nor.png);"));
}

/**
 *click
 */

void ControlWidget::on_peace_btn_clicked()
{
    UiHelp::ShowMessageBoxQuesion("您要求和吗?") ;
}

void ControlWidget::on_surrender_btn_clicked()
{
    UiHelp::ShowMessageBoxInfo("您要认输吗?") ;
}

void ControlWidget::on_undo_btn_clicked()
{
    UiHelp::ShowMessageBoxInfo("悔棋") ;
}
