/********************************************************************************
** Form generated from reading UI file 'Loginwindow2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW2_H
#define UI_LOGINWINDOW2_H

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

class Ui_Loginwindow2Class
{
public:
    QWidget *centralWidget;
    QWidget *subwidget;
    QLabel *label;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *loginButton;
    QPushButton *signinButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Loginwindow2Class)
    {
        if (Loginwindow2Class->objectName().isEmpty())
            Loginwindow2Class->setObjectName(QString::fromUtf8("Loginwindow2Class"));
        Loginwindow2Class->resize(1022, 694);
        centralWidget = new QWidget(Loginwindow2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        subwidget = new QWidget(centralWidget);
        subwidget->setObjectName(QString::fromUtf8("subwidget"));
        subwidget->setGeometry(QRect(120, 60, 761, 501));
        label = new QLabel(subwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 10, 301, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("Cascadia Code SemiBold"));
        font.setPointSize(24);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        username = new QLineEdit(subwidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(250, 160, 241, 41));
        password = new QLineEdit(subwidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(250, 230, 241, 41));
        loginButton = new QPushButton(subwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(250, 320, 112, 34));
        signinButton_2 = new QPushButton(subwidget);
        signinButton_2->setObjectName(QString::fromUtf8("signinButton_2"));
        signinButton_2->setGeometry(QRect(380, 320, 112, 34));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(signinButton_2->sizePolicy().hasHeightForWidth());
        signinButton_2->setSizePolicy(sizePolicy);
        Loginwindow2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Loginwindow2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1022, 30));
        Loginwindow2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Loginwindow2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Loginwindow2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Loginwindow2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Loginwindow2Class->setStatusBar(statusBar);

        retranslateUi(Loginwindow2Class);

        QMetaObject::connectSlotsByName(Loginwindow2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Loginwindow2Class)
    {
        Loginwindow2Class->setWindowTitle(QCoreApplication::translate("Loginwindow2Class", "Loginwindow2", nullptr));
        label->setText(QCoreApplication::translate("Loginwindow2Class", "WORD GAME", nullptr));
        username->setInputMask(QString());
        username->setText(QString());
        username->setPlaceholderText(QCoreApplication::translate("Loginwindow2Class", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        password->setInputMask(QString());
        password->setPlaceholderText(QCoreApplication::translate("Loginwindow2Class", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        loginButton->setText(QCoreApplication::translate("Loginwindow2Class", "\347\231\273\345\275\225", nullptr));
        signinButton_2->setText(QCoreApplication::translate("Loginwindow2Class", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loginwindow2Class: public Ui_Loginwindow2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW2_H
