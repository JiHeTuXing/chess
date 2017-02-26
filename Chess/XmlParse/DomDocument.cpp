//
//
//
//  @ Project : Chess
//  @ File Name : DomDocument.cpp
//  @ Date : 2016/12/20
//  @ Author : limuzi
//
//
#include "DomDocument.h"
#include<QFile>
#include<QTextStream>


///
/// \brief DomDocument::DomDocument 构造函数
/// \param fn
///
DomDocument::DomDocument(QString fn)
{
    _doc = NULL ;
    _fileName = QString() ;
    this->setFileName(fn) ;
}


///
/// \brief DomDocument::setFileName 设置文件名,同时根据文件
/// \param fn
/// \return
///
bool DomDocument::setFileName(QString fn)
{
    //判断xml的名字是否有效
    if(fn.isNull() || fn.isEmpty())
        return false ;

    QString str_content="";
    //将文件中的内容读到str_content中
    if(! this->readFiletoString(fn,str_content))
        return false ;

    if(_doc==NULL)
        _doc = new QDomDocument("myXml");

    QString error ;
    int row =0 ;
    int column = 0;
    if(!_doc->setContent(str_content,false,&error,&row,&column))
    {
        //QMessage::infomation
        return false ;
    }
    else
    {
        _fileName = fn ;
        return true ;
    }

}

void DomDocument::removeDoc()
{
    if(NULL!=_doc)
    {
        delete _doc ;
        _doc = NULL ;
    }
}

bool DomDocument::readFiletoString(const QString& filename, QString &content)
{
    QFile file(filename) ;
    //文件是否打开有效
    if( !file.open( QFile::ReadOnly|QFile::Text) )
    {
        //QMessage::infomation() ;
        return false ;
    }
    else
    {
        QTextStream out(&file) ;
        content = out.readAll() ;
        file.close();
        return true ;
    }

}


bool DomDocument::readXml(void* pthis,bool (*setConfig)(void*,const QDomDocument*))
{
    return setConfig(pthis,_doc) ;
}



//bool DomDocument::readXml2()
//{
//    //获得根节点
//    QDomElement root = _doc->documentElement() ;

//    if(root.isNull() && !root.hasChildNodes() )
//      return false ;
//    QDomElement first  = root.firstChildElement(QString("Pieces")) ;
//    if(first.isNull() && !first.hasChildNodes())
//        return false ;
//    QDomElement elem = first.firstChildElement(QString("Piece"));
//    while(!elem.isNull())
//    {

//        qDebug()<<"hhh" ;
//        if(elem.hasAttribute(QString("type")))
//        {
//            if(elem.attribute("type")==QString("Jiang"))
//            {
//                QDomNodeList nlist = elem.childNodes();
//                for(int i=0;i<nlist.count() ;++i)
//                {
//                    if(nlist.at(i).isNull())
//                        return false ;
//                    if(nlist.at(i).isText())
//                        qDebug()<<"YES" ;
//                    else
//                    {
//                        qDebug()<<"NO" ;
//                        QDomNode text = nlist.at(i).firstChild() ;
//                        if(text.isNull())
//                            return false ;
//                        if(text.isText())
//                        {
//                            qDebug()<<text.toText().data() ;
//                        }
//                    }
//                }
//            }
//        }
//        elem = elem.nextSibling().toElement();
//    }
//    qDebug()<<first.nodeName() ;
//}

