#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainform.h"
#include "empcarform.h"
#include "chiefform.h"
#include "bossform.h"
#include <database.h>
#include <QWidget>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();	

private:
	void hideAll();
	void deleteform();
	mainform* wgt1;
	empcarform* wgt2;
	chiefform* wgt3;
	bossform* wgt4;
	Ui::MainWindow* ui;
	database* db;

public slots:
	void openEmpCar();
	void openChief();
	void openMain();
	void openBoss();

	void db_e_getempinfo(QString fam, QString imya, QString otchestvo, QString tabnomer);
	void db_e_getcarinfo(QString nomer);

	void db_c_getDriverList();
	void db_c_getTripList();
	void db_c_getFreeCar();
	void db_c_goToRemont(QString nomer);
	void db_c_changeCar(QString tabnomer, QString nomer);
	void db_c_newTrip(QString tabnomer, QString gorod, QString traty, QString data, QString prichina);

	void db_b_changeChief(QString oldc, QString newc);
	void db_b_addNewTrip(QString type, QString kilom, QString name);
	void db_b_downgradeBoostStaff(QString tabnomer, int x);
	void db_b_addNewCar(QString pts, QString type, QString garage, QString nomer);
	void db_b_mostEmergensy();

};
#endif // MAINWINDOW_H
