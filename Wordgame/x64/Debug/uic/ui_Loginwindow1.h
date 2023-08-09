/********************************************************************************
** Form generated from reading UI file 'Loginwindow1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW1_H
#define UI_LOGINWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *subwidget;
    QLabel *label;
    QLineEdit *username;
    QPushButton *loginButton;
    QPushButton *signinButton_2;
    QLineEdit *password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        subwidget = new QWidget(centralwidget);
        subwidget->setObjectName(QString::fromUtf8("subwidget"));
        subwidget->setGeometry(QRect(110, 60, 611, 411));
        label = new QLabel(subwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 0, 251, 131));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(22);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        username = new QLineEdit(subwidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(150, 120, 301, 61));
        loginButton = new QPushButton(subwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(150, 320, 121, 41));
        signinButton_2 = new QPushButton(subwidget);
        signinButton_2->setObjectName(QString::fromUtf8("signinButton_2"));
        signinButton_2->setGeometry(QRect(320, 320, 131, 41));
        password = new QLineEdit(subwidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(150, 220, 301, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Word Game", nullptr));
        username->setText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        signinButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        password->setText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW1_H
