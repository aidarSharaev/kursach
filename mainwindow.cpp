#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
		: QMainWindow(parent)
		, wgt2(nullptr),
		wgt3(nullptr),
		wgt4(nullptr),
		ui(new Ui::MainWindow)
	{
	ui->setupUi(this);
	db = new database(this);
	this->setFixedSize(800, 600);
	wgt1 = new mainform(this);
//	wgt2 = nullptr;
//	wgt3 = nullptr;
//	wgt4 = nullptr;
	wgt1->show();

}

MainWindow::~MainWindow()
	{
	delete wgt1;
	if (wgt2)
		delete wgt2;
	if (wgt3)
		delete wgt3;
	if (wgt4)
		delete wgt4;
	delete db;
	delete ui;
	}

void MainWindow::hideAll()
	{
	wgt1->hide();
	if (wgt2)
		wgt2->hide();
	if (wgt3)
		wgt3->hide();
	if (wgt4)
		wgt4->hide();
	}

void MainWindow::openEmpCar()
	{
	wgt2 = new empcarform(this);
	hideAll();
	wgt2->show();
	}

void MainWindow::openChief()
	{
	bool ok;
	QString text = QInputDialog::getText(0, "Введите пароль", "Пароль:", QLineEdit::Normal, "", &ok);
	if (text == "123")
		{
		wgt3 = new chiefform(this);
		hideAll();
		wgt3->show();
		}
	else
		{
		return;
		}
	}

void MainWindow::openBoss()
	{
	bool ok;
	QString text = QInputDialog::getText(0, "Введите пароль", "Пароль:", QLineEdit::Normal, "", &ok);
	if (text == "12345")
		{
		wgt4 = new bossform(this);
		hideAll();
		wgt4->show();
		}
	else
		{
		return;
		}
	}

void MainWindow::openMain()
	{
	deleteform();
	}

void MainWindow::deleteform()
	{
	if (wgt2)
		{
		delete wgt2;
		wgt2 = nullptr;
		}
	if (wgt3)
		{
		delete wgt3;
		wgt3 = nullptr;
		}
	if (wgt4)
		{
		delete wgt4;
		wgt4 = nullptr;
		}
	wgt1->show();
	}

void MainWindow::db_e_getempinfo(QString fam, QString imya, QString otchestvo, QString tabnomer)
	{
	db->e_getEmployeeInfo(fam, imya, otchestvo, tabnomer);
	}

void MainWindow::db_e_getcarinfo(QString nomer)
	{
	db->e_getCarInfo(nomer);
	}

void MainWindow::db_c_getDriverList()
	{
	db->c_getDriverList();
	}

void MainWindow::db_c_getTripList()
	{
	db->c_getTripList();
	}

void MainWindow::db_c_getFreeCar()
	{
	db->c_getFreeCar();
	}

void MainWindow::db_c_goToRemont(QString nomer)
	{
	db->c_goToRemont(nomer);
	}

void MainWindow::db_c_changeCar(QString tabnomer, QString nomer)
	{
	db->c_changeCar(tabnomer, nomer);
	}

void MainWindow::db_c_newTrip(QString tabnomer, QString gorod, QString traty, QString data, QString prichina)
	{
	db->c_newTrip(tabnomer, gorod, traty, data, prichina);
	}

void MainWindow::db_b_changeChief(QString oldc, QString newc)
	{
	db->b_changeChief(oldc, newc);
	}
void MainWindow::db_b_addNewTrip(QString type, QString kilom, QString name)
	{
	db->b_addNewTrip(type, kilom, name);
	}
void MainWindow::db_b_downgradeBoostStaff(QString tabnomer, int x)
	{
	db->b_downgradeBoostStaff(tabnomer, x);
	}
void MainWindow::db_b_addNewCar(QString pts, QString type, QString garage, QString nomer)
	{
	db->b_addNewCar(pts, type, garage, nomer);
	}
void MainWindow::db_b_mostEmergensy()
	{
	db->b_mostEmergensy();
	}




