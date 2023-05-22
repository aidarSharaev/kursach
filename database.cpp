#include "database.h"

database::database(QObject *parent)
		: QObject{parent}
	{
	out = nullptr;
	db = QSqlDatabase::addDatabase("QPSQL");
	query = new QSqlQuery(db);
	db.setHostName("localhost");
	db.setDatabaseName("ud_kr");
	db.setUserName("postgres");
	db.setPort(5432);
	db.setPassword("SQLPassw0rdic3b3rg");
	if (db.open())
		qDebug() << "SUCCCCCCCCCCESS";
	else
		qDebug() << "loooooooooooser";
	}

database::~database()
	{
	delete query;
	}

void database::e_getEmployeeInfo(QString familiya, QString imya, QString otchestvo, QString tabnomer)
	{
	int i = 0;
	QString _query = "select Фамилия, Имя, Отчество, Табельный_номер, Должность from Сотрудник Where ";
	if (!familiya.isEmpty())
		{
		_query = _query + "Фамилия = " + "'" + familiya + "'";
		++i;
		}
	if (!imya.isEmpty())
		{
		if (1)
			_query += " and ";
		_query = _query + "Имя = " + "'" + imya + "'";
		++i;
		}
	if (!otchestvo.isEmpty())
		{
		if (i)
			_query += " and ";
		_query = _query + "Отчество = " + "'" + otchestvo + "'";
		++i;
		}
	if (!tabnomer.isEmpty())
		{
		if (i)
			_query += " and ";
		_query = _query + "Сотрудник = " + tabnomer;
		++i;
		}
	_query += ";";
	query->exec(_query);
	QStringList q_list = {"Фамилия", "Имя", "Отчество", "Табельный_номер", "Должность"};
	out = new outputform(query, q_list.size(), &q_list, nullptr);
	out->show();
	}

void database::e_getCarInfo(QString nomer)
	{
	QString _query
			= "select Машина.Номер_машины, Машина.Вид_кузова, Машина.№_гаража, "
				"Машина.Состояние, Сотрудник.Фамилия from Машина, Сотрудник where Машина.Номер_машины = '"
				+ nomer + "' and Сотрудник.Машина = '" + nomer + "';";
	query->exec(_query);
	//qDebug() << _query;
	if (!query->size())
		{
		_query
				= "select Машина.Номер_машины, Машина.Вид_кузова, Машина.№_гаража, "
					"Машина.Состояние, Сотрудник.Фамилия from Машина, Сотрудник where Машина.Номер_машины = '"
					+ nomer + "'; limit 1";
		query->exec(_query);
		//qDebug() << _query;
		}
	QStringList q_list = {"Номер_машины",
												"Вид_кузова",
												"№_гаража",
												"Состояние",
												"Фамилия"};
	out = new outputform(query, q_list.size(), &q_list, nullptr);
	out->show();
	}

void database::c_getDriverList()
	{
	QString _query = "Select Фамилия, Имя, Табельный_номер, Машина From Сотрудник where Должность = "
									 "'Водитель';";
	query->exec(_query);
	QStringList q_list = {"Фамилия",
												"Имя",
												"Табельный_номер",
												"Машина"};
	out = new outputform(query, q_list.size(), &q_list, nullptr);
	out->show();
	}

void database::c_getTripList()
	{
	QString _query = "Select №_поездки, Дата_поездки, Табельный_номер_сотрудника, Город, Вид_кузова, "
									 "Общая_трата, Причина_трат From Поездки;";
	query->exec(_query);
	QStringList q_list = {"№_поездки",
												"Дата поездки",
												"Табельный_номер_сотрудника",
												"Город",
												"Вид_кузова"};
	out = new outputform(query, q_list.size(), &q_list, nullptr);
	out->show();
	}

void database::c_getFreeCar()
	{
	QString _query = "Select Машина.Номер_машины, Машина.№_гаража, Машина.Состояние, "
									 "Машина.Вид_кузова from Машина where not exists (select Машина from Сотрудник "
									 "where Машина.Номер_машины = Сотрудник.Машина) group by Машина.Номер_машины;";
	query->exec(_query);
	QStringList q_list = {"Номер_машины", "№_гаража", "Состояние", "Вид_кузова"};
	out = new outputform(query, q_list.size(), &q_list, nullptr);
	out->show();
	}

void database::c_goToRemont(QString nomer)
	{
	QString _query = "update Машина set Состояние = 'На ремонте' where Номер_машины = '" + nomer
									 + "';";
	query->exec(_query);
	//qDebug() << query->numRowsAffected();
	if (!query->numRowsAffected())
		errorMessage();
	else {
		_query = "update Сотрудник set Машина = NULL where Машина = '" + nomer + "';";
		query->exec(_query);
			successMessage();
		}
	}

void database::c_changeCar(QString tabnomer, QString nomer)
	{
	QString _query = "select * from Машина where Номер_машины = '" + nomer + "';";
	query->exec(_query);
	if (!query->size())
		errorMessage();
	else
		{
		_query = "select Фамилия from Сотрудник where Машина = '" + nomer + "';";
		query->exec(_query);
		//qDebug() << query->size();
		if (query->size() > 0)
			{
			errorMessage();
			}
		else
			{
			_query = "update Сотрудник set Машина = '" + nomer + "' where Табельный_номер = '" + tabnomer
							 + "';";
			query->exec(_query);
			if (!query->numRowsAffected())
				errorMessage();
			else
				{
				successMessage();
				}
			}
		}
	}

void database::c_newTrip(
		QString tabnomer, QString gorod, QString traty, QString data, QString prichina)
	{
	if (prichina.isEmpty())
		prichina = "null";
	else
		prichina = "'" + prichina + "'";
	if (traty.isEmpty())
		traty = "0";
	QString _query
			= QString("select Сотрудник.Табельный_номер, Машина.Вид_кузова, Расход.Траты_на_бензин, "
								"Расход.Суточные from Машина join Сотрудник on Сотрудник.Табельный_номер = '%1' "
								"join Расход on Сотрудник.Машина = Машина.Номер_машины and Расход.Вид_кузова = "
								"Машина.Вид_кузова and Расход.Город = '%2';")
						.arg(tabnomer)
						.arg(gorod);
	query->exec(_query);
	if (!query->size())
		{
		errorMessage();
		return;
		}
	int x{};
	QString type;
	while (query->next())
		{
		type = query->value(1).toString();
		x = query->value(2).toInt() + query->value(3).toInt() + traty.toInt();
		}
	_query = QString("insert into Поездки(Дата_поездки, Табельный_номер_сотрудника, Город, "
									 "Вид_кузова, Непредвиденные_траты, Общая_трата, Причина_трат) values('%1', "
									 "'%2','%3','%4','%5','%6',%7);")
							 .arg(data)
							 .arg(tabnomer)
							 .arg(gorod)
							 .arg(type)
							 .arg(traty)
							 .arg(QString::number(x))
							 .arg(prichina);
	query->exec(_query);
	//qDebug() << _query;
	successMessage();
	}

void database::b_changeChief(QString oldc, QString newc)
	{
	QString _query;
	for (int i = 0; i < 2; i++)
		{
		if (!i)
			{
			_query = QString("Select * from Сотрудник where Должность = 'Начальник_гаража' and "
											 "Табельный_номер = %1;")
									 .arg(oldc);
			}
		else
			{
			_query = QString("Select * from Сотрудник where Должность = 'Водитель' and "
											 "Табельный_номер = %1;")
									 .arg(newc);
			}
		query->exec(_query);
		if (query->size() < 1)
			{
			errorMessage();
			return;
			}
		}
	_query = QString("Update Сотрудник set Должность = 'Водитель' where Должность = "
									 "'Начальник_гаража' and Табельный_номер = %1;")
							 .arg(oldc);
	query->exec(_query);
	_query = QString("Update Сотрудник set Должность = 'Начальник_гаража' where Должность = "
									 "'Водитель' and Табельный_номер = %1;")
							 .arg(newc);
	query->exec(_query);
	successMessage();
	}

void database::b_addNewTrip(QString type, QString kilom, QString name)
	{
	int sut{kilom.toInt() / 100 * 500};
	int benz{kilom.toInt() * 11 / 100 * 51};
	QString _query = QString("insert into Расход values ('%1', %2, %3, %4, '%5');")
											 .arg(type)
											 .arg(QString::number(sut))
											 .arg(QString::number(benz))
											 .arg(kilom)
											 .arg(name);
	query->exec(_query);
	qDebug() << query->numRowsAffected() << " " << query->size();
	if (query->numRowsAffected() < 1)
		errorMessage();
	else
		successMessage();
	}

void database::b_downgradeBoostStaff(QString tabnomer, int x)
	{
	double g = (x == 0) ? 1.2 : 0.8;

	QString _query = QString("select Оклад from Сотрудник where Табельный_номер = %1;").arg(tabnomer);
	query->exec(_query);
	//qDebug() << "hehe";
	if (!query->size())
		{
		errorMessage();
		return;
		}
	while (query->next())
		g = g * query->value(0).toInt();
	//qDebug() << g;
	_query = QString("update Сотрудник set Оклад = %1 where Табельный_номер = %2;")
							 .arg(QString::number(g))
							 .arg(tabnomer);
	query->exec(_query);
	successMessage();
	}
//
void database::b_addNewCar(QString pts, QString type, QString garage, QString nomer)
	{
	QString _query = QString("insert into Машина values '%1', '%2', %3, '%4', 'Исправное';")
											 .arg(nomer)
											 .arg(type)
											 .arg(garage)
											 .arg(pts);
	query->exec(_query);
	successMessage();
	}

void database::b_mostEmergensy()
	{
	QString _query
			= "select sum(Поездки.Общая_трата), Сотрудник.Фамилия from Сотрудник, Поездки group by "
				"Поездки.Табельный_номер_сотрудника, Поездки.Причина_трат, Сотрудник.Фамилия, "
				"Сотрудник.Табельный_номер having ((Поездки.Причина_трат = 'Штраф' or Причина_трат = "
				"'Ремонт') and Поездки.Табельный_номер_сотрудника = Сотрудник.Табельный_номер) order by "
				"sum "
				"desc;";
	query->exec(_query);
	QStringList q_list = {"Общая трата", "Фамилия"};
	out = new outputform(query, q_list.size(), &q_list, nullptr);
	out->show();
	}

void database::errorMessage()
	{
	QMessageBox::warning(0, QObject::tr("Некорректные данные"), "Перепроверьте введенные данные");
	return;

	}

void database::successMessage()
	{
	QMessageBox::information(0, QObject::tr("Успех"), "Данные внесены");
	return;
	}




