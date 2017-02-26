//
//
//
//  @ Project : Chess
//  @ File Name : Chess.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_CHESS_H)
#define _CHESS_H

#include <QWidget>
#include <QMouseEvent>
#include"BaseChess.h"

class ChessImpl : public QWidget
{
protected:
	BaseChess* _chess;
public:

    /**
     *构造函数和析构函数
     */


    ChessImpl(QWidget *parent=0):QWidget(parent)
    {

    }

    //析构函数
    inline ~ChessImpl(){}

    /**
     *setter and getter
     */

    //_chess
    inline void setChess(BaseChess *chess)
    {
        _chess = chess ;
        _chess->paintBoard(this);
    }

    inline BaseChess* chess(){return _chess ;}

};



#endif  //_CHESS_H
