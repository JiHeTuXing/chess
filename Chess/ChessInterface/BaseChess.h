//
//
//
//  @ Project : Chess
//  @ File Name : BaseChess.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_BASECHESS_H)
#define _BASECHESS_H
#include<QVector>
#include<QWidget>
#include<QPainter>
#include<QDomDocument>
#include<QPixmap>
#include"XmlParse/DomDocument.h"
#include "Board.h"
#include "Step.h"
#include "Piece.h"
#include "ModelInterface.h"
#include "SimpleModel.h"
#include "NetworkModel.h"
#include "SingleModel.h"

class BaseChess : public Board, public ModelInterface
{
public:
    ///
    /// \brief The ChessModel enum
    ///枚举类型,分别表示游戏是人机对战,还是网络对战
    ///
	enum ChessModel
	{
		SingleGame=0,
		NetGame=1
	};

    ///
    /// \brief The GameStatus enum
    /// 表示游戏的状态
    ///
	enum GameStatus
	{
        ProcessGame=1,
        WinGame=2,
        LoseGame=3
	};

    ///
    /// \brief gameType
    /// 标明游戏类型
    /// 0 表示象棋
    /// 1 表示五子棋
    ///
    int gameType ;

protected:
    ///
    /// \brief _status
    /// 表示游戏状态
    /// ProcessGame=1 表示游戏进行
    /// WinGame=2     表示胜
    /// LoseGame=3    表示输
    ///
    GameStatus _status;

    ///
    /// \brief _model
    /// SingleGame=0  表示人机对战模式
    /// NetGame=1     表示网络对战模式
    ///
	ChessModel _model;
    SimpleModel* _modelClass ;


    QVector<Step*> _steps;   //保存走的每一步

    QVector<Piece*> _pieces; //保存棋子

    short _pieceNum;         //棋子数

    short _selectId;         //选中的棋子id

    RC _selectRC ;           //选中的row 和 col

    bool _side ;

    bool _pieceColor ;

    Step* _nextStep;         //棋子的下一步

    DomDocument *_dom ;       //设置配置文档

    QString _backgroundPix ; //棋盘背景

 public:


    /**
     * 构造函数和析构函数
     */

    BaseChess(ChessModel model,bool pieceColor ,short rn, short cn, short pr, short br );

    //析构函数
    virtual ~BaseChess()
    {
        if(NULL!=_modelClass)
        {
            delete _modelClass;
            _modelClass = NULL ;
        }
    }


    /**
     * setter and getter
     */

    //_status
    inline void setStatus(BaseChess::GameStatus s){_status=s;}

    inline BaseChess::GameStatus status(){return _status;}

    //_model
    inline void setModel(BaseChess::ChessModel m){_model=m ;}

    inline BaseChess::ChessModel model(){return _model; }

    //_pieceNum
    inline void setPieceNum(short pn){_pieceNum= pn ;}

    inline short pieceNum(){return _pieceNum; }

    //_selectId
    inline void setSelectId(short id){_selectId = id ;}

    inline short selectId(){return _selectId; }

    //_selectRC
    inline void setSelectRC(const RC& rc){_selectRC = rc ;}

    inline void setSelectRC(short r,short c){_selectRC.r=r ;_selectRC.c=c;}

    inline void setSelectRC(int rc){_selectRC.rc = rc ;}

    inline const RC& selectRC(){return _selectRC;}

    //_side
    inline void setSide(bool b){_side = b ;}

    inline bool side(){return _side;}

    //_pieceColor
    inline void setPieceColor(bool c){_pieceColor = c ;}

    inline bool pieceColor(){return _pieceColor ;}

    //_nextStep
    inline void setNextStep(Step *s){_nextStep = s ;}

    inline Step* nextStep(){return _nextStep; }

    //_pieces
    inline void addPiece(Piece *piece)
    {
        if(_pieces.size()<_pieceNum)
        {
            _pieces.append(piece);
        }
        else return ;
    }

    inline const QVector<Piece*>& pieces(){return _pieces;}

    inline const Piece* piece(int i)
    {
        if(i<_pieces.size())
            return _pieces[i] ;
        else
            return NULL ;
    }

    void removeAllPieces() ;

    inline int getPiecesSize(){return _pieces.size();}


    //_steps
    inline const QVector<Step*>& steps(){return _steps ;}

    inline void addStep(Step* step){_steps.append(step);}

    inline bool isEmptySteps(){ return _steps.isEmpty() ;}

    void removeOneStep();

    void removeAllSteps();

    int getStepsSize(){return _steps.size();}

    //_dom
    inline void removeDom()
    {
        if(NULL!=_dom)
            delete _dom ;
    }

    inline void setDom(DomDocument* dom)
    {
       removeDom();
       _dom = dom ;
    }

    inline const DomDocument* dom()
    {
        return _dom ;
    }

    //backgroundPix
    inline void setBackgroundPix(QString bgName)
    {
        _backgroundPix = bgName ;
    }


    inline QString backgroundPix(){return _backgroundPix ;}


    /**
     * operation function
     */

    //为外部提供调用
    //根据不同的模式调用
    virtual bool moveAStep( Step* step  )
    {
        return _modelClass->model_moveAStep(step) ;
    }

    virtual bool backAStep( Step* step )
    {
        return _modelClass->model_backAStep(step) ;
    }

    virtual bool tryToMove(QPoint point)
    {
        return _modelClass->model_tryToMove(point) ;
    }


    virtual bool isGameOver()
    {
        if(this->_status==BaseChess::ProcessGame)
            return false ;
        else
            return true ;
    }

    //如果要走的那一方 与 自己方棋子颜色相同
    virtual bool isSelfMove()
    {
        return _side==_pieceColor ;
    }


    /**
     *虚函数
     *
     */

    //纯虚函数,绘制棋
    virtual void paintChess(QWidget *widget, QPainter *painter)=0 ;
    //纯虚函数,绘制棋盘
    virtual void paintBoard(QWidget *widget)=0 ;
    //纯虚函数,绘制棋子
    virtual void paintPiece(QPainter *painter)=0 ;



};


///
/// \brief BaseChess::BaseChess 构造函数
/// \param model
/// \param rn
/// \param cn
/// \param pr
/// \param br
///
inline BaseChess::BaseChess(ChessModel model, bool pieceColor, short rn, short cn, short pr, short br ):
    Board(rn,cn,pr,br)
{
   _model = model ;

   _pieceColor = pieceColor ;

   switch(_model)
   {
   case BaseChess::SingleGame :
       _modelClass = new SingleModel ;
       break ;
   case BaseChess::NetGame :
       _modelClass = new NetworkModel ;
       break ;
   default:
       _modelClass = new SingleModel ;
       break ;

   }

   _modelClass->setChessType(this);

   _status = BaseChess::ProcessGame ;
   _selectId=-1 ;
   _selectRC = -1 ;
   _side = true ;
   _dom = NULL ;
   _backgroundPix = "" ;
}

///
/// \brief BaseChess::removeOneStep  删除一步,用于后退
///
inline void BaseChess::removeOneStep()
{
    if(! _steps.isEmpty())
    {
        Step* step  = _steps.back() ;
        delete step ;
        _steps.pop_back();
    }
}


///
/// \brief BaseChess::removeAllSteps 删除所有步数,用于析构
///
inline void BaseChess::removeAllSteps()
{
    Step* step = NULL ;
    while( !_steps.isEmpty() )
    {
       step = _steps.back() ;
       delete step ;
       _steps.pop_back();
    }
}

///
/// \brief BaseChess::removeAllPieces 删除所有棋子,用于析构
///
inline void BaseChess::removeAllPieces()
{
    Piece* piece = NULL ;
    while( !_pieces.isEmpty() )
    {
       piece = _pieces.back() ;
       delete piece ;
       _pieces.pop_back();
    }
}


#endif  //_BASECHESS_H
