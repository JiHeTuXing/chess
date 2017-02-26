#ifndef ICONHELP_H
#define ICONHELP_H

#include <QObject>
#include<QFont>
#include<QMutex>
#include<QFontDatabase>
#include<QLabel>
#include<QPushButton>

class IconHelp : public QObject
{
    Q_OBJECT

public:
    QFont _icoFont ;
    static IconHelp* _instance ;

public:
    explicit IconHelp(QObject *parent = 0);
    ~IconHelp();

public:
    static IconHelp* instance()
    {
        static QMutex mutex ;
        if(!_instance)
        {
            QMutexLocker locker(&mutex) ;
            if(!_instance)
            {
                _instance = new IconHelp ;
            }
        }
        return _instance ;
    }

    void SetIcon(QLabel* lab, QChar c, int size = 10);
    void SetIcon(QPushButton* btn, QChar c, int size = 10);

};

#endif // ICONHELP_H
