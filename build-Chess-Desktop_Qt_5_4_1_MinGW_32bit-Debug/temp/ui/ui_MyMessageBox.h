/********************************************************************************
** Form generated from reading UI file 'MyMessageBox.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMESSAGEBOX_H
#define UI_MYMESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMessageBox
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *title_widget;
    QHBoxLayout *horizontalLayout;
    QLabel *ico_label;
    QLabel *title_label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *close_btn;
    QWidget *main_widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLabel *ico2_label;
    QLabel *content_label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *sure_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancle_btn;

    void setupUi(QDialog *MyMessageBox)
    {
        if (MyMessageBox->objectName().isEmpty())
            MyMessageBox->setObjectName(QStringLiteral("MyMessageBox"));
        MyMessageBox->resize(380, 200);
        MyMessageBox->setSizeGripEnabled(false);
        MyMessageBox->setModal(false);
        verticalLayout_2 = new QVBoxLayout(MyMessageBox);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        title_widget = new QWidget(MyMessageBox);
        title_widget->setObjectName(QStringLiteral("title_widget"));
        horizontalLayout = new QHBoxLayout(title_widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ico_label = new QLabel(title_widget);
        ico_label->setObjectName(QStringLiteral("ico_label"));
        ico_label->setMinimumSize(QSize(31, 0));
        ico_label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(ico_label);

        title_label = new QLabel(title_widget);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        title_label->setFont(font);

        horizontalLayout->addWidget(title_label);

        widget = new QWidget(title_widget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        close_btn = new QPushButton(widget);
        close_btn->setObjectName(QStringLiteral("close_btn"));
        close_btn->setFlat(true);

        horizontalLayout_2->addWidget(close_btn);


        horizontalLayout->addWidget(widget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 8);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_2->addWidget(title_widget);

        main_widget = new QWidget(MyMessageBox);
        main_widget->setObjectName(QStringLiteral("main_widget"));
        verticalLayout = new QVBoxLayout(main_widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(main_widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        ico2_label = new QLabel(groupBox);
        ico2_label->setObjectName(QStringLiteral("ico2_label"));
        ico2_label->setGeometry(QRect(20, 10, 71, 71));
        ico2_label->setStyleSheet(QStringLiteral("border-image: url(:/ui/image/dialog/sure.png);"));
        ico2_label->setAlignment(Qt::AlignCenter);
        content_label = new QLabel(groupBox);
        content_label->setObjectName(QStringLiteral("content_label"));
        content_label->setGeometry(QRect(110, 30, 211, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        content_label->setFont(font1);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 90, 361, 71));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sure_btn = new QPushButton(horizontalLayoutWidget);
        sure_btn->setObjectName(QStringLiteral("sure_btn"));
        sure_btn->setMinimumSize(QSize(100, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        sure_btn->setFont(font2);
        sure_btn->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(sure_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        cancle_btn = new QPushButton(horizontalLayoutWidget);
        cancle_btn->setObjectName(QStringLiteral("cancle_btn"));
        cancle_btn->setMinimumSize(QSize(100, 40));
        cancle_btn->setFont(font2);
        cancle_btn->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(cancle_btn);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout->addWidget(groupBox);


        verticalLayout_2->addWidget(main_widget);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 5);

        retranslateUi(MyMessageBox);

        QMetaObject::connectSlotsByName(MyMessageBox);
    } // setupUi

    void retranslateUi(QDialog *MyMessageBox)
    {
        MyMessageBox->setWindowTitle(QApplication::translate("MyMessageBox", "Dialog", 0));
        ico_label->setText(QString());
        title_label->setText(QApplication::translate("MyMessageBox", "\346\217\220\347\244\272", 0));
        close_btn->setText(QString());
        groupBox->setTitle(QString());
        ico2_label->setText(QString());
        content_label->setText(QApplication::translate("MyMessageBox", "Infomation", 0));
        sure_btn->setText(QApplication::translate("MyMessageBox", "\347\241\256\345\256\232", 0));
        cancle_btn->setText(QApplication::translate("MyMessageBox", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class MyMessageBox: public Ui_MyMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMESSAGEBOX_H
