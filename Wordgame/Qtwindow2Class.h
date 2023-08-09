#pragma once
#include"menu.h"
#include <QMainWindow>
#include "ui_Qtwindow2Class.h"
#include <QTableView>
#include <QStandardItemModel>
#include"Loginwindow2.h"
#include"UserMenu.h"
#include<QTimer>
#include"menu.h"
extern int mode;//0单机 1联机
class Qtwindow2Class : public QMainWindow
{
	Q_OBJECT

public:
	QTimer* time;
	QTimer* answertime = NULL;
	Creator* p1c;
	Guesser* p1g;
	string NewRound();
	string NewRound(int mode);
	//子窗口
	UserMenu* w3;
	void Timeset();
	Qtwindow2Class(QWidget *parent = nullptr);
	~Qtwindow2Class();

private slots:
	void on_exitButton_clicked();
	void vanish();
	void counter();
	void usermenu();
signals:
	void sendsignal();//该界面关闭信号

private:
	Ui::Qtwindow2ClassClass ui;
};
