//
//
//
//  @ Project : Chess
//  @ File Name : ShiOperation.cpp
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#include "ShiOperation.h"

bool ShiOperation::canMove(const Board* board, const Step* step)
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

    if( (tc>=3 && tc<=5) && ( ( tr>=0&&tr<=2 )|| (tr>=board->rNum()-3 && tr<= board->rNum()-1 ) ) )
    {
        if( (max_r-min_r)==1 && (max_c-min_c)==1 )
        {
             flag= true ;
        }
    }
    return flag ;
}

bool ShiOperation::theRule(const Board* board, const Step* step)
{
    return true ;
}

