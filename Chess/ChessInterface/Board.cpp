#include"Board.h"

///
/// \brief Board::Board
/// \param rn
/// \param cn
/// \param pr
/// \param br
///
Board::Board(short rn, short cn, short pr, short br):
    _rNum(rn),_cNum(cn),_pieceRadius(pr),_boardRadius(br)
{

    Q_ASSERT_X(rn>0 && cn>0 && pr>0 && br>0, "row and col number", "can't lower zero");

    //piecePos创建与初始化
    piecePos = new short*[rn];
    for(int i=0 ;i<rn ; ++i)
        piecePos[i] = new short[cn] ;

    for(int i=0; i<rn; ++i)
        for(int j=0; j<cn; ++j)
            piecePos[i][j]=-1 ;

    //points创建与初始化
    points = new QPoint*[rn] ;
    for(int i=0; i<rn; ++i)
    {
        points[i] = new QPoint[cn] ;
    }

    for(int i=0; i<rn; ++i)
    {
        for(int j=0; j<cn; j++)
        {
            points[i][j].setY(i*_boardRadius);
            points[i][j].setX(j*_boardRadius);
        }
    }

}



///
/// \brief Board::~Board
///
Board::~Board()
{

   this->removePiecePos();
   this->removePoints();

}

void Board::removePiecePos()
{
    if(piecePos!=NULL)
    {
        for(int i=0; i<_rNum; ++i)
        {
            for(int j=0; j<_cNum; ++j)
            {
                delete &(piecePos[i][j]) ;
            }
        }

        delete []piecePos;
        piecePos=NULL ;
    }

}

void Board::removePoints()
{
    if(points!=NULL)
    {
        for(int i=0; i<_rNum; ++i)
        {
            for(int j=0; j<_cNum; ++j)
            {
                delete &(points[i][j]) ;
            }
        }
        delete []points;
        points=NULL ;
    }
}




