#pragma once
#include "menu.h"
#include <QMainWindow>
#include "ui_UserMenu.h"
#include "client.h"

class UserMenu : public QMainWindow
{
	Q_OBJECT

public:
	QMenu* ordermenu;//快进按钮，分为三种速度
	QAction* option1;//昵称
	QAction* option2;//Creator 等级/经验
	QAction* option3;//Creator 出题数
	QAction* option4;//Guesser 等级/经验
	QAction* option5;//Guesser 闯关数
	int key = 0;
	UserMenu(QWidget *parent = nullptr);
	~UserMenu();
	void RefreshPlayerlist();
	void RefreshPlayerlist(Creator*& plc, Guesser*& plg);
	Ui::UserMenuClass ui;
private slots:
	void OptionSlot();
	void FindUser();
	void GameReq();
	//void on_listWidget_itemDoubleClicked(QListWidgetItem* item);
};
