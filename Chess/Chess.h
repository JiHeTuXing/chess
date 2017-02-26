#ifndef CHESS_H
#define CHESS_H

#include"ChessInterface/ChessImpl.h"
#include"ChineseChess/ChineseChess.h"
#include"GobangChess/GobangChess.h"

#define CHINESE_CHESS_WIDTH 360
#define CHINESE_CHESS_HIGHT 434

#define GOBANG_WIDTH 360
#define GOBANG_HIGHT 377


class Chess : public ChessImpl
{

public:
    enum GameType
    {
        ChineseChessGame = 0 ,
        GobangGame =1
    };

public:
    /**
     *构造函数和析构函数
     */


    Chess(GameType gameType,BaseChess::ChessModel model,bool side,QWidget *parent=0):ChessImpl(parent)
    {
        if(gameType==ChineseChessGame)
        {
            //设置棋盘大小
            this->setFixedSize(CHINESE_CHESS_WIDTH,CHINESE_CHESS_HIGHT);
            this->setChess(new ChineseChess(model,side) );
        }
        else
        {
            //设置棋盘大小
            this->setFixedSize(GOBANG_WIDTH,GOBANG_HIGHT);
            this->setChess(new GobangChess(model,side) );
        }

    }

    //析构函数
    inline ~Chess(){ if(_chess!=NULL) delete _chess ; }


    /**
     *operation function
     */

    //paintEvent
    virtual void paintEvent(QPaintEvent *) ;

    virtual void mouseReleaseEvent(QMouseEvent *me) ;

};

#endif // CHESS_H
