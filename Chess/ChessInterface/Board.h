//
//
//
//  @ Project : Chess
//  @ File Name : Board.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_BOARD_H)
#define _BOARD_H

#include<QPoint>
#include<QSize>
#include "RCCoordinate.h"

class Board
{

protected:
	short _rNum;
	short _cNum;
	short _pieceRadius;
	short _boardRadius;
    short** piecePos;
    QPoint** points;
    QSize _boardSize ;

public:

    /**
     * 构造函数与析构函数
     */

    //构造函数

    Board(short rn, short cn, short pr, short br) ;

    //析构函数
    virtual ~Board() ;

    /**
     * setter and getter
     */

    //_rNum
    inline void setRNum(short rn){_rNum = rn ;}

    inline short rNum(){return _rNum ;}

    inline short rNum() const {return _rNum; }

    // _cNum
    inline void setCNum(short cn){_cNum = cn ;}

    inline short cNum(){return _cNum ;}

    inline short cNum() const {return _cNum ;}

    // _pieceRadius
    inline void setPieceRadius(short pn){_pieceRadius = pn ;}

    inline short pieceRadius(){return _pieceRadius ;}

    // _boardRadius
    inline void setBoardRadius(short bn){_boardRadius = bn ;}

    inline short boardRadius(){return _boardRadius ;}

    // _boardSize
    inline void setBoardSize(const QSize& size){_boardSize = size ;}

    inline const QSize& boardSize(){return _boardSize;}

    /**
     *运算符重写
     */

    //operator [] piecePos
    short &operator [](int i) const;

    short &operator [](RC rc) const ;

    void removePiecePos() ;

    //at points
    const QPoint &at(int i);

    const QPoint &at(RC rc);

    void removePoints() ;
};

///
/// \brief Board::operator []
/// \param i
/// \return
///
inline short& Board::operator [](int i) const
{
    RC rc(i) ;
    Q_ASSERT_X(piecePos!=NULL && rc.r>=0 && rc.r< _rNum && rc.c>=0 && rc.c <_cNum, "Board::operator [](RC rc)", "index out of range") ;
    return piecePos[rc.r][rc.c] ;
}

///
/// \brief Board::operator []
/// \param rc
/// \return
///
inline short &Board::operator [](RC rc) const
{
    Q_ASSERT_X(piecePos!=NULL && rc.r>=0 && rc.r< _rNum && rc.c>=0 && rc.c <_cNum, "Board::operator [](RC rc)", "index out of range") ;
    return piecePos[rc.r][rc.c] ;
}

///
/// \brief Board::at
/// \param i
/// \return
///
inline const QPoint& Board::at(int i)
{
    RC rc(i) ;
    Q_ASSERT_X(piecePos!=NULL && rc.r>=0 && rc.r< _rNum && rc.c>=0 && rc.c <_cNum, "Board::operator [](RC rc)", "index out of range") ;
    return points[rc.r][rc.c] ;
}

///
/// \brief Board::at
/// \param rc
/// \return
///
inline const QPoint &Board::at(RC rc)
{
     Q_ASSERT_X(points!=NULL && rc.r>=0 && rc.r< _rNum && rc.c>=0 && rc.c <_cNum, "QPoint &Board::at(RC rc)", "index out of range") ;

     return points[rc.r][rc.c] ;
}

#endif  //_BOARD_H
