#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
		: QMainWindow(parent)
		, ui(new Ui::MainWindow)
	{
	ui->setupUi(this);
	wgt1 = new mainform(this);
	//	wgt2 = new QWidget(this);
	//	wgt3 = new QWidget(this);
	//	wgt4 = new QWidget(this);
	wgt1->show();
}

MainWindow::~MainWindow()
{
delete wgt1;
//delete wgt2;
//delete wgt3;
//delete wgt4;

	delete ui;
}

