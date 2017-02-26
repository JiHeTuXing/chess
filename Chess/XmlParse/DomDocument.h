//
//
//
//  @ Project : Chess
//  @ File Name : DomDocument.h
//  @ Date : 2016/12/20
//  @ Author : limuzi
//

#ifndef DOMDOCUMENT_H
#define DOMDOCUMENT_H

#include<QString>
#include<QDomDocument>

class DomDocument
{

private:

    QString _fileName ; //文件名

    QDomDocument* _doc ;//文档

protected:
    void removeDoc() ;
public:

    /**
     *构造函数与析构函数
     */

    DomDocument(QString fn);

    inline ~DomDocument(){this->removeDoc();}

    /**
     * setter and getter
     */

    bool setFileName(QString fn) ;

    inline QString fileName(){return _fileName ;}


    inline QString toString()
    {
        if(_doc!=NULL)
            return _doc->toString();
        else
            return QString() ;
    }

    /**
     * operation function
     */

    bool readFiletoString(const QString& filename, QString& content);//将文件读成字符串

    ///
    /// \brief readXml
    /// \param pthis
    ///     pthis指针:含有DomDocument的类的类对象指针
    ///     setConfig:为pthis的静态函数
    /// \return
    ///
    bool readXml( void* pthis,bool (*setConfig)(void*,const QDomDocument*) );//读取xml

};

#endif // DOMDOCUMENT_H
