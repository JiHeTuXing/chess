#include "IconHelp.h"

//初始化静态变量
IconHelp* IconHelp::_instance = NULL ;

IconHelp::IconHelp(QObject *parent) : QObject(parent)
{
    int fontId = QFontDatabase::addApplicationFont(QStringLiteral(":/ui/image/fontawesome-webfont.ttf")) ;
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0) ;
    _icoFont = QFont(fontName) ;

}

IconHelp::~IconHelp()
{

}

void IconHelp::SetIcon(QLabel *lab, QChar c, int size)
{
    _icoFont.setPointSize(size);
    lab->setFont(_icoFont);
    lab->setText(c);
}

void IconHelp::SetIcon(QPushButton *btn, QChar c, int size)
{
    _icoFont.setPointSize(size);
    btn->setFont(_icoFont);
    btn->setText(c);
}

