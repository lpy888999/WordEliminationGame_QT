/********************************************************************************
** Form generated from reading UI file 'MyQtProject1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQTPROJECT1_H
#define UI_MYQTPROJECT1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyQtProject1Class
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *username;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QPushButton *signinButton_2;
    QVBoxLayout *verticalLayout_4;
    QMenuBar *menuBar;
    QMenu *menulog;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyQtProject1Class)
    {
        if (MyQtProject1Class->objectName().isEmpty())
            MyQtProject1Class->setObjectName(QString::fromUtf8("MyQtProject1Class"));
        MyQtProject1Class->resize(214, 225);
        centralWidget = new QWidget(MyQtProject1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 211, 151));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_5->addWidget(label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        username = new QLineEdit(widget);
        username->setObjectName(QString::fromUtf8("username"));

        verticalLayout->addWidget(username);

        password = new QLineEdit(widget);
        password->setObjectName(QString::fromUtf8("password"));

        verticalLayout->addWidget(password);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        horizontalLayout->addWidget(loginButton);

        signinButton_2 = new QPushButton(widget);
        signinButton_2->setObjectName(QString::fromUtf8("signinButton_2"));

        horizontalLayout->addWidget(signinButton_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));

        verticalLayout_5->addLayout(verticalLayout_4);

        MyQtProject1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyQtProject1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 214, 21));
        menulog = new QMenu(menuBar);
        menulog->setObjectName(QString::fromUtf8("menulog"));
        MyQtProject1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyQtProject1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyQtProject1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyQtProject1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyQtProject1Class->setStatusBar(statusBar);

        menuBar->addAction(menulog->menuAction());

        retranslateUi(MyQtProject1Class);

        QMetaObject::connectSlotsByName(MyQtProject1Class);
    } // setupUi

    void retranslateUi(QMainWindow *MyQtProject1Class)
    {
        MyQtProject1Class->setWindowTitle(QCoreApplication::translate("MyQtProject1Class", "MyQtProject1", nullptr));
        label->setText(QCoreApplication::translate("MyQtProject1Class", "\347\231\273\345\205\245\345\255\246\347\224\237\346\227\245\347\250\213\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("MyQtProject1Class", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267", nullptr));
        password->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("MyQtProject1Class", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        loginButton->setText(QCoreApplication::translate("MyQtProject1Class", "\347\231\273\345\275\225", nullptr));
        signinButton_2->setText(QCoreApplication::translate("MyQtProject1Class", "\346\263\250\345\206\214", nullptr));
        menulog->setTitle(QCoreApplication::translate("MyQtProject1Class", "log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyQtProject1Class: public Ui_MyQtProject1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQTPROJECT1_H
