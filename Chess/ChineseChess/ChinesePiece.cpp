//
//
//
//  @ Project : Chess
//  @ File Name : ChinesePiece.cpp
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#include "ChinesePiece.h"

///
/// \brief ChinesePiece::ChinesePiece
/// \param id
/// \param type
/// \param r
/// \param c
/// \param operation
/// \param value
/// \param side
/// \param text
///
ChinesePiece::ChinesePiece(short id, ChinesePiece::PieceType type, short r, short c, PieceOperation *operation,const QString text, int value, bool side):
    Piece(id,r,c,operation,value,side)
{
    _type = type ;
    _isAlive = true  ;
    _text =text ;
}

///
/// \brief ChinesePiece::ChinesePiece
/// \param id
/// \param type
/// \param rc
/// \param operation
/// \param value
/// \param side
/// \param text
///
ChinesePiece::ChinesePiece(short id, ChinesePiece::PieceType type, const RC &rc, PieceOperation *operation,QString text, int value, bool side):
    Piece(id,rc,operation,value,side)
{
    _type = type ;
    _isAlive = true  ;
    _text =text ;
}

///
/// \brief ChinesePiece::ChinesePiece
/// \param id
/// \param type
/// \param rc
/// \param operation
/// \param value
/// \param side
/// \param text
///
ChinesePiece::ChinesePiece(short id, ChinesePiece::PieceType type, int rc, PieceOperation *operation,const QString text, int value, bool side):
    Piece(id,rc,operation,value,side)
{
    _type = type ;
    _isAlive = true  ;
    _text =text ;
}



///
/// \brief ChinesePiece::~ChinesePiece
///
ChinesePiece::~ChinesePiece()
{

}


