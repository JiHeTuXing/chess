//
//
//
//  @ Project : Chess
//  @ File Name : MaOperation.cpp
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#include "MaOperation.h"

///
/// \brief MaOperation::canMove
/// \param board
/// \param step
/// \return
///
bool MaOperation::canMove(const Board* board, const Step* step)
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


    if( (max_r-min_r)==2 && (max_c-min_c)==1 )
    {
        if( (*board)[RC(min_r+1,fc)]==UNSELECT )
        {
            flag= true ;
        }
    }
    else if( (max_r-min_r)==1 && (max_c-min_c)==2 )
    {
        if( (*board)[ RC(fr,min_c+1)]==UNSELECT )
            flag= true ;
    }
    else
    {
        flag =false ;
    }

    return flag ;

}

///
/// \brief MaOperation::theRule
/// \param board
/// \param step
/// \return
///
bool MaOperation::theRule(const Board* board, const Step* step)
{
    return true ;
}

