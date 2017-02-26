//
//
//
//  @ Project : Chess
//  @ File Name : MaOperation.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_MAOPERATION_H)
#define _MAOPERATION_H

#include "ChessInterface/PieceOperation.h"

class MaOperation : public PieceOperation {
public:
	bool canMove(const Board* board, const Step* step);
	bool theRule(const Board* board, const Step* step);
};

#endif  //_MAOPERATION_H
