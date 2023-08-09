#pragma once

#include <QMainWindow>
#include "ui_MainWindow.h"
#include <QTimer>
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	QTimer* time;
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
};
