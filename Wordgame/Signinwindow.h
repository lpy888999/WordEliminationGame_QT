#pragma once
#include"menu.h"
#include <QMainWindow>
#include<QMessageBox>
#include "ui_Signinwindow.h"

class Signinwindow : public QMainWindow
{
	Q_OBJECT

public:
	Signinwindow(QWidget *parent = nullptr);
	~Signinwindow();
public slots:
	void Signin();
private:
	Ui::SigninwindowClass ui;
};
