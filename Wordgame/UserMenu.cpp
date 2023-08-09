#include "UserMenu.h"
#include"Qtwindow2Class.h"
#include<QDateTime>
UserMenu::UserMenu(QWidget* parent)
	:QMainWindow(parent)
{
	
	ui.setupUi(this);
	this->setObjectName("userWidget");
	this->setStyleSheet("#userWidget{border-image:url(:/image/b1.jpg)}");//设置背景
	ui.profile->setPixmap(QString(":/image/th.jpg"));
	//排序选项菜单
	ordermenu = new QMenu();
	ui.key->setMenu(ordermenu);
	option1 = ordermenu->addAction("Name", this, SLOT(OptionSlot()));//Qaction 新建菜单  
	option2 = ordermenu->addAction("Creator Level", this, SLOT(OptionSlot()));//Qaction 新建菜单
	option3 = ordermenu->addAction("Num of Questions", this, SLOT(OptionSlot()));
	option4 = ordermenu->addAction("Guesser Level", this, SLOT(OptionSlot()));
	option5 = ordermenu->addAction("Already Solved", this, SLOT(OptionSlot()));
	//connect(ui.listWidget, &QListWidget::itemDoubleClicked, this, [=]() {
	//	on_listWidget_itemDoubleClicked(ui.listWidget->currentItem());
	//	});
	connect(ui.Connect, SIGNAL(clicked()), this, SLOT(GameReq()));
	connect(ui.find, SIGNAL(clicked()), this, SLOT(FindUser()));
}

UserMenu::~UserMenu()
{
	this->setAttribute(Qt::WA_DeleteOnClose, 1);//销毁该界面的所有变量
}
void UserMenu::OptionSlot() {
	QAction* cur_action = (QAction*)sender();//通过sender获得发送信号的对象
	QString actionText = cur_action->text();//获取该对象的名字（字符串）
	if (actionText == "Name") { key = 0; SortPlayerList(0); ui.key->setText("Name"); }
	else if (actionText == "Creator Level") { key = 1; SortPlayerList(1);  ui.key->setText("C_LV");
	}
	else if (actionText == "Num of Questions") { key = 2; SortPlayerList(2); ui.key->setText("W_N");
	}
	else if (actionText == "Guesser Level") { key = 3; SortPlayerList(3);  ui.key->setText("G_LV");
	}
	else { key = 4; SortPlayerList(4);  ui.key->setText("ROUND");
	}
	RefreshPlayerlist();//刷新显示排行榜
}
void UserMenu::RefreshPlayerlist() {
	ui.listWidget->clear();
	string tmp;
	QString qtmp;
	tmp += "NAME\tC_LV\tEXP\tW_N\tG_LV\tEXP\tROUND\tONLINE";
	qtmp = QString::fromStdString(tmp);
	ui.listWidget->addItem(qtmp);
	//更新当前用户
	tcp.sendMsg(11);//请求所有用户列表
	LoadPlayerList();//接收用户列表
	//显示所有用户
	for (int i = 0; i < Playerlist.size(); ++i) {
		tmp = "";
		for (int j = 0; j < Playerlist[i].size(); ++j) {
			tmp += Playerlist[i][j] + "\t";
		}
		qtmp = QString::fromStdString(tmp);
		ui.listWidget->addItem(qtmp);
	}
};
void UserMenu::RefreshPlayerlist(Creator*& p1c, Guesser*& p1g) {//重载更新，实时更新当前用户
	for (int i = 0; i < Playerlist.size(); ++i) {
		if (Playerlist[i][0] == p1c->_nickname) {
			Playerlist[i][1] = to_string(p1c->_level);
			Playerlist[i][2] = to_string(p1c->_exp);
			Playerlist[i][3] = to_string(p1c->_wordnum);
			Playerlist[i][4] = to_string(p1g->_level);
			Playerlist[i][5] = to_string(p1g->_exp);
			Playerlist[i][6] = to_string(p1g->_roundnum);
			break;
		}
	}
};

void  UserMenu::FindUser() {
	string target = ui.findline->text().toStdString();
	ui.listWidget->clear();
	string tmp;
	QString qtmp;
	tmp += "NAME\tC_LV\tEXP\tW_N\tG_LV\tEXP\tROUND";
	qtmp = QString::fromStdString(tmp);
	ui.listWidget->addItem(qtmp);
	int index;
	switch (key) {//根据（排序）属性查找
	case 0:index = 0; break;
	case 1:index = 1; break;
	case 2:index = 3; break;
	case 3:index = 4; break;
	case 4:index = 6; break;
	default: std::cout << "order key error" << std::endl;
	}
	//遍历所有用户
	int flag = 0;
	for (int i = 0; i < Playerlist.size(); ++i) {
		tmp = "";
		if (Playerlist[i][index] == target) {//查找成功
			flag = 1;//已找到
			for (int j = 0; j < Playerlist[i].size(); ++j) {
				tmp += Playerlist[i][j] + "\t";
			}
			qtmp = QString::fromStdString(tmp);
			ui.listWidget->addItem(qtmp);
		}
		else if (flag == 1) break;
	}
	
}

void UserMenu::GameReq() {
	
	QTimer* t1 = new QTimer();
	t1->setInterval(1000);

	//发送联机请求
	tcp.sendMsg(15);
	string ret = tcp.recvMsg();
	if (ret[0] == '1')//连接成功
	{
		ret= ret.substr(2, ret.length());//去掉头
		ui.p2->setText(QString::fromStdString(ret));
		mode = 1;
		delete t1;
	}
	else if (ret[0] == '0') {//需要等待
		t1->start();
		std::cout << "please wait for a moment。。。" << std::endl;
		connect(t1, SIGNAL(timeout()), this, SLOT(GameReq));
	}
	else {
		QMessageBox::information(this, "联机游戏", "请选择角色！");
	}
}
//void UserMenu::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
//{
//	static bool isProcessing = false;
//	if (isProcessing) {
//		return;
//	}
//	isProcessing = true;
//	
//	//获得昵称，发送对战请求
//		//判断该人是否在线
//	string text = item->text().toStdString();
//	istringstream s1(text);
//	string tmpnickname;
//	string tmp1;
//	s1 >> tmpnickname;//nickname
//	for (int i = 0; i < 7; ++i) s1 >> tmp1;//得到是否在线
//	if (tmp1 == "1") {
//
//	}
//	else QMessageBox::information(this, "联机游戏", "对方不在线！");
//	
//	QTimer::singleShot(1000, [=]() {
//		isProcessing = false;
//		});
//}
