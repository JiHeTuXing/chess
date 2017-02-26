#ifndef UIHELP_H
#define UIHELP_H

#include <QObject>
#include <QApplication>
#include <QtGui>
#include <QDesktopWidget>
#include"MyMessageBox.h"

class UiHelp : public QObject
{
    Q_OBJECT
public:
    //设置为开机启动
    static void AutoRunWithSystem(bool IsAutoRun, QString AppName, QString AppPath)
    {
        QSettings *reg = new QSettings(
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
            QSettings::NativeFormat);

        if (IsAutoRun) {
            reg->setValue(AppName, AppPath);
        } else {
            reg->setValue(AppName, "");
        }
    }

    //设置编码为UTF8
    static void SetUTF8Code()
    {
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForTr(codec);
#endif
    }


    //加载中文字符
    static void SetChinese()
    {
        QTranslator *translator = new QTranslator(qApp);
        translator->load(":/ui/image/qt_zh_CN.qm");
        qApp->installTranslator(translator);
    }

    //判断是否是IP地址
    static bool IsIP(QString IP)
    {
        QRegExp RegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
        return RegExp.exactMatch(IP);
    }

    //窗体居中显示
    static void FormInCenter(QWidget *frm)
    {
        int frmX = frm->width();
        int frmY = frm->height();
        QDesktopWidget w;
        int deskWidth = w.width();
        int deskHeight = w.height();
        QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
        frm->move(movePoint);
    }


    //设置皮肤样式
    static void SetStyle(QApplication *a,const QString &styleName)
    {
        QFile file(QString(":/ui/image/%1.css").arg(styleName));
        file.open(QFile::ReadOnly);
        QString qss = QLatin1String(file.readAll());
        a->setStyleSheet(qss);
        a->setPalette(QPalette(QColor("#F0F0F0")));
    }

    //延时
    static void Sleep(int sec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(sec);
        while ( QTime::currentTime() < dieTime ) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }


    /**
     *MessageBox
     */

    //显示信息框,仅确定按钮
    static int ShowMessageBoxInfo(QString info)
    {
        MyMessageBox *msg = new MyMessageBox;
        msg->setMessage(info, MyMessageBox::Info);
        return msg->exec();
    }

    //显示错误框,仅确定按钮
    static int ShowMessageBoxError(QString info)
    {
        MyMessageBox *msg = new MyMessageBox;
        msg->setMessage(info, MyMessageBox::Error);
        return msg->exec();
    }

    //显示错误框,仅确定按钮
    static int ShowMessageBoxSure(QString info)
    {
        MyMessageBox *msg = new MyMessageBox;
        msg->setMessage(info, MyMessageBox::Sure);
        return msg->exec();
    }

    //显示询问框,确定和取消按钮
    static int ShowMessageBoxQuesion(QString info)
    {
        MyMessageBox *msg = new MyMessageBox;
        msg->setMessage(info, MyMessageBox::Question);
        return msg->exec();
    }



};

#endif // UIHELP_H
