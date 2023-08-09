#pragma once
#include<String>
#include<QString>
#include<QMessageBox>
#include<QObject>
#include <QMainWindow>
#include "ui_Loginwindow2.h"
#include "Signinwindow.h"
#include"Qtwindow2Class.h"
#include"client.h"
class Loginwindow2 : public QMainWindow
{
	Q_OBJECT

public:
	Loginwindow2(QWidget *parent = nullptr);
	~Loginwindow2();
	Signinwindow* w0;
private slots:
	void reshow();
private:
	Ui::Loginwindow2Class ui;
};
