#pragma once
#include"Server.h"
#include"menu.h"

#define PASSWORD 1
#define WORD 2
#define C_INFO 3
#define G_INFO 4
#define REQ_ACC 5
#define REQ_WORD 6
#define REQ_CINFO 7
#define REQ_GINFO 8
#define NEW_WORD 9//单机玩家添加
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

int lock = 0;
vector<int> fdlist;

struct m_info {
        string username;
        string nickname;
        string id;
};
vector<struct m_info> c_matchlist;
vector<struct m_info> g_matchlist;

TcpSocket::TcpSocket()
{
    m_fd = socket(AF_INET, SOCK_STREAM, 0);
}

TcpSocket::TcpSocket(int socket)
{
    m_fd = socket;
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
    std::cout << "Successfully connect with server..." << std::endl;
    return ret;
}

int TcpSocket::sendMsg(int type, std::string msg)
{
    char buffer[1024] = {};

    switch (type) {
    case 0:break;//服务器回复客户端，客户端无需回复
    case PASSWORD: {
        string nickname;
        ifstream ifs("user//" + msg + "//nickname.txt");
        ifs >> nickname;
        if (OnlinePlayer.find(nickname) == OnlinePlayer.end()) {

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
        }
        else  send(m_fd, "0 0000", 4, 0);//发送密码
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
        string buf = "0 ";
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
        //0 nickname exp lev num
        string buf = "0 ";
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
    case REQ_CINFO: {msg = "3 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case REQ_GINFO: {
        msg = "4 " + msg;
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

    case LIST: {
        msg = "12 ";
        for (int i = 0; i < Playerlist.size(); ++i) {
            for (int j = 0; j < 7; ++j) {//添加这条
                msg +=  Playerlist[i][j] + " ";
            }
            if (OnlinePlayer.find(Playerlist[i][0]) == OnlinePlayer.end()) {//该玩家不在线
                msg += "0 ";
            }
            else msg += "1 ";
            //发送
        }
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case ACK_ONLINE: {
        msg = "13 " + msg;//13头表示用户登陆成功
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }
    case ANS_CON: {
        msg = "16 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        send(m_fd, buffer, msg.size(), 0);
        break;
    }

    case WORD_RET: {//向另外一个玩家发送信息
        msg = "19 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        if(m_fd == fdlist[0]) send(fdlist[1], buffer, msg.size(), 0);
        else send(fdlist[0], buffer, msg.size(), 0);
        break;
    }
    case ANS_RET: {//向另外一个玩家发送信息
        msg = "20 " + msg;
        memcpy(buffer, msg.c_str(), msg.size());
        buffer[msg.size()] = '\0';
        if (m_fd == fdlist[0]) send(fdlist[1], buffer, msg.size(), 0);
        else send(fdlist[0], buffer, msg.size(), 0);
        break;
    }
    case ACK_SIG: {
        msg = "22 " + msg;
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
    if(retStr.size() > 2)
    retStr = retStr.substr(tmptype.size()+1, retStr.length());//去掉头
    //接收信息需要的操作
    switch (atoi(tmptype.c_str())) {
    case NEW_WORD: //玩家出的新词 
    {
        int ret = AddNewWord(retStr);
        retStr = to_string(ret);
        tmptype = "10";
        break;
    }
    case C_INFO: {//接收到客户端的信息，需要更新Playerlist
        //retStr = nickname + exp + lev + num
        string tmpstr1;
        ss >> tmpstr1;
        for (int i = 0; i < Playerlist.size(); i++) {
            if (Playerlist[i][0] == tmpstr1) {//这个玩家存在
                // modify Playerlist[i]
                for (int j = 1; ss >> tmpstr1 && j <= 3; ++j) {
                    Playerlist[i][j] = tmpstr1;
                }
                break;
            }
        }
        tmptype = "0";
        break;  
    }
    case G_INFO: {        
        string tmpstr2;
        ss >> tmpstr2;
        for (int i = 0; i < Playerlist.size(); i++) {
            if (Playerlist[i][0] == tmpstr2) {//这个玩家存在
                // modify Playerlist[i]
                for (int j = 4; ss >> tmpstr2 && j <= 6; ++j) {
                    Playerlist[i][j] = tmpstr2;
                }
                break;
            }
        }
        tmptype = "0";
        break; 
    }
    case REQ_CINFO: tmptype = "3"; break;
    case REQ_GINFO: tmptype = "4"; break;
    case REQ_LIST: tmptype = "12"; break;
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
    case ACK_ONLINE: {//若在线用户列表没有，添加到在线用户列表；若存在，则表明下线
        if (OnlinePlayer.find(retStr) == OnlinePlayer.end()) {
            OnlinePlayer.emplace(retStr, "");
        }
       // else {
           //OnlinePlayer.erase(retStr);
       // }
        tmptype = "0"; //无需回复
        break;
    }
    case REQ_SAVE:
    {
        StoreWordLib();
        SavePlayerList();
        tmptype = "0";
        break;
    }
    case REQ_CON: {//接收联机请求
        tmptype = 16;//ANS
        struct m_info m;
        ss >> m.username;
        ifstream inFile("user\\" +m.username +"\\nickname.txt", ios::in);
        if (!inFile) std::cout << "error!" << std::endl;
        else {
            inFile >> m.nickname;
        }
        inFile.close();

        //根据身份匹配
        ss >> m.id;
        if (m.id == "1") {//此人是Creater //&& find_if(c_matchlist.begin(), c_matchlist.end(), [](auto& p) { return p.nickname == m.nickname; } == c_matchlist.end()
            if (g_matchlist.size() == 0 ) {
                c_matchlist.push_back(m);
                retStr = "0";//未匹配成功
            }
            else {
                OnlinePlayer[m.nickname] = g_matchlist[0].nickname;
                OnlinePlayer[g_matchlist[0].nickname] = m.nickname;
                retStr = "1 " + g_matchlist[0].nickname;//成功匹配
                g_matchlist.erase(g_matchlist.begin());
                ofstream ofs("room\\1.txt");//创建并打开文件
                ofs.close();
            }
        }
        else if (m.id == "2") {
            if (c_matchlist.size() == 0 ) {
                g_matchlist.push_back(m);
                retStr = "0";//未匹配成功
            } 
            else {
                OnlinePlayer[m.nickname] = c_matchlist[0].nickname;
                OnlinePlayer[c_matchlist[0].nickname] = m.nickname;

                retStr = "1 " + c_matchlist[0].nickname;//成功匹配
                c_matchlist.erase(c_matchlist.begin());
                ofstream ofs("room\\1.txt");//创建并打开文件
                ofs.close();
            }
        }  
        else {//无身份
            retStr = "-1";//未选择身份
        }


        break;
    
    }
    case CON_WORD: {
        //写入文件
        if (lock == 0) {
            ofstream ofs("room\\1.txt");//创建并打开文件
            ofs << retStr;//写入单词
            ofs.close();
            lock = 1;
            tmptype = 19;
        }
        else {
            tmptype = '0';
        }
    }
    case CON_ANS: {
        if (lock == 1) {
            ifstream ifs("room\\1.txt", ios::in);
            string correct;
            ifs >> correct;
            if (retStr == correct) {
                retStr = "r";
            }
            else {
                retStr = "w";
            }
            tmptype = 20;
        }
        else {
            tmptype = '0';
        }
    }
    case REQ_SIG: {
        string username;
        string code;
        string nickname;
        ss >> username >> code >> nickname;
        DM dm1(username);
        if (dm1.SignIn(code, nickname)) {
            retStr = "Y";
            Playerlist.clear();
            LoadPlayerList();
        } 
        else retStr = "N";
        tmptype = "22";
        break;
    }
    default: std::cout << "No recv responce" << std::endl;
    }
    //按照头回复
    sendMsg(atoi(tmptype.c_str()), retStr);
    return retStr;
}





TcpServer::TcpServer()
{
    m_fd = socket(AF_INET, SOCK_STREAM, 0);
}

TcpServer::~TcpServer()
{
    closesocket(m_fd);
}

int TcpServer::setListen(unsigned short port)
{
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = INADDR_ANY;  // 0 = 0.0.0.0
    int ret = bind(m_fd, (struct sockaddr*)&saddr, sizeof(saddr));
    if (ret == -1)
    {
        perror("bind");
        return -1;
    }
    std::cout << "The socket binding succeeded, ip: "
        << inet_ntoa(saddr.sin_addr)
        << ", port: " << port << std::endl;

    ret = listen(m_fd, 128);
    if (ret == -1)
    {
        perror("listen");
        return -1;
    }
    std::cout << "Setting listener succeeded..." << std::endl;

    return ret;
}

TcpSocket* TcpServer::acceptConn(sockaddr_in* addr)
{
    if (addr == NULL)
    {
        return nullptr;
    }

    socklen_t addrlen = sizeof(struct sockaddr_in);
    int cfd = accept(m_fd, (struct sockaddr*)addr, &addrlen);
    if (cfd == -1)
    {
        perror("accept");
        return nullptr;
    }
    printf("The connection is successfully established with the client....\n");
    return new TcpSocket(cfd);
}

