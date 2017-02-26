//
//
//
//  @ Project : Chess
//  @ File Name : BingOperation.cpp
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#include "BingOperation.h"

bool BingOperation::canMove(const Board* board, const Step* step)
{
    bool flag = false ;
    short fr = step->fromR() ;
    short tr = step->toR() ;
    short fc = step->fromC() ;
    short tc = step->toC() ;

    board = board ;

    if( (1==qAbs(fr-tr) && fc==tc ) || (fr==tr && 1==qAbs(fc-tc))  )
    {
        if(step->_fromId<16)
        {
            if( fr>4 && (1==tr-fr || tr==fr) )
                flag = false ;
            else
                flag = true ;
        }
        else
        {
            if(fr<5 && (1==fr-tr || fr==tr) )
                flag = false ;
            else
                flag = true ;
        }
    }
    return flag ;
}

bool BingOperation::theRule(const Board* board, const Step* step)
{
    return true ;

}

