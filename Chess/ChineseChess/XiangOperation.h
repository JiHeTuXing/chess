//
//
//
//  @ Project : Chess
//  @ File Name : XiangOperation.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_XIANGOPERATION_H)
#define _XIANGOPERATION_H

#include "ChessInterface/PieceOperation.h"

class XiangOperation : public PieceOperation {
public:
	bool canMove(const Board* board, const Step* step);
	bool theRule(const Board* board, const Step* step);
};

#endif  //_XIANGOPERATION_H
