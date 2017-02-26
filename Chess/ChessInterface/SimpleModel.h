//
//
//
//  @ Project : Chess
//  @ File Name : SimpleModel.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_SIMPLEMODEL_H)
#define _SIMPLEMODEL_H

#include "ModelInterface.h"

class SimpleModel
{
protected:
    ModelInterface* _chessType;
public:

    /**
     * 构造函数和析构函数
     */

    //构造函数
    inline SimpleModel(){_chessType=NULL ;}

    inline SimpleModel(ModelInterface* t){_chessType = t;}

    //析构函数
    virtual ~SimpleModel(){}

    /**
     * setter
     */

    //_model
    inline void setChessType(ModelInterface* chess)
    {
        _chessType = chess ;
    }

    /**
     *virtual function
     */
    virtual bool model_moveAStep( Step* step  ) = 0;
    virtual bool model_backAStep( Step* step   ) = 0;
    virtual bool model_tryToMove(QPoint point) = 0 ;

};

#endif  //_SIMPLEMODEL_H
