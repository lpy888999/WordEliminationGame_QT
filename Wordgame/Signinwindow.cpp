#include "Signinwindow.h"

Signinwindow::Signinwindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Signinwindow::~Signinwindow()
{}

void Signinwindow::Signin() {
    ui.subwidget->setAttribute(Qt::WA_StyledBackground);
    ui.subwidget->setStyleSheet("QWidget{background-color: white; border-top-left-radius:15px; border-top-right-radius:15px; border-bottom-left-radius:15px; border-bottom-right-radius:15px;}");
    ui.centralWidget->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(253, 185, 39, 200), stop:1 rgba(85, 37, 130, 210));");
    ui.label->setStyleSheet("font: 22 14pt '微软雅黑 Light';" //字体
        "color: black;"		//字体颜色
        "padding-left:20px;"       //内边距-字体缩进
        "background-color: rgb(255, 255, 255);" //背景颜色
    );//边框粗细-颜色-圆角设置 
    ui.label_2->setStyleSheet("font: 22 14pt '微软雅黑 Light';" //字体
        "color: black;"		//字体颜色
        "padding-left:20px;"       //内边距-字体缩进
        "background-color: rgb(255, 255, 255);" //背景颜色
    );//边框粗细-颜色-圆角设置 
    ui.label_3->setStyleSheet("font: 22 14pt '微软雅黑 Light';" //字体
        "color: black;"		//字体颜色
        "padding-left:20px;"       //内边距-字体缩进
        "background-color: rgb(255, 255, 255);" //背景颜色
    );//边框粗细-颜色-圆角设置 
    ui.username->setStyleSheet("font: 25 14pt '微软雅黑 Light';" //字体
        "color: rgb(31,31,31);"		//字体颜色
        "padding-left:20px;"       //内边距-字体缩进
        "background-color: rgb(255, 255, 255);" //背景颜色
        "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置 
    ui.password->setStyleSheet("font: 25 14pt '微软雅黑 Light';" //字体
        "color: rgb(31,31,31);"		//字体颜色
        "padding-left:20px;"       //内边距-字体缩进
        "background-color: rgb(255, 255, 255);" //背景颜色
        "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置 
    ui.nickname->setStyleSheet("font: 25 14pt '微软雅黑 Light';" //字体
        "color: rgb(31,31,31);"		//字体颜色
        "padding-left:20px;"       //内边距-字体缩进
        "background-color: rgb(255, 255, 255);" //背景颜色
        "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置 
    ui.SigninButton->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 Light';color: rgb(255,255,255);background-color: rgb(20,196,188);"
        "border: none;border-radius:15px;}"
        "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
        "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    this->show();
    connect(ui.SigninButton, &QPushButton::clicked, this, [=]() {
        account = ui.username->text().toStdString();
        std::string password = ui.password->text().toStdString();
        std::string nickname = ui.nickname->text().toStdString();
        //DM dm(account);//账号文件管理对象
        string msg = account + " " + password + " " + nickname;
          tcp.sendMsg(21, msg);
         //登陆成功则切换窗口
          string ret1 = tcp.recvMsg();
        if (ret1 == "Y")//注册成功 
        {
            QMessageBox::information(this, "注册", "注册成功");
            this->hide();
        }
        else {//登录失败弹窗提示
            QMessageBox::information(this, "注册", "注册失败：账号已存在");
        }
    });
}