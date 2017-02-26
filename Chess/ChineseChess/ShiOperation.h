//
//
//
//  @ Project : Chess
//  @ File Name : ShiOperation.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_SHIOPERATION_H)
#define _SHIOPERATION_H

#include "ChessInterface/PieceOperation.h"

class ShiOperation : public PieceOperation {
public:
	bool canMove(const Board* board, const Step* step);
	bool theRule(const Board* board, const Step* step);
};

#endif  //_SHIOPERATION_H
