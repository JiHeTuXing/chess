//
//
//
//  @ Project : Chess
//  @ File Name : ChinesePiece.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_CHINESEPIECE_H)
#define _CHINESEPIECE_H

#include<QString>


#include "ChessInterface/Piece.h"

class ChinesePiece : public Piece
{
public:
    ///
    /// \brief The PieceType enum
    ///
    enum PieceType
    {
        Che = 0,
        Ma =1 ,
        Xiang = 2 ,
        Shi =3 ,
        Jiang =4 ,
        Pao = 5 ,
        Bing = 6
    } ;

protected:
	bool _isAlive;
	QString _text;
    PieceType _type ;
public:

    /**
     *构造函数和析构函数
     */

    ChinesePiece(short id, PieceType type, short r, short c , PieceOperation *operation=NULL, QString text="空", int value=0, bool side=true) ;

    ChinesePiece(short id, PieceType type, const RC& rc, PieceOperation *operation=NULL, QString text="空", int value=0, bool side=true ) ;

    ChinesePiece(short id, PieceType type, int rc, PieceOperation *operation=NULL, QString text="空", int value=0,  bool side=true) ;

    ~ChinesePiece() ;

    /**
     *setter and getter
     */

    inline void setIsAlive(bool b){_isAlive = b ;}

    inline bool isAlive(){return _isAlive ;}

    inline void setText(const QString& str){ _text = str ;}

    inline const QString& text(){return _text; }

};

#endif  //_CHINESEPIECE_H
