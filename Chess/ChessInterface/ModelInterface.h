//
//
//
//  @ Project : Chess
//  @ File Name : ModelInterface.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_MODELINTERFACE_H)
#define _MODELINTERFACE_H
#include<QPoint>
#include"RCCoordinate.h"
#include"Step.h"

class ModelInterface
{
public:

    /**
     *virtual function
     */
    virtual bool _moveAStep(Step* step) = 0;
    virtual bool _backAStep( Step* step ) = 0;
    virtual bool _tryToMove(QPoint point) = 0 ;

    //通过Point得到rc
    virtual RC getRcByPoint(QPoint point) = 0 ;

    //判断是否是
    virtual bool isSelfMove()=0 ;

    //是否游戏结束
    virtual bool isGameOver()=0 ;
};

#endif  //_MODELINTERFACE_H
