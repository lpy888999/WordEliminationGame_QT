/********************************************************************************
** Form generated from reading UI file 'Signinwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINWINDOW_H
#define UI_SIGNINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SigninwindowClass
{
public:
    QWidget *centralWidget;
    QWidget *subwidget;
    QLineEdit *username;
    QLineEdit *password;
    QLineEdit *nickname;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *SigninButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SigninwindowClass)
    {
        if (SigninwindowClass->objectName().isEmpty())
            SigninwindowClass->setObjectName(QString::fromUtf8("SigninwindowClass"));
        SigninwindowClass->resize(775, 788);
        centralWidget = new QWidget(SigninwindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        subwidget = new QWidget(centralWidget);
        subwidget->setObjectName(QString::fromUtf8("subwidget"));
        subwidget->setGeometry(QRect(90, 90, 581, 551));
        username = new QLineEdit(subwidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(160, 110, 281, 51));
        password = new QLineEdit(subwidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(160, 190, 281, 51));
        nickname = new QLineEdit(subwidget);
        nickname->setObjectName(QString::fromUtf8("nickname"));
        nickname->setGeometry(QRect(160, 270, 281, 51));
        label = new QLabel(subwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 100, 101, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(subwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 180, 91, 71));
        label_2->setFont(font);
        label_3 = new QLabel(subwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 260, 101, 81));
        label_3->setFont(font);
        label_4 = new QLabel(subwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 0, 441, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        SigninButton = new QPushButton(subwidget);
        SigninButton->setObjectName(QString::fromUtf8("SigninButton"));
        SigninButton->setGeometry(QRect(240, 360, 112, 34));
        QFont font2;
        font2.setPointSize(11);
        SigninButton->setFont(font2);
        SigninwindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SigninwindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 775, 30));
        SigninwindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SigninwindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SigninwindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SigninwindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SigninwindowClass->setStatusBar(statusBar);

        retranslateUi(SigninwindowClass);

        QMetaObject::connectSlotsByName(SigninwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SigninwindowClass)
    {
        SigninwindowClass->setWindowTitle(QCoreApplication::translate("SigninwindowClass", "Signinwindow", nullptr));
        label->setText(QCoreApplication::translate("SigninwindowClass", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("SigninwindowClass", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("SigninwindowClass", "\346\230\265\347\247\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("SigninwindowClass", "SIGN IN NOW TO WORD GAME!", nullptr));
        SigninButton->setText(QCoreApplication::translate("SigninwindowClass", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SigninwindowClass: public Ui_SigninwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINWINDOW_H
