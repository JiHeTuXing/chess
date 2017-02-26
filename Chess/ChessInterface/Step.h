//
//
//
//  @ Project : Chess
//  @ File Name : Step.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//


#if !defined(_STEP_H)
#define _STEP_H

#include"RCCoordinate.h"

class Step
{
public:
	short _fromId;
    RC _fromRC ;
	short _toId;
    RC _toRC ;

public:

    /**
     * 构造函数和析构函数
     */

    //构造函数
    inline Step(){}

    Step(short fid,const RC& frc , short tid ,const RC& trc);

    Step(short fid,int frc , short tid ,int trc);

    Step(short fid,short fr, short fc, short tid ,short tr, short tc);

    //析构函数
    inline ~Step(){}

    /**
     * getter
     */

    //_fromR
    inline short fromR() const
    {
        return _fromRC.r ;
    }

    //_fromC
    inline short fromC() const
    {
        return _fromRC.c ;
    }

    //_toR
    inline short toR() const
    {
        return _toRC.r ;
    }

    //_fromC
    inline short toC() const
    {
        return _toRC.c ;
    }

};

///
/// \brief Step::Step
/// \param fid
/// \param frc
/// \param tid
/// \param trc
///
inline Step::Step(short fid,const RC& frc , short tid ,const RC& trc)
{
    this->_fromId = fid ;
    this->_toId =tid ;
    this->_fromRC = frc ;
    this->_toRC = trc ;
}

///
/// \brief Step::Step
/// \param fid
/// \param frc
/// \param tid
/// \param trc
///
inline Step::Step(short fid,int frc , short tid ,int trc)
{
    this->_fromId = fid ;
    this->_toId =tid ;
    this->_fromRC.rc = frc ;
    this->_toRC.rc = trc ;
}

///
/// \brief Step::Step
/// \param fid
/// \param fr
/// \param fc
/// \param tid
/// \param tr
/// \param tc
///
inline Step::Step(short fid,short fr, short fc, short tid ,short tr, short tc)
{
    this->_fromId = fid ;
    this->_toId =tid ;
    this->_fromRC.r = fr ;
    this->_fromRC.c = fc ;
    this->_toRC.r = tr ;
    this->_toRC.c = tc ;
}

#endif  //_STEP_H
