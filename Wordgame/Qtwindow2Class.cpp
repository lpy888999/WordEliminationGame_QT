#include "Qtwindow2Class.h"
int mode = 0;//0单机 1联机
Qtwindow2Class::Qtwindow2Class(QWidget* parent)
	: QMainWindow(parent)
{
	//加载词库
	//加载所有玩家与usermenu
	//LoadPlayerList();
	ui.setupUi(this);
	w3 = new UserMenu(this);
	this->setObjectName("mainWidget");
	this->setStyleSheet("#mainWidget{border-image:url(:/image/b3.jpg)}");//设置背景

	ui.usermenu->setIcon(QIcon(":/image/th.jpg"));  
	ui.CreatorButton->setStyleSheet("border-image:url(:/image/Creator.jpg)");

	ui.GuessButton->setStyleSheet("border-image:url(:/image/Guesser.jpg)");

	ui.textEdit->setStyleSheet("background - color: rgb(255, 255, 255, 60); ");//设置透明
	p1c = new Creator(account);
	p1g = new Guesser(account);
	tcp.sendMsg(13, p1c->_nickname);//表示已登录
	Sleep(200);
	tcp.sendMsg(11);//请求所有用户列表
	LoadPlayerList();//接收用户列表

	Round = p1g->_roundnum;//接着闯关
	
	ui.Round->setText("Round："+ QString::number(Round));
	ui.count->setText("Count：" + QString::number(count1));
	//Creator
    connect(ui.CreatorButton, &QPushButton::clicked, this, [=]() {
		playerid = "1";
		ui.SubmitButton->disconnect();
		//使该按钮失能
		ui.CreatorButton->setEnabled(false);  
		ui.GuessButton->setEnabled(true);
		//当提交按钮点击
		connect(ui.SubmitButton, &QPushButton::clicked, this, [=]() {
			string newword = ui.input->text().toStdString();
			int ret = 0;
			tcp.sendMsg(9,newword);
			ret = atoi(tcp.recvMsg().c_str());
			if(ret == 0) QMessageBox::information(this, "创造", "单词已存在");//检查是否已经存在
			else if(ret == -1) QMessageBox::information(this, "创造", "单词存在非法字符！");
			else {
				p1c->expadd(ret);
				p1c->levadd();
				p1c->store(); //先保存更新本地存档
				tcp.sendMsg(3,account);

				w3->RefreshPlayerlist();
				QMessageBox::information(this, "创造", "出题成功");
			}
			});
        });
	connect(ui.GuessButton, &QPushButton::clicked, this, [=]() {
		
		playerid = "2";
		ui.SubmitButton->disconnect();//解除所有连接

		//使该按钮失能
		ui.CreatorButton->setEnabled(true);
		ui.GuessButton->setEnabled(false);

		//显示单词
		string word = NewRound();
		//计时	
		count1 = 0;
		ui.count->setText("Count：" + QString::number(count1));
		Timeset();

		//当提交按钮点击
		connect(ui.SubmitButton, &QPushButton::clicked, this, [=]()mutable {
			answertime->stop();
			string answer = ui.input->text().toStdString();
			if (word == answer) {
				++Round;
				ui.Round->setText("Round：" + QString::number(Round));
				//增加经验
				p1g->expadd(count1);
				count1 = 0;
				ui.count->setText("Count：" + QString::number(count1));
				p1g->levadd();
				p1g->store();//先保存更新本地存档
				tcp.sendMsg(4, account);
				//刷新用户列表
				w3->RefreshPlayerlist();

				//下一关
				
				word = NewRound();
				Timeset();
				ui.input->clear();
			}
			else {
				//游戏结束
				QMessageBox::information(this, "挑战者", "回答错误");
				answertime->stop();
			}
		//刷新单词	
			});
		});
	connect(ui.usermenu, SIGNAL(clicked()), this, SLOT(usermenu()));

}

void Qtwindow2Class::on_exitButton_clicked() {
	//退出时存档

	Playerlist.clear();
	tcp.sendMsg(14);
	emit sendsignal();
	this->close();
	this->setAttribute(Qt::WA_DeleteOnClose, 1);//销毁该界面的所有变量

}


Qtwindow2Class::~Qtwindow2Class()
{}

string Qtwindow2Class::NewRound(int mode) {
	string word = RandWord(mode);
	QString qword = QString::fromStdString(word);
	ui.textEdit->append(qword);
	ui.textEdit->setAlignment(Qt::AlignCenter);            //水平居中
	return word;
}
string Qtwindow2Class::NewRound() {//来自服务器的词
	tcp.sendMsg(6);
	string word = tcp.recvMsg();
	QString qword = QString::fromStdString(word);
	ui.textEdit->append(qword);
	ui.textEdit->setAlignment(Qt::AlignCenter);            //水平居中
	return word;
}
void Qtwindow2Class::Timeset() {
	if(answertime != NULL) delete answertime;
	answertime = new QTimer;
	answertime->setInterval(1000);//重新填装

	time = new QTimer;
	ui.SubmitButton->setEnabled(false);
	ui.input->setEnabled(false);
	//根据难度确定消失时间每10关缩短一些
	time->setInterval(3000 /((Round / 10) + 1));
	time->start();
	//QMessageBox::information(this, "计时", "设定时间");
	connect(time, SIGNAL(timeout()), this, SLOT(vanish()));
	connect(answertime, SIGNAL(timeout()), this, SLOT(counter()));
}

void Qtwindow2Class::vanish() {

	ui.textEdit->clear();
	ui.SubmitButton->setEnabled(true);
	ui.input->setEnabled(true);
	//QMessageBox::information(this, "计时", "到时间！");
	time->stop();
	delete time;
	answertime->start();
}
void Qtwindow2Class::counter() {
	count1++;
	ui.count->setText("Count：" + QString::number(count1));
}
void Qtwindow2Class::usermenu() {
	
	w3->setWindowTitle("My Homepage");
	w3->ui.nickname->setText(QString::fromStdString(p1c->_nickname));
	w3->ui.CreatorLV->setText("CreatorLV:"+QString::number(p1c->_level));
	w3->ui.Total_Word->setText("Total Word:"+QString::number(p1c->_wordnum));
	w3->ui.GuesserLV->setText("GuesserLV:"+QString::number(p1g->_level));
	w3->ui.Round->setText("Round:"+QString::number(p1g->_roundnum));
	w3->ui.listWidget->setStyleSheet(R"(
                        QListWidget { outline: none; border:1px solid white;  color: #696969;}
                        QListWidget::Item { width: 60px; height: 60px; }
                        QListWidget::Item:hover { background: #FFA500; color: white; }
                        QListWidget::item:selected { background: #FFC0CB; color: #DC143C; }
                        QListWidget::item:selected:!active { background: blue; }
                        )");
	w3->show();
	w3->ui.listWidget->clear();
	string tmp;
	QString qtmp;
	tmp += "NAME\tC_LV\tEXP\tW_N\tG_LV\tEXP\tROUND";
	qtmp = QString::fromStdString(tmp);
	w3->ui.listWidget->addItem(qtmp);
	//显示所有用户
	for (int i = 0; i < Playerlist.size(); ++i) {
		tmp = "";
		for (int j = 0; j < Playerlist[i].size(); ++j) {
			tmp += Playerlist[i][j] + "\t";
		}
		qtmp = QString::fromStdString(tmp);
		w3->ui.listWidget->addItem(qtmp);
	}
}
