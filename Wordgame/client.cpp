#include"client.h"
#include<ws2tcpip.h>
#include<pthread.h>
#include <WinSock2.h>
#include"menu.h"
#define PASSWORD 1
#define WORD 2
#define C_INFO 3
#define G_INFO 4
#define REQ_ACC 5
#define REQ_WORD 6
#define REQ_CINFO 7
#define REQ_GINFO 8
#define NEW_WORD 9
#define RET_WORD 10
#define REQ_LIST 11
#define LIST 12
#define ACK_ONLINE 13
#define REQ_SAVE 14
#define REQ_CON 15
#define ANS_CON 16
#define CON_WORD 17
#define CON_ANS 18
#define WORD_RET 19 //服务器回答
#define ANS_RET 20 //服务器回答
#define REQ_SIG 21 //请求注册
#define ACK_SIG 22 //回复注册

int lock = 0;//新词vs.已被猜过

TcpSocket tcp;
TcpSocket::TcpSocket()
{
    this->m_fd = socket(AF_INET, SOCK_STREAM, 0);
}

TcpSocket::TcpSocket(int socket)
{
    this->m_fd = socket;
}

TcpSocket::~TcpSocket()
{
    if (m_fd > 0)
    {
        closesocket(m_fd);
    }
}

int TcpSocket::connectToHost(std::string ip, unsigned short port)
{
    // 连接服务器IP port
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    inet_pton(AF_INET, ip.data(), &saddr.sin_addr.s_addr);
    int ret = connect(m_fd, (struct sockaddr*)&saddr, sizeof(saddr));
    if (ret == -1)
    {
        perror("connect");
        return -1;
    }
    std::cout << "Seccessfully connect with server..." << std::endl;
    return ret;
}

int TcpSocket::sendMsg(int type, std::string msg)
{
    char buffer[1024] = {};

    switch (type) {
    case 0:break;//服务器回复客户端，客户端无需回复
    case PASSWORD: {
        std::ifstream ifs;
        ifs.open("user\\" + msg + "\\code.txt", ios::in);
        if (!ifs.is_open())
        {
            cout << "account do not exist!" << endl;
            send(m_fd, "0", 1, 0);
        }
        string buf;
        getline(ifs, buf);//读入密码
        ifs.close();
        buf = "0 " + buf;
        memcpy(buffer, buf.c_str(), buf.size());
        buffer[buf.size()] = '\0';
        send(m_fd, buffer, buf.size(), 0);//发送密码
        break;
    }
    case WORD: {
        msg = "0 " + RandWord();
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case C_INFO: //meg is username
    {
        string buf = "3 ";
        string tmp;
        //读nickname
        std::ifstream ifs;
        ifs.open("user\\" + msg + "\\nickname.txt", ios::in);
        if (!ifs.is_open()) {
            cout << "nickname reading error" << endl;
            send(m_fd, "0", 1, 0);
        }
        ifs >> tmp;
        buf += tmp;
        ifs.close();
        //读exp
        ifs.open("user\\" + msg + "\\Creator\\achievements.txt", ios::in);
        if (!ifs.is_open()) {
            cout << "achievements reading error" << endl;
            send(m_fd, "0", 1, 0);
        }
        for (int i = 0; i < 3; i++) {
            ifs >> tmp;
            buf = buf + " " + tmp;
        }
        memcpy(buffer, buf.c_str(), buf.size());
        buffer[buf.size()] = '\0';
        send(m_fd, buffer, buf.size(), 0);//发送Creator信息
        break;

    }
    case G_INFO: {
        string buf = "4 ";
        string tmp;
        //读nickname
        std::ifstream ifs;
        ifs.open("user\\" + msg + "\\nickname.txt", ios::in);

        if (!ifs.is_open()) {
            cout << "nickname reading error" << endl;
            send(m_fd, "0", 1, 0);
        }

        ifs >> tmp;
        buf += tmp;
        ifs.close();
        //读exp
        ifs.open("user\\" + msg + "\\Guesser\\achievements.txt", ios::in);
        if (!ifs.is_open()) {
            cout << "achievements reading error" << endl;
            send(m_fd, "0", 1, 0);
        }

        for (int i = 0; i < 3; i++) {
            ifs >> tmp;
            buf = buf + " " + tmp;
        }
        memcpy(buffer, buf.c_str(), buf.size());
        buffer[buf.size()] = '\0';
        send(m_fd, buffer, buf.size(), 0);//发送Creator信息
        break;

    }
    case REQ_ACC: {
        msg = "1 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }

    case REQ_WORD: send(m_fd, "2", 1, 0); break;
    case REQ_CINFO: {msg = "7 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case REQ_GINFO: {
        msg = "8 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case NEW_WORD: {
        msg = "9 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    };
    case RET_WORD: {
        msg = "0 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case REQ_LIST: {//请求发送所有玩家信息
        send(m_fd, "11", 2, 0); break;
    }

    case ACK_ONLINE: {
        msg = "13 " + msg;//13头表示用户登陆成功
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case REQ_SAVE: {
        send(m_fd, "14", 2, 0); break;
    }
    case REQ_CON: {//发送联机请求
        msg = "15 " + account + " " + playerid;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case CON_WORD: {
        msg = "17 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case CON_ANS: {
        msg = "18 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case REQ_SIG: {
        msg = "21 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    default: std::cout << "Msg Type error" << std::endl;
    }


}

std::string TcpSocket::recvMsg()
{
    // 接收数据
    // 1. 读数据头
    char buf[1024] = {};
    int ret = recv(m_fd, buf, sizeof(buf), 0);
    if (ret <= 0)
    {
        return std::string();
    }
    string retStr(buf);
    istringstream ss(retStr); //创建一个istringstream对象，以str作为输入源
    string tmptype; //临时字符串
    ss >> tmptype;
    if (retStr.size() > 2)
        retStr = retStr.substr(tmptype.size() + 1, retStr.length());//去掉头
        //接收信息需要的操作
    switch (atoi(tmptype.c_str())) {
    case NEW_WORD: //玩家出的新词 
    {
        int ret = AddNewWord(retStr);
        retStr = to_string(ret);
        tmptype = "10";
        break;
    }
    case C_INFO: tmptype = "0"; break;
    case G_INFO: tmptype = "0"; break;
    case LIST: {

        //先存内存PlayerList
            //拆分语义
        string tmp;
        while (ss >> tmp) {
            bool found = false;
            for (int i = 0; i < Playerlist.size(); i++) {
                if (Playerlist[i][0] == tmp) {//这个玩家存在
                    found = true;
                    // modify Playerlist[i]
                    for (int j = 1; j < Playerlist[i].size(); ++j) {
                        ss >> tmp;
                        Playerlist[i][j] = tmp;
                    }
                    break;
                }
            }
            if (!found) {//不存在该玩家,添加新项
                vector<string> Player;
                Player.push_back(tmp);
                for (int j = 1; j < 8; ++j) {
                    ss >> tmp;
                    Player.push_back(tmp);
                }
                Playerlist.push_back(Player);
            }
        }

        tmptype = "0"; //无需回复
    }
    case ACK_SIG: tmptype = "0"; break;
    default: std::cout << "No recv responce" << std::endl;
    }
    //按照头回复
    sendMsg(atoi(tmptype.c_str()), retStr);
    return retStr;
}


void Con_game(int id1, int id2) {
    
}
