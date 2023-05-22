#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include "outputform.h"
#include <QMessageBox>

class database : public QObject
	{
	Q_OBJECT
public:
	explicit database(QObject* parent = nullptr);
	~database();
	QSqlDatabase db;
	QSqlQuery* query;
	outputform* out;

	void e_getEmployeeInfo(QString familiya, QString imya, QString otchestvo, QString tabnomer);
	void e_getCarInfo(QString nomer);

	void c_getDriverList();
	void c_getTripList();
	void c_getFreeCar();
	void c_goToRemont(QString nomer);
	void c_changeCar(QString tabnomer, QString nomer);
	void c_newTrip(QString tabnomer, QString gorod, QString traty, QString data, QString prichina);

	void b_changeChief(QString oldc, QString newc);
	void b_addNewTrip(QString type, QString kilom, QString name);
	void b_downgradeBoostStaff(QString tabnomer, int x);
	void b_addNewCar(QString pts, QString type, QString garage, QString nomer);
	void b_mostEmergensy();

	void errorMessage();
	void successMessage();
	};

#endif // DATABASE_H
