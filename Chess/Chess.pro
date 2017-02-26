#-------------------------------------------------
#
# Project created by QtCreator 2016-12-20T19:54:33
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ChineseChess/BingOperation.cpp \
    ChineseChess/CheOperation.cpp \
    ChineseChess/ChinesePiece.cpp \
    ChineseChess/JiangOperation.cpp \
    ChineseChess/MaOperation.cpp \
    ChineseChess/PaoOperation.cpp \
    ChineseChess/ShiOperation.cpp \
    ChineseChess/XiangOperation.cpp \
    ChessInterface/Board.cpp \
    ChineseChess/ChineseChess.cpp \
    XmlParse/DomDocument.cpp \
    GobangChess/GobangChess.cpp \
    GobangChess/GobangOperation.cpp \
    GobangChess/GobangPiece.cpp \
    Controlwidget.cpp \
    UIHelp/IconHelp.cpp \
    MyMessageBox.cpp \
    Chess.cpp

HEADERS  += mainwindow.h \
    ChessInterface/BaseChess.h \
    ChessInterface/Board.h \
    ChessInterface/ModelInterface.h \
    ChessInterface/NetworkModel.h \
    ChessInterface/Piece.h \
    ChessInterface/PieceOperation.h \
    ChessInterface/SimpleModel.h \
    ChessInterface/SingleModel.h \
    ChessInterface/Step.h \
    ChineseChess/BingOperation.h \
    ChineseChess/CheOperation.h \
    ChineseChess/ChineseChess.h \
    ChineseChess/ChinesePiece.h \
    ChineseChess/JiangOperation.h \
    ChineseChess/MaOperation.h \
    ChineseChess/PaoOperation.h \
    ChineseChess/ShiOperation.h \
    ChineseChess/XiangOperation.h \
    ChessInterface/RCCoordinate.h \
    XmlParse/DomDocument.h \
    GobangChess/GobangChess.h \
    GobangChess/GobangOperation.h \
    GobangChess/GobangPiece.h \
    Controlwidget.h \
    UIHelp/IconHelp.h \
    UIHelp/UiHelp.h \
    MyMessageBox.h \
    ChessInterface/ChessImpl.h \
    Chess.h

FORMS    += mainwindow.ui \
    Controlwidget.ui \
    MyMessageBox.ui

MOC_DIR=temp/moc
RCC_DIR=temp/rcc
UI_DIR=temp/ui
OBJECTS_DIR=temp/obj
DESTDIR=bin

RESOURCES += \
    res.qrc

RC_FILE = ico.rc
