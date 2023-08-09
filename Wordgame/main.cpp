#include "Loginwindow2.h"
#include <QtWidgets/QApplication>
#include"client.h"

int main(int argc, char *argv[])
{
    WSADATA WSAData;

    if (WSAStartup(MAKEWORD(2, 0), &WSAData) != 0)

    {
        return FALSE;
    }
    // 1. 创建通信的套接字
    TcpSocket tcp1;
    tcp.m_fd = tcp1.m_fd;
    //初始化WinSock

    // 2. 连接服务器IP port
    int ret = tcp.connectToHost("127.0.0.1", 10000);
    if (ret == -1)
    {
        return -1;
    }

    QApplication a(argc, argv);
    Loginwindow2 w; //登录窗口
    w.setWindowTitle("LOG IN");
    w.show();
    return a.exec();

    //WSACleanup();
}
/*
Qmessagebox 使用弹出登录成功或者失败的提示弹窗
*/
/*窗口切换 添加新Qwidget类再设计一个界面
 在第一个窗口cpp中：
    this ->hide 隐藏主窗口
    new一个新类第二个窗口
    显示第二个窗口w.show()
*/

/*时间系统：
设置Qtimer 定时器
QDateTime 日期时间类型(可与Qstring 转换)
按间隔更新datetimeedit？setDateTime( QDateTime )

使用槽：关联信号被发射 槽就会调用


*/

/*多级菜单：
QMenu 与 QAction
*/