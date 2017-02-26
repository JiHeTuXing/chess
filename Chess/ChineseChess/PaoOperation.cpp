//
//
//
//  @ Project : Chess
//  @ File Name : PaoOperation.cpp
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#include "PaoOperation.h"

///
/// \brief PaoOperation::canMove
/// \param board
/// \param step
/// \return
///
bool PaoOperation::canMove(const Board* board, const Step* step)
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

    int i ;
    int interval_count =0 ;

    if(fr==tr && fc!=tc)
    {
        for(i = min_c+1 ;i<max_c ;++i)
        {
            if((*board)[RC(fr,i)]!=UNSELECT)
            {
                interval_count++ ;
            }
        }
        if( ((interval_count==0)&&( (*board)[RC(tr,tc)]==UNSELECT))
                || ((interval_count==1)&&( (*board)[RC(tr,tc)]!=UNSELECT)))
        {
            flag= true ;
        }
    }
    else if(fr!=tr && fc==tc)
    {
        for(i = min_r+1 ;i<max_r;++i)
        {
            if( (*board)[ RC(i,fc) ]!=UNSELECT)
            {
                interval_count++ ;
            }
        }
        if( ((interval_count==0)&&( (*board)[RC(tr,tc)]==UNSELECT))
                || ((interval_count==1)&&( (*board)[RC(tr,tc)]!=UNSELECT)) )
        {
            flag= true ;
        }

    }
    else
    {
        flag =false ;
    }

    return flag ;
}

///
/// \brief PaoOperation::theRule
/// \param board
/// \param step
/// \return
///
bool PaoOperation::theRule(const Board* board, const Step* step)
{
    return true ;
}

