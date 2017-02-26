#ifndef RCCOORDINATE_H
#define RCCOORDINATE_H

struct RC
{
    union{

        struct
        {
            short r;
            short c;
        };

        int rc ;
    };

    /**
     * 构造函数和析构函数
     */

    inline RC(){}

    inline RC(int rc){ this->rc = rc ; }

    inline RC(short r , short c){ this->r =r ; this->c =c ;}

    inline RC(const RC& rc){ this->rc =rc.rc ; }

    ~RC(){}

    /**
     * 运算符重载
     */

    RC& operator = (const RC& rc){this->rc = rc.rc; return *this; }

    RC& operator = (int rc){this->rc = rc ; return *this ;}

    bool operator == (const RC& rc){return rc.rc==this->rc ; }


};

#endif // RCCOORDINATE_H

