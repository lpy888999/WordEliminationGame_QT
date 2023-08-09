#include"Server.h"
#include <pthread.h>
#include<Windows.h>
#include"menu.h"
extern vector<int> fdlist;
struct SockInfo
{
    TcpServer* s;
    TcpSocket* tcp;
    struct sockaddr_in addr;
};

void* working(void* arg)
{
    struct SockInfo* pinfo = static_cast<struct SockInfo*>(arg);
    // 连接建立成功, 打印客户端的IP和端口信息
    char ip[32];
    printf("client's IP: %s, port: %d\n",
        inet_ntop(AF_INET, &pinfo->addr.sin_addr.s_addr, ip, sizeof(ip)),
        ntohs(pinfo->addr.sin_port));

    // 5. 通信
    while (1)
    {
        printf("Accept data: .....\n");
        std::string msg = pinfo->tcp->recvMsg();
        if (!msg.empty())
        {
            std::cout << msg << std::endl << std::endl << std::endl;
        }
        else
        {
            break;
        }
    }
    delete pinfo->tcp;
    delete pinfo;
    return nullptr;
}

int main()
{
    WSADATA WSAData;

    if (WSAStartup(MAKEWORD(2, 0), &WSAData) != 0)

    {
        return FALSE;
    }
    //加载词库
    wordlib1.clear();//初始化临时列表
    wordlib2.clear();
    wordlib3.clear();
    LoadWordLib("wordlib\\wordlib1.txt", EASY);
    LoadWordLib("wordlib\\wordlib2.txt", NORMAL);
    LoadWordLib("wordlib\\wordlib3.txt", HARD);
    //加载玩家列表
    LoadPlayerList();
    // 1. 创建监听的套接字
    TcpServer s;
    // 2. 绑定本地的IP port并设置监听
    s.setListen(10000);
    // 3. 阻塞并等待客户端的连接
    while (1)
    {
        SockInfo* info = new SockInfo;
        TcpSocket* tcp = s.acceptConn(&info->addr);
        if (tcp == nullptr)
        {
            std::cout << "retry...." << std::endl;
            continue;
        }
        // 创建子线程
        pthread_t tid;
        info->s = &s;
        info->tcp = tcp;
        fdlist.push_back(tcp->m_fd);
        pthread_create(&tid, NULL, working, info);
        pthread_detach(tid);
    }

    return 0;
}
