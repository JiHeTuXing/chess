//
//
//
//  @ Project : Chess
//  @ File Name : CheOperation.cpp
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//
#include "CheOperation.h"


bool CheOperation::canMove(const Board* board, const Step* step)
{
    bool flag = false ;
    short fr = step->fromR() ;
    short tr = step->toR() ;
    short fc = step->fromC() ;
    short tc = step->toC() ;

    if( (fr==tr && qAbs(fc-tc)!=0) || (fc==tc && qAbs(fr-tr)!=0))
    {
        short f,t ;
        if(fr==tr)
        {
           f = qMin(fc,tc) ;
           t = qMax(fc,tc) ;
           int i  ;
           for(i=f+1 ; i<t; ++i )
           {
               if( UNSELECT!=(*board)[RC(fr,i)] )
                   break ;
           }
           flag = (i==t) ? true : false ;
        }
        else
        {
            f = qMin(fr,tr) ;
            t = qMax(fr,tr) ;
            int i  ;
            for(i=f+1 ; i<t; ++i )
            {
                if( UNSELECT!=(*board)[RC(i,fc)] )
                    break ;
            }
            flag = (i==t) ? true : false ;
        }
    }

    return flag ;
}


bool CheOperation::theRule(const Board* board, const Step* step)
{
    return true ;
}

