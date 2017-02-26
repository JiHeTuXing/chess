/********************************************************************************
** Form generated from reading UI file 'Controlwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWIDGET_H
#define UI_CONTROLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QPushButton *peace_btn;
    QPushButton *surrender_btn;
    QPushButton *undo_btn;

    void setupUi(QWidget *ControlWidget)
    {
        if (ControlWidget->objectName().isEmpty())
            ControlWidget->setObjectName(QStringLiteral("ControlWidget"));
        ControlWidget->resize(140, 426);
        ControlWidget->setMinimumSize(QSize(140, 0));
        ControlWidget->setMaximumSize(QSize(140, 16777215));
        ControlWidget->setBaseSize(QSize(140, 0));
        verticalLayout_2 = new QVBoxLayout(ControlWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, -1, -1, 20);
        peace_btn = new QPushButton(ControlWidget);
        peace_btn->setObjectName(QStringLiteral("peace_btn"));
        peace_btn->setMinimumSize(QSize(88, 132));
        peace_btn->setMaximumSize(QSize(88, 132));
        peace_btn->setBaseSize(QSize(88, 132));
        peace_btn->setCursor(QCursor(Qt::PointingHandCursor));
        peace_btn->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/button/draw_nor.png);"));
        peace_btn->setFlat(true);

        verticalLayout_2->addWidget(peace_btn);

        surrender_btn = new QPushButton(ControlWidget);
        surrender_btn->setObjectName(QStringLiteral("surrender_btn"));
        surrender_btn->setMinimumSize(QSize(88, 132));
        surrender_btn->setMaximumSize(QSize(88, 132));
        surrender_btn->setBaseSize(QSize(88, 132));
        surrender_btn->setCursor(QCursor(Qt::PointingHandCursor));
        surrender_btn->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/button/surrender_nor.png);"));
        surrender_btn->setFlat(true);

        verticalLayout_2->addWidget(surrender_btn);

        undo_btn = new QPushButton(ControlWidget);
        undo_btn->setObjectName(QStringLiteral("undo_btn"));
        undo_btn->setMinimumSize(QSize(88, 132));
        undo_btn->setMaximumSize(QSize(88, 132));
        undo_btn->setBaseSize(QSize(88, 132));
        undo_btn->setCursor(QCursor(Qt::PointingHandCursor));
        undo_btn->setStyleSheet(QStringLiteral("border-image: url(:/chess/image/button/undo_nor.png);"));
        undo_btn->setFlat(true);

        verticalLayout_2->addWidget(undo_btn);


        retranslateUi(ControlWidget);

        QMetaObject::connectSlotsByName(ControlWidget);
    } // setupUi

    void retranslateUi(QWidget *ControlWidget)
    {
        ControlWidget->setWindowTitle(QApplication::translate("ControlWidget", "Form", 0));
        peace_btn->setText(QString());
        surrender_btn->setText(QString());
        undo_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ControlWidget: public Ui_ControlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWIDGET_H
