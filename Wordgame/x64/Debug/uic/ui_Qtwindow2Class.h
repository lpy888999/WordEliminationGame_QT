/********************************************************************************
** Form generated from reading UI file 'Qtwindow2Class.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWINDOW2CLASS_H
#define UI_QTWINDOW2CLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qtwindow2ClassClass
{
public:
    QWidget *centralWidget;
    QPushButton *exitButton;
    QPushButton *CreatorButton;
    QPushButton *GuessButton;
    QLineEdit *input;
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *SubmitButton;
    QPushButton *usermenu;
    QProgressBar *EXP;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *Round;
    QLabel *count;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qtwindow2ClassClass)
    {
        if (Qtwindow2ClassClass->objectName().isEmpty())
            Qtwindow2ClassClass->setObjectName(QString::fromUtf8("Qtwindow2ClassClass"));
        Qtwindow2ClassClass->resize(1211, 799);
        Qtwindow2ClassClass->setStyleSheet(QString::fromUtf8("#objectname{border-image: url(:/image/b3.jpg);}"));
        centralWidget = new QWidget(Qtwindow2ClassClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(960, 10, 81, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setBold(true);
        font.setWeight(75);
        exitButton->setFont(font);
        CreatorButton = new QPushButton(centralWidget);
        CreatorButton->setObjectName(QString::fromUtf8("CreatorButton"));
        CreatorButton->setGeometry(QRect(50, 150, 161, 161));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        CreatorButton->setFont(font1);
        GuessButton = new QPushButton(centralWidget);
        GuessButton->setObjectName(QString::fromUtf8("GuessButton"));
        GuessButton->setGeometry(QRect(50, 370, 161, 161));
        GuessButton->setFont(font1);
        input = new QLineEdit(centralWidget);
        input->setObjectName(QString::fromUtf8("input"));
        input->setGeometry(QRect(390, 560, 471, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Calibri"));
        font2.setPointSize(10);
        input->setFont(font2);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(380, 170, 641, 311));
        QFont font3;
        font3.setPointSize(23);
        font3.setBold(true);
        font3.setWeight(75);
        textEdit->setFont(font3);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(470, 20, 291, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Consolas"));
        font4.setPointSize(25);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        label->setFont(font4);
        SubmitButton = new QPushButton(centralWidget);
        SubmitButton->setObjectName(QString::fromUtf8("SubmitButton"));
        SubmitButton->setGeometry(QRect(910, 560, 111, 71));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        SubmitButton->setFont(font5);
        usermenu = new QPushButton(centralWidget);
        usermenu->setObjectName(QString::fromUtf8("usermenu"));
        usermenu->setGeometry(QRect(30, 10, 71, 71));
        EXP = new QProgressBar(centralWidget);
        EXP->setObjectName(QString::fromUtf8("EXP"));
        EXP->setGeometry(QRect(30, 90, 171, 16));
        EXP->setValue(24);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 330, 111, 21));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Consolas"));
        font6.setPointSize(13);
        font6.setBold(true);
        font6.setWeight(75);
        label_2->setFont(font6);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 540, 141, 41));
        label_3->setFont(font6);
        Round = new QLabel(centralWidget);
        Round->setObjectName(QString::fromUtf8("Round"));
        Round->setGeometry(QRect(860, 129, 161, 31));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Consolas"));
        font7.setPointSize(12);
        Round->setFont(font7);
        count = new QLabel(centralWidget);
        count->setObjectName(QString::fromUtf8("count"));
        count->setGeometry(QRect(740, 640, 111, 21));
        QFont font8;
        font8.setPointSize(10);
        count->setFont(font8);
        Qtwindow2ClassClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Qtwindow2ClassClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1211, 30));
        Qtwindow2ClassClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qtwindow2ClassClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Qtwindow2ClassClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Qtwindow2ClassClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Qtwindow2ClassClass->setStatusBar(statusBar);

        retranslateUi(Qtwindow2ClassClass);

        QMetaObject::connectSlotsByName(Qtwindow2ClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *Qtwindow2ClassClass)
    {
        Qtwindow2ClassClass->setWindowTitle(QCoreApplication::translate("Qtwindow2ClassClass", "Qtwindow2Class", nullptr));
        exitButton->setText(QCoreApplication::translate("Qtwindow2ClassClass", "exit", nullptr));
        CreatorButton->setText(QString());
        GuessButton->setText(QString());
        input->setText(QString());
        input->setPlaceholderText(QCoreApplication::translate("Qtwindow2ClassClass", "your answer", nullptr));
        label->setText(QCoreApplication::translate("Qtwindow2ClassClass", "WORD GAME", nullptr));
        SubmitButton->setText(QCoreApplication::translate("Qtwindow2ClassClass", "Submit", nullptr));
        usermenu->setText(QString());
        label_2->setText(QCoreApplication::translate("Qtwindow2ClassClass", "Creator", nullptr));
        label_3->setText(QCoreApplication::translate("Qtwindow2ClassClass", "Guesser", nullptr));
        Round->setText(QString());
        count->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Qtwindow2ClassClass: public Ui_Qtwindow2ClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWINDOW2CLASS_H
