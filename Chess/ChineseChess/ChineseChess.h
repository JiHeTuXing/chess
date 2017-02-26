//
//
//
//  @ Project : Chess
//  @ File Name : ChineseChess.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_CHINESECHESS_H)
#define _CHINESECHESS_H

#include<QMap>
#include<QFont>
#include "ChessInterface/PieceOperation.h"
#include "ChessInterface/BaseChess.h"
#include "ChinesePiece.h"
#include "CheOperation.h"
#include "MaOperation.h"
#include "ShiOperation.h"
#include "XiangOperation.h"
#include "JiangOperation.h"
#include "PaoOperation.h"
#include "BingOperation.h"

#define CHINESE_XML_FILE_NAME ":/chinese_xml/chinese_cfg"
#define CHINESE_ROW_NUM 10
#define CHINESE_COL_NUM 9
#define CHINESE_PIECE_NUM 32
#define CHINESE_PIECE_RADIUS 20
#define CHINESE_BOARD_RADIUS 40

class ChineseChess : public BaseChess {

private:
    QMap<int,PieceOperation *> *_pieceOperationMap ;
    QMap<int,QString> *_type2TextMap ;
    QMap<int,int> *_type2ValueMap ;
    QPixmap *_pieceNormalPix ;
    QPixmap *_piecePressPix ;

    short _pieceDiameter ; //棋子直径
    QFont _pieceFont ;     //棋子字体

public:

    /**
     *构造函数和析构函数
     */

    ChineseChess(ChessModel model=BaseChess::SingleGame,bool c=true ,short pr=CHINESE_PIECE_RADIUS, short br=CHINESE_BOARD_RADIUS );

    ~ChineseChess() ;

    /**
     *
     *set and get
     */

    //_pieceNormalPix
    inline void removePieceNormalPix()
    {
        if(NULL!=_pieceNormalPix)
            delete _pieceNormalPix ;
    }

    void setPieceNormalPix(QString pixName)
    {
        this->removePieceNormalPix();
        _pieceNormalPix = new QPixmap(pixName) ;
    }

    inline void setPieceNormalPix(QPixmap* pix)
    {
        this->removePieceNormalPix();
        _pieceNormalPix = pix ;
    }

    inline const QPixmap* pieceNormalPix()
    {
        return _pieceNormalPix;
    }

    //_piecePressPix
    inline void removepiecePressPix()
    {
        if(NULL!=_piecePressPix)
            delete _piecePressPix ;
    }

    inline void setPiecePressPix(QString pixName)
    {
        this->removepiecePressPix();
        _piecePressPix = new QPixmap(pixName) ;
    }

    inline void setPiecePressPix(QPixmap* pix)
    {
        this->removepiecePressPix();
        _piecePressPix = pix ;
    }

    inline const QPixmap* piecePressPix()
    {
        return _piecePressPix ;
    }

    /**
     *operation function
     */

    virtual bool _moveAStep(Step* step) ;

    virtual bool _backAStep(Step *step) ;

    virtual bool _tryToMove(QPoint point);

    virtual RC getRcByPoint(QPoint point) ;


    virtual void paintChess(QWidget *widget, QPainter *painter);//绘制棋

    virtual void paintBoard(QWidget *widget);//绘制棋盘

    virtual void paintPiece(QPainter *painter) ;//绘制棋子


    /**
     *static function
     */

    static bool setConfig(void* pthis,const QDomDocument* doc) ;

protected:



    /**
     *init and create
     */

    //_pieceOperationMap
    void createOperationMap() ;

    void clearOperationMap() ;

    //_type2TextMap
    void createTextMap() ;

    void clearTextMap() ;

    //_type2ValueMap
    void createValueMap() ;

    void clearValueMap() ;

    //pieces
    void createPieces() ;

    void initPos() ;
};

#endif  //_CHINESECHESS_H
