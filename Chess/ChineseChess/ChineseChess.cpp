//
//
//
//  @ Project : Chess
//  @ File Name : ChineseChess.cpp
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//

#include "ChineseChess.h"
#include<QDebug>

/**
 * ==================================================
 * 构造函数和析构函数
 * ==================================================
 */
///
/// \brief ChineseChess::ChineseChess
/// \param model
/// \param c 表示自己哪一方颜色
/// \param pr 棋子半径
/// \param br 棋盘半径
///
ChineseChess::ChineseChess(BaseChess::ChessModel model, bool c, short pr, short br):
    BaseChess(model,c,CHINESE_ROW_NUM,CHINESE_COL_NUM,pr,br)
{
    this->gameType = 0 ;
    this->_pieceNum = 32 ;
    this->_pieces.resize(_pieceNum);
    _pieceOperationMap = NULL ;
    _type2TextMap      = NULL ;
    _type2ValueMap     = NULL ;

    _backgroundPix     = "" ;
    _piecePressPix     = NULL ;
    _pieceNormalPix    = NULL ;
    _pieceDiameter     = _pieceRadius*2 ;
    //利用回调函数调用
    _dom = new DomDocument(CHINESE_XML_FILE_NAME) ;
    _dom->readXml(this,this->setConfig) ;

    _pieceFont.setBold(true);
    _pieceFont.setFamily("KaiTi");
    _pieceFont.setPixelSize(20);

    //创建配置
    this->createOperationMap();
    this->createTextMap();
    this->createValueMap();
    this->createPieces();
    this->initPos();
}

///
/// \brief ChineseChess::~ChineseChess
///     析构函数
///
ChineseChess::~ChineseChess()
{
    this->removeAllSteps();
    this->removeAllPieces();

    this->clearOperationMap();
    this->clearTextMap();
    this->clearValueMap();

    this->removeDom();
    this->removePieceNormalPix();
    this->removepiecePressPix();
}




/**
 * ==================================================
 * 初始化和清除函数
 * ==================================================
 */

///
/// \brief ChineseChess::ChineseChess
/// \param model
///
void ChineseChess::createOperationMap()
{
    while(_pieceOperationMap==NULL)
    {
        _pieceOperationMap = new QMap<int,PieceOperation *> ;
        _pieceOperationMap->insert(ChinesePiece::Che,new CheOperation) ;
        _pieceOperationMap->insert(ChinesePiece::Ma,new MaOperation) ;
        _pieceOperationMap->insert(ChinesePiece::Xiang,new XiangOperation) ;
        _pieceOperationMap->insert(ChinesePiece::Shi,new ShiOperation) ;
        _pieceOperationMap->insert(ChinesePiece::Jiang,new JiangOperation) ;
        _pieceOperationMap->insert(ChinesePiece::Pao,new PaoOperation) ;
        _pieceOperationMap->insert(ChinesePiece::Bing,new BingOperation) ;
    }
}

///
/// \brief ChineseChess::clearOperationMap
///
void ChineseChess::clearOperationMap()
{
    if(_pieceOperationMap!=NULL)
    {
        PieceOperation *operation = NULL ;

        QMap<int,PieceOperation*>::iterator iterator ;
        for( iterator=_pieceOperationMap->begin() ; iterator==_pieceOperationMap->end() ;iterator++)
        {
            operation = iterator.value() ;
            delete operation ;
        }
        _pieceOperationMap->clear();
        delete _pieceOperationMap ;
        _pieceOperationMap = NULL ;
    }
}

///
/// \brief ChineseChess::createTextMap
///
void ChineseChess::createTextMap()
{
    while(_type2TextMap==NULL)
    {
        _type2TextMap = new QMap<int,QString> ;
        _type2TextMap->insert(ChinesePiece::Che,"车") ;
        _type2TextMap->insert(ChinesePiece::Ma,"马") ;
        _type2TextMap->insert(ChinesePiece::Xiang,"象") ;
        _type2TextMap->insert(ChinesePiece::Shi,"士") ;
        _type2TextMap->insert(ChinesePiece::Jiang,"将") ;
        _type2TextMap->insert(ChinesePiece::Pao,"炮") ;
        _type2TextMap->insert(ChinesePiece::Bing,"兵") ;
    }
}

///
/// \brief ChineseChess::clearTextMap
///
void ChineseChess::clearTextMap()
{
    if(_type2TextMap!=NULL)
    {
        _type2TextMap->clear();
        delete _type2TextMap ;
        _type2TextMap = NULL ;
    }
}

///
/// \brief ChineseChess::createValueMap
///
void ChineseChess::createValueMap()
{
    while(_type2ValueMap==NULL)
    {
        _type2ValueMap = new QMap<int,int> ;
        _type2ValueMap->insert(ChinesePiece::Che,500) ;
        _type2ValueMap->insert(ChinesePiece::Ma,250) ;
        _type2ValueMap->insert(ChinesePiece::Xiang,80) ;
        _type2ValueMap->insert(ChinesePiece::Shi,80) ;
        _type2ValueMap->insert(ChinesePiece::Jiang,10000) ;
        _type2ValueMap->insert(ChinesePiece::Pao,250) ;
        _type2ValueMap->insert(ChinesePiece::Bing,80) ;
    }
}

///
/// \brief ChineseChess::clearValueMap
///
void ChineseChess::clearValueMap()
{
    if(_type2ValueMap!=NULL)
    {
        _type2ValueMap->clear();
        delete _type2ValueMap ;
        _type2ValueMap = NULL ;
    }
}

void ChineseChess::createPieces()
{
    if(_pieceOperationMap==NULL)
        this->createOperationMap();
    if(_type2TextMap==NULL)
        this->createTextMap();
    if(_type2ValueMap==NULL)
        this->createValueMap();

    //车
    _pieces.replace(0,new ChinesePiece(0,ChinesePiece::Che,_rNum-1,0,
                                    _pieceOperationMap->value(ChinesePiece::Che),
                                    _type2TextMap->value(ChinesePiece::Che),
                                    _type2ValueMap->value(ChinesePiece::Che),
                                    _pieceColor));
    _pieces.replace(8,new ChinesePiece(8,ChinesePiece::Che,_rNum-1,_cNum-1,
                                    _pieceOperationMap->value(ChinesePiece::Che),
                                    _type2TextMap->value(ChinesePiece::Che),
                                    _type2ValueMap->value(ChinesePiece::Che),
                                    _pieceColor));
    _pieces.replace(16,new ChinesePiece(16,ChinesePiece::Che,0,0,
                                    _pieceOperationMap->value(ChinesePiece::Che),
                                    _type2TextMap->value(ChinesePiece::Che),
                                    _type2ValueMap->value(ChinesePiece::Che),
                                    !_pieceColor));
    _pieces.replace(24,new ChinesePiece(24,ChinesePiece::Che,0,_cNum-1,
                                    _pieceOperationMap->value(ChinesePiece::Che),
                                    _type2TextMap->value(ChinesePiece::Che),
                                    _type2ValueMap->value(ChinesePiece::Che),
                                    !_pieceColor));
    //马
    _pieces.replace(1,new ChinesePiece(1,ChinesePiece::Ma,_rNum-1,1,
                                    _pieceOperationMap->value(ChinesePiece::Ma),
                                    _type2TextMap->value(ChinesePiece::Ma),
                                    _type2ValueMap->value(ChinesePiece::Ma),
                                    _pieceColor));
    _pieces.replace(7,new ChinesePiece(7,ChinesePiece::Ma,_rNum-1,_cNum-2,
                                    _pieceOperationMap->value(ChinesePiece::Ma),
                                    _type2TextMap->value(ChinesePiece::Ma),
                                    _type2ValueMap->value(ChinesePiece::Ma),
                                    _pieceColor));
    _pieces.replace(17,new ChinesePiece(17,ChinesePiece::Ma,0,1,
                                    _pieceOperationMap->value(ChinesePiece::Ma),
                                    _type2TextMap->value(ChinesePiece::Ma),
                                    _type2ValueMap->value(ChinesePiece::Ma),
                                    !_pieceColor));
    _pieces.replace(23,new ChinesePiece(23,ChinesePiece::Ma,0,_cNum-2,
                                    _pieceOperationMap->value(ChinesePiece::Ma),
                                    _type2TextMap->value(ChinesePiece::Ma),
                                    _type2ValueMap->value(ChinesePiece::Ma),
                                    !_pieceColor));
    //象
    _pieces.replace(2,new ChinesePiece(2,ChinesePiece::Xiang,_rNum-1,2,
                                    _pieceOperationMap->value(ChinesePiece::Xiang),
                                    _type2TextMap->value(ChinesePiece::Xiang),
                                    _type2ValueMap->value(ChinesePiece::Xiang),
                                    _pieceColor));
    _pieces.replace(6,new ChinesePiece(6,ChinesePiece::Xiang,_rNum-1,_cNum-3,
                                    _pieceOperationMap->value(ChinesePiece::Xiang),
                                    _type2TextMap->value(ChinesePiece::Xiang),
                                    _type2ValueMap->value(ChinesePiece::Xiang),
                                    _pieceColor));
    _pieces.replace(18,new ChinesePiece(18,ChinesePiece::Xiang,0,2,_pieceOperationMap->value(ChinesePiece::Xiang),
                                    _type2TextMap->value(ChinesePiece::Xiang),
                                    _type2ValueMap->value(ChinesePiece::Xiang),
                                    !_pieceColor));
    _pieces.replace(22,new ChinesePiece(22,ChinesePiece::Xiang,0,_cNum-3,
                                    _pieceOperationMap->value(ChinesePiece::Xiang),
                                    _type2TextMap->value(ChinesePiece::Xiang),
                                    _type2ValueMap->value(ChinesePiece::Xiang),
                                    !_pieceColor));
    //士
    _pieces.replace(3,new ChinesePiece(3,ChinesePiece::Shi,_rNum-1,3,
                                    _pieceOperationMap->value(ChinesePiece::Shi),
                                    _type2TextMap->value(ChinesePiece::Shi),
                                    _type2ValueMap->value(ChinesePiece::Shi),
                                    _pieceColor));
    _pieces.replace(5,new ChinesePiece(5,ChinesePiece::Shi,_rNum-1,_cNum-4,
                                    _pieceOperationMap->value(ChinesePiece::Shi),
                                    _type2TextMap->value(ChinesePiece::Shi),
                                    _type2ValueMap->value(ChinesePiece::Shi),
                                    _pieceColor));
    _pieces.replace(19,new ChinesePiece(19,ChinesePiece::Shi,0,3,
                                    _pieceOperationMap->value(ChinesePiece::Shi),
                                    _type2TextMap->value(ChinesePiece::Shi),
                                    _type2ValueMap->value(ChinesePiece::Shi),
                                    !_pieceColor));
    _pieces.replace(21,new ChinesePiece(21,ChinesePiece::Shi,0,_cNum-4,
                                    _pieceOperationMap->value(ChinesePiece::Shi),
                                    _type2TextMap->value(ChinesePiece::Shi),
                                    _type2ValueMap->value(ChinesePiece::Shi),
                                    !_pieceColor));
    //将
    _pieces.replace(4,new ChinesePiece(4,ChinesePiece::Jiang,_rNum-1,4,
                                    _pieceOperationMap->value(ChinesePiece::Jiang),
                                    _type2TextMap->value(ChinesePiece::Jiang),
                                    _type2ValueMap->value(ChinesePiece::Jiang),
                                    _pieceColor));
    _pieces.replace(20,new ChinesePiece(20,ChinesePiece::Jiang,0,4,
                                    _pieceOperationMap->value(ChinesePiece::Jiang),
                                    _type2TextMap->value(ChinesePiece::Jiang),
                                    _type2ValueMap->value(ChinesePiece::Jiang),
                                    !_pieceColor));
    //炮
    _pieces.replace(9,new ChinesePiece(9,ChinesePiece::Pao,_rNum-3,1,
                                    _pieceOperationMap->value(ChinesePiece::Pao),
                                    _type2TextMap->value(ChinesePiece::Pao),
                                    _type2ValueMap->value(ChinesePiece::Pao),
                                    _pieceColor));
    _pieces.replace(10,new ChinesePiece(10,ChinesePiece::Pao,_rNum-3,_cNum-2,
                                    _pieceOperationMap->value(ChinesePiece::Pao),
                                    _type2TextMap->value(ChinesePiece::Pao),
                                    _type2ValueMap->value(ChinesePiece::Pao),
                                    _pieceColor));
    _pieces.replace(25,new ChinesePiece(25,ChinesePiece::Pao,2,1,
                                    _pieceOperationMap->value(ChinesePiece::Pao),
                                    _type2TextMap->value(ChinesePiece::Pao),
                                    _type2ValueMap->value(ChinesePiece::Pao),
                                    !_pieceColor));
    _pieces.replace(26,new ChinesePiece(26,ChinesePiece::Pao,2,_cNum-2,
                                    _pieceOperationMap->value(ChinesePiece::Pao),
                                    _type2TextMap->value(ChinesePiece::Pao),
                                    _type2ValueMap->value(ChinesePiece::Pao),
                                    !_pieceColor));
    //兵
    for(int i=0; i<5; ++i)
    {
        _pieces.replace(11+i,new ChinesePiece(11+i,ChinesePiece::Bing,_rNum-4,i*2,
                                        _pieceOperationMap->value(ChinesePiece::Bing),
                                        _type2TextMap->value(ChinesePiece::Bing),
                                        _type2ValueMap->value(ChinesePiece::Bing),
                                        _pieceColor));
        _pieces.replace(11+16+i,new ChinesePiece(11+16+i,ChinesePiece::Bing,3,i*2,
                                        _pieceOperationMap->value(ChinesePiece::Bing),
                                        _type2TextMap->value(ChinesePiece::Bing),
                                        _type2ValueMap->value(ChinesePiece::Bing),
                                        !_pieceColor));
    }


}

void ChineseChess::initPos()
{
    for(int i=0 ;i<_pieceNum ; i++)
    {
        (*this)[_pieces.at(i)->rc()] = _pieces.at(i)->id() ;
    }
}



/**
 * ==================================================
 * 虚函数
 * ==================================================
 */

///
/// \brief ChineseChess::paintChess
/// \param widget
/// \param painter
///
void ChineseChess::paintChess(QWidget *widget, QPainter *painter)
{
    widget = widget ;
    this->paintPiece(painter);
}

///
/// \brief ChineseChess::paintBoard
/// \param widget
/// \param painter
///
void ChineseChess::paintBoard(QWidget *widget)
{

//    QPalette palette = widget->palette()  ;
//    palette.setBrush(QPalette::Active,QPalette::Window,QBrush(_backgroundPix));
//    widget->setPalette(palette);
//    widget->setAutoFillBackground(true);

    //设置棋盘背景
    widget->setStyleSheet("border-image: url("+_backgroundPix+");");

}


///
/// \brief ChineseChess::paintPiece
/// \param widget
/// \param painter
///
void ChineseChess::paintPiece(QPainter *painter)
{
    painter->setFont(_pieceFont);
    for(int i=0; i<_pieceNum; ++i)
    {
         ChinesePiece* piece = (ChinesePiece*)(_pieces.at(i)) ;
         //判断棋子是否活着
         if(piece->isAlive())
         {
             //选中棋子与未选中的棋子,图片不同
             QPixmap* pix = ( _selectId != piece->id() ) ? _pieceNormalPix : _piecePressPix ;
             painter->drawPixmap(this->at(piece->rc()).x(),this->at(piece->rc()).y(),_pieceDiameter,_pieceDiameter,*pix);

             //设置Pen
             QPen pen = painter->pen() ;
             QColor color ;
             if( _selectId != piece->id())
                color = QColor(piece->side() ? Qt::red : Qt::black) ;
             else
                color = QColor( Qt::white ) ;
             pen.setColor(color);
             painter->setPen(pen);

             painter->drawText(QRectF(this->at(piece->rc()),QSize(_pieceDiameter,_pieceDiameter-7)),Qt::AlignCenter,piece->text());

        }//if

     }//for

}


///
/// \brief ChineseChess::_moveAStep
/// \return
/// 棋子操作函数
///
bool ChineseChess::_moveAStep(Step *step)
{
    _steps.append(step);
    if(-1!=step->_toId )
        ((ChinesePiece*)(_pieces.at(step->_toId)))->setIsAlive(false);
    _pieces.at(step->_fromId)->setRC(step->_toRC);

    (*this)[step->_fromRC]=-1 ;
    (*this)[step->_toRC]  = step->_fromId ;
    _side = !_side ;

    return true ;
}

bool ChineseChess::_backAStep(Step* step)
{

}

bool ChineseChess::_tryToMove(QPoint point)
{
    RC rc = this->getRcByPoint(point) ;
    if( (rc.r>_rNum-1 || rc.r <0 ) || (rc.c>_cNum-1 || rc.c <0 ) )
        return false ;
    qDebug()<<"RC"<<rc.r<<":"<<rc.c ;

    bool flag = false ;
    short tid = (*this)[rc] ;

    //如果一开始_selectId=-1
    if(-1==_selectId)
    {
        if(-1 != tid && (_pieces.at(tid)->side()== _side) )
            flag = true ;
    }
    else
    {
        if((-1==tid) || (_pieces.at(tid)->side()!= _side) )
        {
            Step* step = new Step(_selectId,_selectRC,tid,rc) ;
            if( _pieces.at(_selectId)->canMove(this,step) )
            {
                if(this->moveAStep(step) )
                {
                    rc  = -1 ;
                    tid = -1 ;
                    flag = true ;
                }

            }
            else
            {
                delete step ;
                flag = false ;
            }
        }
        else
        {
            flag = true ;
        }

    }

    if(flag)
    {
        _selectRC = rc ;
        _selectId = tid ;
    }

    return flag ;

}

///
/// \brief ChineseChess::getRcByPoint
/// \param point
/// \return
/// 通过point获得点击位置的r和c
///
RC ChineseChess::getRcByPoint(QPoint point)
{
    short c = (short)(point.x()/_boardRadius) ;
    short r = (short)(point.y()/_boardRadius) ;
    return RC(r,c) ;
}



/**
 * ==================================================
 * 静态函数
 * ==================================================
 */

///
/// \brief ChineseChess::setConfig
/// \param pthis 由于setConfig是静态函数
/// \param doc
///
bool ChineseChess::setConfig(void *pthis, const QDomDocument* doc)
{
//    qDebug()<<doc->toString() ;

    ChineseChess* cthis = (ChineseChess*)pthis ;

    QDomElement root = doc->documentElement() ;
    if(root.isNull() || !root.hasChildNodes() )
        return false;

    //读取棋子半径
    QDomElement pr = root.firstChildElement(QString("PieceRadius")) ;
    QString prStr = pr.text() ;
    if(prStr.isNull() || prStr.isEmpty() )
        return false ;
    cthis->_pieceRadius =  prStr.toShort() ;
    cthis->_pieceDiameter = cthis->_pieceRadius*2 ;

    //读取棋盘半径
    QDomElement br = root.firstChildElement(QString("BoardRadius")) ;
    QString brStr = br.text() ;
    if(brStr.isNull() || brStr.isEmpty() )
        return false ;
    cthis->_boardRadius = brStr.toShort() ;

    //读取背景图片
    QDomElement bbg = root.firstChildElement(QString("BoardBackground")) ;
    QString bgStr = bbg.text() ;
    if(bgStr.isNull() || bgStr.isEmpty() )
        return false ;
    cthis->setBackgroundPix(bgStr) ;

    //读取棋子图片
    QDomElement pbg = root.firstChildElement(QString("PieceBackground")) ;
    QString pbgStr = pbg.text() ;
    if(pbgStr.isNull() || pbgStr.isEmpty() )
        return false ;
    cthis->setPieceNormalPix(pbgStr);

    //读取棋子按压图片
    QDomElement ppressbg = root.firstChildElement(QString("Piece-press")) ;
    QString ppressbgStr = ppressbg.text() ;
    if(ppressbgStr.isNull() || ppressbgStr.isEmpty() )
        return false ;
    cthis->setPiecePressPix(ppressbgStr);

    return true ;

}


