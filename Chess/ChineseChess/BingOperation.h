//
//
//
//  @ Project : Chess
//  @ File Name : BingOperation.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_BINGOPERATION_H)
#define _BINGOPERATION_H

#include "ChessInterface/PieceOperation.h"

class BingOperation : public PieceOperation {
public:
	bool canMove(const Board* board, const Step* step);
	bool theRule(const Board* board, const Step* step);
};

#endif  //_BINGOPERATION_H
