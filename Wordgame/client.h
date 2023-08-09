#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
class TcpSocket
{
public:
    TcpSocket();
    TcpSocket(int socket);
    ~TcpSocket();
    int connectToHost(std::string ip, unsigned short port);
    int sendMsg(int type, std::string msg = "");
    std::string recvMsg();

private:
    int readn(char* buf, int size);
    int writen(const char* msg, int size);

public:
    int m_fd;	// 通信的套接字
};

extern TcpSocket tcp;