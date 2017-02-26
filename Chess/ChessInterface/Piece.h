//
//
//
//  @ Project : Chess
//  @ File Name : Piece.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_PIECE_H)
#define _PIECE_H

#include <QPainter>
#include "PieceOperation.h"
#include "RCCoordinate.h"

class Piece : public PieceOperation
{
protected:
    short _id;
    RC _rc ;
    bool _side;
    int _value;
    PieceOperation* _operation;

public:

    /**
     * 构造函数和析构函数
     */

    //构造函数

    Piece(short id, short r,short c ,PieceOperation *operation=NULL, int value=0, bool side=true) ;

    Piece(short id,const RC& rc,PieceOperation *operation=NULL, int value=0, bool side=true) ;

    Piece(short id,int rc,PieceOperation *operation=NULL, int value=0, bool side=true) ;

    //析构函数
    inline virtual ~Piece(){}

    /**
     * setter
     */

    inline void setId(short id){ _id = id ; }

    inline void setRC(short r,short c){ _rc.r =r ; _rc.c =c ; }

    inline void setRC(int rc){ _rc.rc = rc ; }

    inline void setRC(const RC& rc){ _rc = rc ; }

    inline void setSide(bool side){ _side = side; }

    inline void setValue(int value){ _value = value ; }

    /**
     * getter
     */

    inline short id(){return _id ;}

    inline short r(){return _rc.r ;}

    inline short c(){return _rc.c ;}

    inline int rc(){return _rc.rc ;}

    inline bool side(){return _side ;}

    inline int value(){return _value ;}

    /**
     * operation function
     */

    inline virtual bool canMove(const Board* board, const Step* step)
    {
       return _operation->canMove(board,step) ;
    }

};


///
/// \brief Piece::Piece
/// \param id
/// \param r
/// \param c
/// \param operation
/// \param value
/// \param side
///
inline Piece::Piece(short id, short r, short c , PieceOperation *operation, int value, bool side)
{
    this->_id  = id ;
    this->_rc.r =r ;
    this->_rc.c =c ;
    this->_operation = operation ;
    this->_side = side ;
    this->_value = value ;
}

///
/// \brief Piece::Piece
/// \param id
/// \param rc
/// \param operation
/// \param value
/// \param side
///
inline Piece::Piece(short id,const RC& rc,PieceOperation *operation, int value, bool side)
{
    this->_id  = id ;
    this->_rc = rc ;
    this->_operation = operation ;
    this->_side = side ;
    this->_value = value ;
}

///
/// \brief Piece::Piece
/// \param id
/// \param rc
/// \param operation
/// \param value
/// \param side
///
inline Piece::Piece(short id, int rc, PieceOperation *operation, int value, bool side)
{
    this->_id  = id ;
    this->_rc.rc = rc ;
    this->_operation = operation ;
    this->_side = side ;
    this->_value = value ;
}


#endif  //_PIECE_H
