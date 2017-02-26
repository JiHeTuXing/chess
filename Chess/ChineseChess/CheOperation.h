//
//
//
//  @ Project : Chess
//  @ File Name : CheOperation.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_CHEOPERATION_H)
#define _CHEOPERATION_H

#include "ChessInterface/PieceOperation.h"

class CheOperation : public PieceOperation {
public:
	bool canMove(const Board* board, const Step* step);
	bool theRule(const Board* board, const Step* step);
};

#endif  //_CHEOPERATION_H
