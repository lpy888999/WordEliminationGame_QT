/********************************************************************************
** Form generated from reading UI file 'UserMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMENU_H
#define UI_USERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMenuClass
{
public:
    QWidget *centralWidget;
    QLineEdit *nickname;
    QListWidget *listWidget;
    QLabel *profile;
    QPushButton *key;
    QLineEdit *findline;
    QPushButton *find;
    QLabel *CreatorLV;
    QLabel *Total_Word;
    QLabel *GuesserLV;
    QLabel *Round;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UserMenuClass)
    {
        if (UserMenuClass->objectName().isEmpty())
            UserMenuClass->setObjectName(QString::fromUtf8("UserMenuClass"));
        UserMenuClass->resize(1066, 926);
        centralWidget = new QWidget(UserMenuClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        nickname = new QLineEdit(centralWidget);
        nickname->setObjectName(QString::fromUtf8("nickname"));
        nickname->setGeometry(QRect(40, 100, 181, 41));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(270, 100, 691, 721));
        profile = new QLabel(centralWidget);
        profile->setObjectName(QString::fromUtf8("profile"));
        profile->setGeometry(QRect(40, 10, 71, 71));
        key = new QPushButton(centralWidget);
        key->setObjectName(QString::fromUtf8("key"));
        key->setGeometry(QRect(270, 60, 101, 31));
        findline = new QLineEdit(centralWidget);
        findline->setObjectName(QString::fromUtf8("findline"));
        findline->setGeometry(QRect(630, 60, 201, 31));
        find = new QPushButton(centralWidget);
        find->setObjectName(QString::fromUtf8("find"));
        find->setGeometry(QRect(860, 60, 101, 31));
        CreatorLV = new QLabel(centralWidget);
        CreatorLV->setObjectName(QString::fromUtf8("CreatorLV"));
        CreatorLV->setGeometry(QRect(30, 180, 231, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(13);
        CreatorLV->setFont(font);
        Total_Word = new QLabel(centralWidget);
        Total_Word->setObjectName(QString::fromUtf8("Total_Word"));
        Total_Word->setGeometry(QRect(30, 240, 191, 31));
        Total_Word->setFont(font);
        GuesserLV = new QLabel(centralWidget);
        GuesserLV->setObjectName(QString::fromUtf8("GuesserLV"));
        GuesserLV->setGeometry(QRect(30, 300, 191, 31));
        GuesserLV->setFont(font);
        Round = new QLabel(centralWidget);
        Round->setObjectName(QString::fromUtf8("Round"));
        Round->setGeometry(QRect(30, 360, 191, 31));
        Round->setFont(font);
        UserMenuClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UserMenuClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1066, 30));
        UserMenuClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UserMenuClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UserMenuClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UserMenuClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UserMenuClass->setStatusBar(statusBar);

        retranslateUi(UserMenuClass);

        QMetaObject::connectSlotsByName(UserMenuClass);
    } // setupUi

    void retranslateUi(QMainWindow *UserMenuClass)
    {
        UserMenuClass->setWindowTitle(QCoreApplication::translate("UserMenuClass", "UserMenu", nullptr));
        nickname->setText(QString());
        profile->setText(QString());
        key->setText(QCoreApplication::translate("UserMenuClass", "\351\200\211\351\241\271", nullptr));
        find->setText(QCoreApplication::translate("UserMenuClass", "\346\237\245\346\211\276", nullptr));
        CreatorLV->setText(QString());
        Total_Word->setText(QString());
        GuesserLV->setText(QString());
        Round->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserMenuClass: public Ui_UserMenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMENU_H
