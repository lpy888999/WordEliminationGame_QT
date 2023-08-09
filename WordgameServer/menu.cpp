#include"menu.h"
#include<tchar.h>

std::string account = "";//用户账户
int count1 = 0;
int Round = 1;
vector<string> wordlib1;
vector<string> wordlib2;
vector<string> wordlib3;
vector<vector<string>> Playerlist;
unordered_map<string,string> OnlinePlayer;
//vector<vector<string>> Creatorlist;
//vector<vector<string>> Guesserlist;
DM::DM(string username) :_path("user//" + username) {}

int DM::LogIn(string in_code) {//登录功能 检查登录，账号存在并且密码正确返回1，否则返回0

	ifstream ifs;
	ifs.open(_path + "\\code.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "账号不存在！（或文件打开失败）" << endl;
		return 0;
	}
	string buf;
	getline(ifs, buf);//读入密码，与输入密码比对
	ifs.close();
	if (buf == in_code) {
		cout << "登陆成功" << endl;
		return 1;
	}
	else {
		cout << "密码错误" << endl;
		return 0;
	}

}

int DM::SignIn(string code, string nickname)//注册功能
{
	//创建文件
	string folderPath = _path;

	if (0 != _access(folderPath.c_str(), 0))
	{
		// if this folder not exist, create a new one.
		_mkdir(folderPath.c_str());   // 返回 0 表示创建成功，-1 表示失败
		//换成 ::_mkdir  ::_access 也行，不知道什么意思
	}
	else { std::cout << "username already exist" << std::endl; return 0; }
	//设定密码
	//cout << "请输入设定密码:" << endl;
	ofstream ofs(_path + "\\code.txt");//创建并打开文件
	if (!ofs.is_open())
	{
		cout << "code file error" << endl;
	}
	ofs << code;
	ofs.close();

	//写入总用户档案
	ofs.open("users.txt", ios::app);
	if (!ofs.is_open())
	{
		cout << "register error" << endl;
	}
	ofs << _path <<"\n";
	ofs.close();

	//记录nickname
	ofs.open(_path + "//nickname.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "nickname error" << endl;
	}
	ofs << nickname;
	ofs.close();
	//设定achievements初值
	folderPath += "//Creator";
	
	if (0 != _access(folderPath.c_str(), 0))
	{
		// if this folder not exist, create a new one.
		_mkdir(folderPath.c_str());   // 返回 0 表示创建成功，-1 表示失败
		//换成 ::_mkdir  ::_access 也行，不知道什么意思
	}
	ofs.open(folderPath+"//achievements.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "creater error" << endl;
	}
	ofs << 1 << " " << 0 << " " << 0;
	ofs.close();

	//
	folderPath = _path+"//Guesser";
	if (0 != _access(folderPath.c_str(), 0))
	{
		// if this folder not exist, create a new one.
		_mkdir(folderPath.c_str());   // 返回 0 表示创建成功，-1 表示失败
		//换成 ::_mkdir  ::_access 也行，不知道什么意思
	}
	ofs.open(folderPath + "//achievements.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "creater error" << endl;
	}
	ofs << 1 << " " << 0 << " " << 0;
	ofs.close();
	return 1;
}

//void DM::LogOut()
//{
//	//是否存在？
//	//删除文件与文件夹
//	cout << "你确定要注销该用户，并删除该用户所有相关信息吗？[Y/N]" << endl;
//	cout << "删除路径：" << _path << endl;
//	string answer;
//	cin >> answer;
//	if (answer != "Y") return;
//	//删除文件夹
//	if (!rmdir(_path.c_str()))	cout << "删除成功！" << endl;
//
//}
Player::Player(string username): _account(username){
	ifstream inFile(_account._path+"\\nickname.txt", ios::in);
	if (!inFile) std::cout << "error!" << std::endl;
	else {
		inFile >> _nickname;
	}
	inFile.close();
}

void Creator::expadd(int mode) {
	_wordnum++;
	switch (mode) {
	case EASY:_exp += 10; break;
	case NORMAL:_exp += 20; break;
	case HARD:_exp += 50; break;
	default:std::cout << "expadd fault" << std::endl;
	}
}

void Creator::levadd() {
	if (_level == 1 && _exp >= 100) _level++;
	else if (_level == 2 && _exp >= 350) _level++;
	else if (_level == 3 && _exp >= 1000) _level++;
	else if (_level == 4 && _exp >= 2000) _level++;
	else if (_level == 5 && _exp >= 5000) _level++;
}




Creator::Creator(string username) :Player(username){
	//读文件 赋值 成员
	long num;
	ifstream inFile(_account._path + "\\Creator\\achievements.txt", ios::in);//二进制模式打开文件
	if (!inFile) std::cout << "error!" << std::endl;
	else {
		inFile >> num;
		_level = num;
		inFile >> num;
		_exp = num;
		std::cout << "my exp:" << _exp << std::endl;//测试
		inFile >> num;
		_wordnum = num;
	}

}

void Creator::store() {
	//只存成员属性
	ofstream outFile(_account._path + "\\Creator\\achievements.txt", ios::out);
	if (!outFile) std::cout << "store error" << std::endl;
	else {
	outFile << _level << " ";
	outFile << _exp << " ";
	outFile << _wordnum;
	}
	outFile.close();

}

Guesser::Guesser(string username):Player(username)
{
	//读文件 赋值 成员
	long num;
	ifstream inFile(_account._path + "\\Guesser\\achievements.txt", ios::in);//二进制模式打开文件
	if (!inFile) std::cout << "error!" << std::endl;
	else {
		inFile >> num;
		_level = num;
		inFile >> num;
		_exp = num;
		std::cout << "my exp:" << _exp << std::endl;//测试
		inFile >> num;
		_roundnum = num;
	}
}

void Guesser::expadd(int count) {
	_roundnum++;
	switch (count/2) {
	case 0:_exp += 15; break;
	case 1:_exp += 10; break;
	case 2:_exp += 5; break;
	default:_exp += 1;
	}
}

void Guesser::levadd() {
	if (_level == 1 && _exp >= 100) _level++;
	else if (_level == 2 && _exp >= 350) _level++;
	else if (_level == 3 && _exp >= 1000) _level++;
	else if (_level == 4 && _exp >= 2000) _level++;
	else if (_level == 5 && _exp >= 5000) _level++;
}

void Guesser::store() {
	ofstream outFile(_account._path + "\\Guesser\\achievements.txt", ios::out);
	if (!outFile) std::cout << "store error" << std::endl;
	else {
		outFile << _level << " ";
		outFile << _exp << " ";
		outFile << _roundnum;
	}
	outFile.close();
}

string RandWord(int mode) {
	//之前先将词库读入内存
	// 在词库中随机读一行
	string word;
	srand(time(nullptr)); // 用当前时间作为种子
	switch (mode) {
	case EASY:
	{
		//产生随机数
		int min = 0, max = wordlib1.size() - 1;
		if (max == -1) { return ""; }
		int random = (rand() % (max - min + 1)) + min;//范围[min,max]
		//读取随机单词
		word = wordlib1[random];
		break;
	}
	case NORMAL: {
		//产生随机数
		int min = 0, max = wordlib2.size() - 1;
		if (max == 0) { return ""; }
		int random = (rand() % (max - min + 1)) + min;//范围[min,max]
		//读取随机单词
		word = wordlib2[random];
		break;
	}

	case HARD: {
		//产生随机数
		int min = 0, max = wordlib3.size() - 1;
		if (max == 0) { return ""; }
		int random = (rand() % (max - min + 1)) + min;//范围[min,max]
		//读取随机单词
		word = wordlib3[random];
		break;
	}
	default: {//
		std::cout << "wordlib mode error" << std::endl;
	}
	}
	return word;
}
string RandWord() {//未输入难度的重载 按照游戏关数调整难度
	// 在词库中随机读一行
	string word;
	srand(time(nullptr)); // 用当前时间作为种子
	switch ((Round / 10) + 1) {
	case EASY:
	{
		//产生随机数
		int min = 0, max = wordlib1.size() - 1;
		if (max == -1) { return ""; }
		int random = (rand() % (max - min + 1)) + min;//范围[min,max]
		//读取随机单词
		word = wordlib1[random];
		break;
	}
	case NORMAL: {
		//产生随机数
		int min = 0, max = wordlib2.size() - 1;
		if (max == 0) { return ""; }
		int random = (rand() % (max - min + 1)) + min;//范围[min,max]
		//读取随机单词
		word = wordlib2[random];
		break;
	}

	case HARD: {
		//产生随机数
		int min = 0, max = wordlib3.size() - 1;
		if (max == 0) { return ""; }
		int random = (rand() % (max - min + 1)) + min;//范围[min,max]
		//读取随机单词
		word = wordlib3[random];
		break;
	}
	default: {//
		std::cout << "wordlib mode error" << std::endl;
		word = "CONGRATULATIONS";
	}
	}
	return word;
}
// 获取文件的行数
//filepath:文件路径
int getFileLine(string filePath) {
	int nLines = 0;
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filePath, ios::in);//ios::in 表示以只读的方式读取文件
	if (ReadFile.fail())//文件打开失败:返回0
		return 0;
	else//文件存在
	{
		while (getline(ReadFile, tmp))
		{
			if (tmp == "")
				continue;	//不统计空行
			n++;
		}
	}
	ReadFile.close();
	return n;
}

void LoadWordLib(string filepath, int mode) {

	string word;
	//int fileline = getFileLine(filepath);
	ifstream inFile(filepath, ios::in);
	if (!inFile) {
		std::cout << "wordlib error" << std::endl;
		return ;
	}
	while (inFile >> word) {
		switch (mode) {
		case EASY:wordlib1.push_back(word); break;
		case NORMAL:wordlib2.push_back(word); break;
		case HARD:wordlib3.push_back(word); break;
		default: std::cout << "wordlib mode error" << std::endl;
		}

	}
	inFile.close();
}

int AddNewWord(string newword) {
	for (auto e : newword) {
		if (e < 'A' || (e > 'Z' && e < 'a') || e > 'z') return -1;
	}
	if (newword.size() <= 5)//EASY词
	{
		if (find(wordlib1.begin(), wordlib1.end(), newword) != wordlib1.end()) return 0;
		wordlib1.push_back(newword);
		return 1;
	}
	else if (newword.size() > 5 && newword.size() < 10)//NORMAL词
	{
		if (find(wordlib2.begin(), wordlib2.end(), newword) != wordlib2.end()) return 0;
		wordlib2.push_back(newword);
		return 2;
	}
	else//HARD词
	{
		if (find(wordlib3.begin(), wordlib3.end(), newword) != wordlib3.end()) return 0;
		wordlib3.push_back(newword);
		return 3;
	}
}

void StoreWordLib() {
	ofstream outfile1("wordlib\\wordlib1.txt", ios::out);
	ofstream outfile2("wordlib\\wordlib2.txt", ios::out);
	ofstream outfile3("wordlib\\wordlib3.txt", ios::out);
	if (!outfile1 || !outfile2 || !outfile3) std::cout << "store lib error" << std::endl;
	else {
		for (int i = 0; i < wordlib1.size(); ++i) {
			outfile1 << wordlib1[i] << " ";
		}
		for (int i = 0; i < wordlib2.size(); ++i) {
			outfile2 << wordlib2[i] << " ";
		}
		for (int i = 0; i < wordlib3.size(); ++i) {
			outfile3 << wordlib3[i] << " ";
		}
	}
	outfile1.close();
	outfile2.close();
	outfile3.close();
}

void LoadPlayerList() {
	Playerlist.clear();
	ifstream ifs1("users.txt", ios::in);
	ifstream ifs2;
	ifstream ifs3;
	string tmppath;
	string tmpelm;
	while (ifs1 >> tmppath) {
		vector<string> tmp1;//对于一个用户
		//存昵称
		ifs2.open(tmppath + "\\nickname.txt", ios::in);
		if (!ifs2) std::cout << " LoadCreatorList fault" << std::endl;
		ifs2 >> tmpelm;
		tmp1.push_back(tmpelm);
		ifs2.close();
		//存Creator成就
		ifs2.open(tmppath + "\\Creator\\achievements.txt", ios::in);
		if (!ifs2) std::cout << " LoadCreatorList fault" << std::endl;
		while (ifs2 >> tmpelm) {
			tmp1.push_back(tmpelm);
		}
		ifs2.close();
		//存Guesser成就
		ifs2.open(tmppath + "\\Guesser\\achievements.txt", ios::in);
		if (!ifs2) std::cout << " LoadGuesserList fault" << std::endl;
		while (ifs2 >> tmpelm) {
			tmp1.push_back(tmpelm);
		}
		ifs2.close();
		//存是否在线
		if (OnlinePlayer.find(tmp1[0]) == OnlinePlayer.end()) tmp1.push_back("0");
		else tmp1.push_back("1");
		Playerlist.push_back(tmp1);
	}
}

//排序玩家信息
void SortPlayerList(int mode) {
	std::cout << Playerlist[0][0] << " " << Playerlist[1][0] << " " << Playerlist[2][0] << std::endl;
	switch (mode) {
	case 0:
		sort(Playerlist.begin(), Playerlist.end(), [](const auto& e1, const auto& e2) {
			return e1[0] < e2[0];
			});
		break;
	case 1:
		sort(Playerlist.begin(), Playerlist.end(), [](const auto& e1, const auto& e2) {
			return long(*(e1[1].c_str())) > long(*(e2[1].c_str()))|| (long(*(e1[1].c_str())) == long(*(e2[1].c_str())) && long(*(e1[2].c_str())) > long(*(e2[2].c_str())));
			});
		break; 
	case 2:
		sort(Playerlist.begin(), Playerlist.end(), [](const auto& e1, const auto& e2) {
			return long(*(e1[3].c_str())) > long(*(e2[3].c_str())) || (long(*(e1[3].c_str())) == long(*(e2[3].c_str())) && e1[0] < e2[0]);
			});
		break;
	case 3:
		sort(Playerlist.begin(), Playerlist.end(), [](const auto& e1, const auto& e2) {
			return long(*(e1[4].c_str())) > long(*(e2[4].c_str())) || (long(*(e1[4].c_str())) == long(*(e2[4].c_str())) && long(*(e1[5].c_str())) > long(*(e2[5].c_str())));
			});
		break;
	case 4:
		sort(Playerlist.begin(), Playerlist.end(), [](const auto& e1, const auto& e2) {
			return long(*(e1[6].c_str())) > long(*(e2[6].c_str())) || (long(*(e1[6].c_str())) == long(*(e2[6].c_str())) && e1[0] < e2[0]);
			});
		break;
	default: std::cout << "playerlist sort error" << std::endl;
	
	}

	std::cout << Playerlist[0][0] << " " << Playerlist[1][0] << " " << Playerlist[2][0] << std::endl;
}

void SavePlayerList() {
	ifstream ifs1("users.txt", ios::in);
	ofstream ofs2;
	string tmppath;
	for (int i = 0; i < Playerlist.size() && ifs1 >> tmppath; ++i) {
			//存昵称
			ofs2.open(tmppath + "\\nickname.txt", ios::in);
			if (!ofs2) std::cout << " Save nickname fault" << std::endl;
			ofs2 << Playerlist[i][0];
			ofs2.close();
			//存Creator成就
			ofs2.open(tmppath + "\\Creator\\achievements.txt", ios::in);
			if (!ofs2) std::cout << "SaveCreatorList fault" << std::endl;
			ofs2 << Playerlist[i][1] << " " << Playerlist[i][2] << " " << Playerlist[i][3];
			ofs2.close();
			//存Guesser成就
			ofs2.open(tmppath + "\\Guesser\\achievements.txt", ios::in);
			if (!ofs2) std::cout << " SaveGuesserList fault" << std::endl;
			ofs2 << Playerlist[i][4] << " " << Playerlist[i][5] << " " << Playerlist[i][6];
			ofs2.close();

	}

}