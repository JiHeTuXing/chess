//
//
//
//  @ Project : Chess
//  @ File Name : JiangOperation.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_JIANGOPERATION_H)
#define _JIANGOPERATION_H

#include "ChessInterface/PieceOperation.h"

class JiangOperation : public PieceOperation {
public:
	bool canMove(const Board* board, const Step* step);
	bool theRule(const Board* board, const Step* step);

    bool faceToFace(const Board* board, int id, int tr, int tc);

};

#endif  //_JIANGOPERATION_H
