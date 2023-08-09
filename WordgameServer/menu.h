#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <fstream>
#include<string>
#include <algorithm>
#include<windows.h>
#include <direct.h>
#include<Io.h>
#include<vector>
#include<unordered_map>
#define EASY 1
#define NORMAL 2
#define HARD 3
extern std::string account;//用户账户
using namespace std;
extern int count1;
extern int Round;
extern std::vector<string> wordlib1;
extern std::vector<string> wordlib2;
extern std::vector<string> wordlib3;
extern vector<vector<string>> Playerlist;
extern unordered_map<string, string> OnlinePlayer;
//extern std::vector<vector<string>> Creatorlist;
//extern std::vector<vector<string>> Guesserlist;
#define DocumentManager DM
class DocumentManager //用户管理对象 用户登录时创建
{
public:
	string _path;//用户文件夹路径
	DM(string username);//初始化文件夹路径
	int LogIn(string in_code);//登录
	int SignIn(string code, string nickname);//注册
	void LogOut();//注销
};

class Player{
public:
	DM _account;//玩家账户
	Player(string username);
	//virtual ~Player();
	virtual void levadd() {};
	virtual void expadd(int mode) {};
	virtual void store(){};//退出保存 

	string _nickname;
};

class Creator : public Player
{
public:
	Creator(string username);
	//virtual ~Creator();
	virtual void levadd();
	virtual void expadd(int mode);
	virtual void store();//退出保存

	int _level = 1;//等级
	long _exp = 0;//经验
	long _wordnum = 0;
};

class Guesser: public Player
{
public:
	Guesser(string username);
	//virtual ~Guesser();
	virtual void levadd();
	virtual void expadd(int count);//传入已过秒数
	virtual void store();//退出保存

	int _level = 1;
	long _exp = 0;
	long _roundnum = 0;//闯关数
};
string RandWord();
string RandWord(int mode);
int getFileLine(string filePath);
void LoadWordLib(string filepath, int mode);
int AddNewWord(string newword);
void StoreWordLib();
void LoadPlayerList();
bool cmp();
void SortPlayerList(int mode);
void SavePlayerList();