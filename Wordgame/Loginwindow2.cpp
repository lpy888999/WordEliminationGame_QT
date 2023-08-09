#include "Loginwindow2.h"


Loginwindow2::Loginwindow2(QWidget *parent)
	: QMainWindow(parent)
{
    ui.setupUi(this);
    //子窗口背景颜色与圆边框
    ui.subwidget->setAttribute(Qt::WA_StyledBackground);
    ui.subwidget->setStyleSheet("QWidget{background-color: white; border-top-left-radius:15px; border-top-right-radius:15px; border-bottom-left-radius:15px; border-bottom-right-radius:15px;}");

    //设置子窗口边框
    //ui.subwidget->setStyleSheet(QString::fromUtf8("border:1px solid white"));
    ui.centralWidget->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(253, 185, 39, 200), stop:1 rgba(85, 37, 130, 210));");

    //设置界面字体
    ui.label->setStyleSheet("font: 22 14pt '微软雅黑 Light';" //字体
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
    ui.loginButton->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 Light';color: rgb(255,255,255);background-color: rgb(20,196,188);"
        "border: none;border-radius:15px;}"
        "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
        "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    ui.signinButton_2->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 Light';color: rgb(255,255,255);background-color: rgb(20,196,188);"
        "border: none;border-radius:15px;}"
        "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
        "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    //接受用户输入
    //登录键被点击
    connect(ui.loginButton, &QPushButton::clicked, this, [=]() {
        account = ui.username->text().toStdString();
        std::string password1 = ui.password->text().toStdString();

        //向服务器发送账号
        tcp.sendMsg(5,account);
        std::string password = tcp.recvMsg();

         //登陆成功则切换窗口
        if (password == password1)//登录成功 
        {
            this->hide();

            Qtwindow2Class* w2 = new Qtwindow2Class();
            w2->setWindowTitle("WORD GAME");
            //连接自定义退出信号与登录界面重现槽函数，实现从主界面退出到登录界面
            connect(w2, SIGNAL(sendsignal()), this, SLOT(reshow()));

            w2->show();//显示窗口
        }
        else {//登录失败弹窗提示
            QMessageBox::information(this, "登录", "登陆失败：账户或密码错误!!");
        }
        });
    //注册界面
    w0 = new Signinwindow();
    //注册键被点击
    connect(ui.signinButton_2, SIGNAL(clicked()), this->w0, SLOT(Signin()));
}

Loginwindow2::~Loginwindow2()
{}

void Loginwindow2::reshow() {
    Round = 1;
    this->show();
};