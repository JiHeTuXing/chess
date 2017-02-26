//
//
//
//  @ Project : Chess
//  @ File Name : PaoOperation.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_PAOOPERATION_H)
#define _PAOOPERATION_H

#include "ChessInterface/PieceOperation.h"

class PaoOperation : public PieceOperation {
public:
	bool canMove(const Board* board, const Step* step);
	bool theRule(const Board* board, const Step* step);
};

#endif  //_PAOOPERATION_H
