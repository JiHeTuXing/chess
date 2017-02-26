#include "mainwindow.h"
#include <QApplication>
#include"UIHelp/UiHelp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UiHelp::SetUTF8Code() ;
    UiHelp::SetChinese() ;
    UiHelp::SetStyle(&a,"black") ;

    MainWindow w;
    w.show();

    return a.exec();
}
