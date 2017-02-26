//
//
//
//  @ Project : Chess
//  @ File Name : XiangOperation.cpp
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#include "XiangOperation.h"

bool XiangOperation::canMove(const Board* board, const Step* step)
{

    bool flag = false ;
    short fr = step->fromR() ;
    short tr = step->toR() ;
    short fc = step->fromC() ;
    short tc = step->toC() ;

    int max_r = qMax(fr,tr) ;
    int min_r = qMin(fr,tr) ;
    int max_c = qMax(fc,tc) ;
    int min_c = qMin(fc,tc) ;

    if( ( (*board)[ RC(fr,fc)] <16 && tr>=board->rNum()-5) || ( (*board)[ RC(fr,fc)] >=16 && tr<=4) )
    {
        if( (max_r-min_r)==2 && (max_c-min_c)==2 )
        {
            if( (*board)[ RC(min_r+1,min_c+1) ]==UNSELECT)
            {
                flag= true ;
            }
        }
    }
    return flag ;
}

bool XiangOperation::theRule(const Board* board, const Step* step)
{
    return true ;
}

