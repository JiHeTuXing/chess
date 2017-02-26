/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *sound_action;
    QAction *action;
    QAction *actionBlue;
    QAction *actionBlack;
    QAction *actionNavy;
    QAction *actionGray;
    QAction *shot_action;
    QAction *show_action;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    QDockWidget *chat_dockWidget;
    QWidget *dockWidgetContents_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *chat_vl;
    QTextEdit *recard_text;
    QWidget *widget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *edit_vl;
    QTextEdit *edit_text;
    QHBoxLayout *send_hl;
    QPushButton *clear_btn;
    QPushButton *send_btn;
    QMenuBar *menuBar;
    QMenu *game_menu;
    QMenu *set_menu;
    QMenu *skin_menu;
    QDockWidget *main_dockWidget;
    QWidget *dockWidgetContents;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1100, 620);
        MainWindow->setMinimumSize(QSize(1100, 620));
        MainWindow->setMaximumSize(QSize(1100, 624));
        MainWindow->setBaseSize(QSize(1100, 620));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        sound_action = new QAction(MainWindow);
        sound_action->setObjectName(QStringLiteral("sound_action"));
        sound_action->setCheckable(true);
        sound_action->setChecked(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ui/image/close_sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/ui/image/open_sound.png"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QStringLiteral(":/ui/image/close_sound.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon.addFile(QStringLiteral(":/ui/image/open_sound.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon.addFile(QStringLiteral(":/ui/image/close_sound.png"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QStringLiteral(":/ui/image/open_sound.png"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QStringLiteral(":/ui/image/close_sound.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QStringLiteral(":/ui/image/open_sound.png"), QSize(), QIcon::Selected, QIcon::On);
        sound_action->setIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        actionBlue = new QAction(MainWindow);
        actionBlue->setObjectName(QStringLiteral("actionBlue"));
        actionBlack = new QAction(MainWindow);
        actionBlack->setObjectName(QStringLiteral("actionBlack"));
        actionNavy = new QAction(MainWindow);
        actionNavy->setObjectName(QStringLiteral("actionNavy"));
        actionGray = new QAction(MainWindow);
        actionGray->setObjectName(QStringLiteral("actionGray"));
        shot_action = new QAction(MainWindow);
        shot_action->setObjectName(QStringLiteral("shot_action"));
        show_action = new QAction(MainWindow);
        show_action->setObjectName(QStringLiteral("show_action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        chat_dockWidget = new QDockWidget(MainWindow);
        chat_dockWidget->setObjectName(QStringLiteral("chat_dockWidget"));
        chat_dockWidget->setMinimumSize(QSize(300, 563));
        chat_dockWidget->setMaximumSize(QSize(300, 563));
        chat_dockWidget->setBaseSize(QSize(300, 563));
        chat_dockWidget->setFloating(false);
        chat_dockWidget->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetVerticalTitleBar);
        chat_dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayoutWidget = new QWidget(dockWidgetContents_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-10, -10, 302, 597));
        chat_vl = new QVBoxLayout(verticalLayoutWidget);
        chat_vl->setSpacing(6);
        chat_vl->setContentsMargins(11, 11, 11, 11);
        chat_vl->setObjectName(QStringLiteral("chat_vl"));
        chat_vl->setSizeConstraint(QLayout::SetDefaultConstraint);
        chat_vl->setContentsMargins(0, 12, 0, 10);
        recard_text = new QTextEdit(verticalLayoutWidget);
        recard_text->setObjectName(QStringLiteral("recard_text"));
        recard_text->setMinimumSize(QSize(280, 374));
        recard_text->setMaximumSize(QSize(280, 374));
        recard_text->setBaseSize(QSize(280, 374));
        recard_text->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/chat/comment_bg.png);"));

        chat_vl->addWidget(recard_text);

        widget = new QWidget(verticalLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(280, 187));
        widget->setMaximumSize(QSize(280, 187));
        widget->setBaseSize(QSize(280, 187));
        verticalLayoutWidget_2 = new QWidget(widget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 0, 300, 189));
        edit_vl = new QVBoxLayout(verticalLayoutWidget_2);
        edit_vl->setSpacing(6);
        edit_vl->setContentsMargins(11, 11, 11, 11);
        edit_vl->setObjectName(QStringLiteral("edit_vl"));
        edit_vl->setContentsMargins(0, 0, 15, 0);
        edit_text = new QTextEdit(verticalLayoutWidget_2);
        edit_text->setObjectName(QStringLiteral("edit_text"));
        edit_text->setMinimumSize(QSize(270, 0));
        edit_text->setMaximumSize(QSize(270, 16777215));
        edit_text->setSizeIncrement(QSize(0, 0));
        edit_text->setBaseSize(QSize(270, 187));
        edit_text->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/chat/chat_book_bg.png);"));

        edit_vl->addWidget(edit_text);

        send_hl = new QHBoxLayout();
        send_hl->setSpacing(6);
        send_hl->setObjectName(QStringLiteral("send_hl"));
        send_hl->setContentsMargins(-1, -1, 15, 15);
        clear_btn = new QPushButton(verticalLayoutWidget_2);
        clear_btn->setObjectName(QStringLiteral("clear_btn"));
        clear_btn->setMinimumSize(QSize(0, 40));
        clear_btn->setMaximumSize(QSize(16777215, 40));
        clear_btn->setBaseSize(QSize(0, 40));

        send_hl->addWidget(clear_btn);

        send_btn = new QPushButton(verticalLayoutWidget_2);
        send_btn->setObjectName(QStringLiteral("send_btn"));
        send_btn->setMinimumSize(QSize(0, 40));
        send_btn->setMaximumSize(QSize(16777215, 40));
        send_btn->setBaseSize(QSize(0, 40));

        send_hl->addWidget(send_btn);


        edit_vl->addLayout(send_hl);


        chat_vl->addWidget(widget);

        chat_dockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), chat_dockWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 27));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        menuBar->setFont(font1);
        menuBar->setLayoutDirection(Qt::LeftToRight);
        menuBar->setStyleSheet(QStringLiteral(""));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        game_menu = new QMenu(menuBar);
        game_menu->setObjectName(QStringLiteral("game_menu"));
        set_menu = new QMenu(menuBar);
        set_menu->setObjectName(QStringLiteral("set_menu"));
        set_menu->setGeometry(QRect(374, 107, 128, 105));
        set_menu->setLayoutDirection(Qt::LeftToRight);
        set_menu->setTearOffEnabled(false);
        set_menu->setSeparatorsCollapsible(false);
        set_menu->setToolTipsVisible(false);
        skin_menu = new QMenu(set_menu);
        skin_menu->setObjectName(QStringLiteral("skin_menu"));
        skin_menu->setTearOffEnabled(false);
        skin_menu->setToolTipsVisible(true);
        MainWindow->setMenuBar(menuBar);
        main_dockWidget = new QDockWidget(MainWindow);
        main_dockWidget->setObjectName(QStringLiteral("main_dockWidget"));
        main_dockWidget->setMinimumSize(QSize(200, 563));
        main_dockWidget->setMaximumSize(QSize(200, 563));
        main_dockWidget->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetVerticalTitleBar);
        main_dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayoutWidget_3 = new QWidget(dockWidgetContents);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 110, 1802, 565));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(dockWidgetContents);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(-10, -20, 180, 563));
        listWidget->setMinimumSize(QSize(180, 563));
        listWidget->setMaximumSize(QSize(180, 563));
        listWidget->setBaseSize(QSize(180, 563));
        main_dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), main_dockWidget);

        menuBar->addAction(game_menu->menuAction());
        menuBar->addAction(set_menu->menuAction());
        game_menu->addAction(shot_action);
        game_menu->addAction(show_action);
        set_menu->addAction(skin_menu->menuAction());
        set_menu->addSeparator();
        set_menu->addAction(sound_action);
        skin_menu->addAction(actionBlue);
        skin_menu->addAction(actionBlack);
        skin_menu->addAction(actionNavy);
        skin_menu->addAction(actionGray);

        retranslateUi(MainWindow);
        QObject::connect(clear_btn, SIGNAL(clicked()), edit_text, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        sound_action->setText(QApplication::translate("MainWindow", "\351\237\263\346\225\210", 0));
        action->setText(QApplication::translate("MainWindow", "--", 0));
        actionBlue->setText(QApplication::translate("MainWindow", "Blue", 0));
        actionBlack->setText(QApplication::translate("MainWindow", "Black", 0));
        actionNavy->setText(QApplication::translate("MainWindow", "Navy", 0));
        actionGray->setText(QApplication::translate("MainWindow", "Gray", 0));
        shot_action->setText(QApplication::translate("MainWindow", "\346\210\252\345\233\276", 0));
        show_action->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0));
        clear_btn->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0));
        send_btn->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        game_menu->setTitle(QApplication::translate("MainWindow", "\346\270\270\346\210\217(&G)", 0));
        set_menu->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256(&S)", 0));
        skin_menu->setTitle(QApplication::translate("MainWindow", "\346\215\242\350\202\244", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
