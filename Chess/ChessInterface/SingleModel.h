//
//
//
//  @ Project : Chess
//  @ File Name : SingleModel.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_SINGLEMODEL_H)
#define _SINGLEMODEL_H

#include "SimpleModel.h"


class SingleModel : public SimpleModel
{

public:
    virtual bool model_moveAStep(Step* step)
    {
       return this->_chessType->_moveAStep(step) ;
    }

    virtual bool model_backAStep(Step* step)
    {
        return this->_chessType->_backAStep(step) ;
    }

    virtual bool model_tryToMove(QPoint point)
    {

        return this->_chessType->_tryToMove(point) ;

    }
};

#endif  //_SINGLEMODEL_H
