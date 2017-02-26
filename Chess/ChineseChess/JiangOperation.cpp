//
//
//
//  @ Project : Chess
//  @ File Name : JiangOperation.cpp
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//
#include "JiangOperation.h"

///
/// \brief JiangOperation::canMove
/// \param board
/// \param step
/// \return
///
bool JiangOperation::canMove(const Board* board, const Step* step)
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

//    int fid = stPos[fr][fc] ;//本函数没有用到stPos,这里是消除警告

    if( (tc>=3 && tc<=5) && ( ( tr>=0&&tr<=2 )|| (tr>=board->rNum()-3 && tr<= board->rNum()-1) ) )
    {
        if(!this->faceToFace(board,step->_fromId,tr,tc))
        {
            if( (max_r-min_r)==1 && (max_c-min_c)==0 )
            {
                flag= true ;
            }
            else if( (max_r-min_r)==0 && (max_c-min_c)==1 )
            {
                flag= true ;
            }
            else
            {
                flag = false ;
            }
        }

    }

    return flag ;

}


///
/// \brief JiangOperation::theRule
/// \param board
/// \param step
/// \return
///
bool JiangOperation::theRule(const Board* board, const Step* step)
{
    return true ;
}


/**
 *判断将军是否面对面
 */
bool JiangOperation::faceToFace(const Board* board , int id, int tr, int tc)
{
    int faceId = UNSELECT ;
    bool flag = false ;

    if(id<16)
    {
        for(int i=tr-1 ;i>=0 ; --i)
        {
            faceId = (*board)[ RC(i,tc) ] ;
            if(faceId!=UNSELECT)
                break;
        }
        if(faceId==(id+16))
            flag = true ;
    }
    else
    {
        for(int i=tr+1 ;i< board->rNum() ;++i)
        {
            faceId = (*board)[ RC(i,tc) ] ;
            if(faceId!=UNSELECT)
                break ;
        }
        if(faceId==(id-16))
            flag = true ;

    }

    return flag ;

}

