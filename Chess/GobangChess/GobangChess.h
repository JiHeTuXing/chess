//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Chess
//  @ File Name : GobangChess.h
//  @ Date : 2017/1/9
//  @ Author : limuzi
//
//


#if !defined(_GOBANGCHESS_H)
#define _GOBANGCHESS_H

#include "ChessInterface/BaseChess.h"
#include "GobangOperation.h"
#include "GobangPiece.h"
#include <QWidget>
#include <QPixmap>


#define GOBANG_XML_FILE_NAME ":/gobang_xml/gobang_cfg"
#define GOBANG_ROW_NUM 15
#define GOBANG_COL_NUM 15
#define GOBANG_PIECE_RADIUS 15
#define GOBANG_BOARD_RADIUS 30



class GobangChess : public BaseChess {

private:
    PieceOperation* _pieceOperation ;
    QPixmap* _whitePix ;
    QPixmap* _blackPix ;

    short _pieceDiameter ; //棋子直径

    GobangPiece *_currentPiece ;
public:

    /**
     *构造函数与析构函数
     */

    GobangChess(BaseChess::ChessModel model, bool c, short pr=GOBANG_PIECE_RADIUS, short br=GOBANG_BOARD_RADIUS) ;

    ~GobangChess() ;


    //_whitePix
    inline void setWhitePix(QString pixName)
    {
        this->removeWhitePix();
        _whitePix = new QPixmap(pixName) ;
    }

    inline void removeWhitePix()
    {
        if(NULL!=_whitePix)
        {
            delete _whitePix ;
            _whitePix = NULL ;
        }
    }

    //_blackPix
    inline void setBlackPix(QString pixName)
    {
        this->removeBlackPix();
        _blackPix = new QPixmap(pixName) ;
    }

    inline void removeBlackPix()
    {
        if(NULL!=_blackPix)
        {
            delete _blackPix ;
            _blackPix = NULL ;
        }
    }


    /**
     *虚函数
     */

    //纯虚函数,绘制棋
    virtual void paintChess(QWidget *widget, QPainter *painter);
    //纯虚函数,绘制棋盘
    virtual void paintBoard(QWidget *widget) ;
    //纯虚函数,绘制棋子
    virtual void paintPiece(QPainter *painter) ;

    virtual bool _moveAStep(Step* step) ;
    virtual bool _backAStep( Step* step );
    virtual bool _tryToMove(QPoint point) ;

    //通过Point得到rc
    virtual RC getRcByPoint(QPoint point) ;

    /**
     *静态函数
     */
    static bool setConfig(void *pthis, const QDomDocument* doc) ;


};

#endif  //_GOBANGCHESS_H
