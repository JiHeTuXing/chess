//
//
//
//  @ Project : Chess
//  @ File Name : NetworkModel.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_NETWORKMODEL_H)
#define _NETWORKMODEL_H

#include "SimpleModel.h"

class NetworkModel : public SimpleModel
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

#endif  //_NETWORKMODEL_H
