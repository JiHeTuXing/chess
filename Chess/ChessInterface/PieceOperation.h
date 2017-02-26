//
//
//
//  @ Project : Chess
//  @ File Name : PieceOperation.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_PIECEOPERATION_H)
#define _PIECEOPERATION_H
#define UNSELECT -1

#include"Board.h"
#include"Step.h"

class PieceOperation
{
public:


    inline PieceOperation(){}
    virtual ~PieceOperation(){}

    /**
     * virtual function
     */

	virtual bool canMove(const Board* board, const Step* step) = 0;
};

#endif  //_PIECEOPERATION_H
