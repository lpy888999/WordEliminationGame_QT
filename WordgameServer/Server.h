#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include<winsock2.h>
#include<ws2tcpip.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include <pthread.h>
#include<Windows.h>
#include<vector>
//extern vector<int> fdlist;
extern int lock;

class TcpSocket
{
public:
    TcpSocket();
    TcpSocket(int socket);
    ~TcpSocket();
    int connectToHost(std::string ip, unsigned short port);
    int sendMsg(int type, std::string = "");
    std::string recvMsg();



    int m_fd;	// 通信的套接字
};


class TcpServer
{
public:
    TcpServer();
    ~TcpServer();
    int setListen(unsigned short port);
    TcpSocket* acceptConn(struct sockaddr_in* addr = nullptr);

private:
    SOCKET m_fd;	// 监听的套接字
};

