#include "chiefform.h"

chiefform::chiefform(QWidget *parent)
		: QWidget{parent}
	{
	this->resize(800, 600);

	lbl_driverlist = new QLabel("Получить список водителей", this);
	lbl_triplist = new QLabel("Получить поездки", this);
	lbl_freecar = new QLabel("Незанятые машины", this);
	lbl_gotoremont = new QLabel("Отправить в ремонт", this);
	lbl_changecar = new QLabel("Изменить машину", this);
	lbl_newtrip = new QLabel("Внести новую поездку", this);

	but_driverlist = new QPushButton("Получить список", this);
	but_triplist = new QPushButton("Получить список", this);
	but_freecar = new QPushButton("Получить список", this);
	but_gotoremont = new QPushButton("Выполнить", this);
	but_changecar = new QPushButton("Выполнить", this);
	but_newtrip = new QPushButton("Внести", this);
	btn_back = new QPushButton("Назад", this);

	line_gotoremont_carNumber = new QLineEdit(this);
	line_changecar_tabNumber = new QLineEdit(this);
	line_changecar_carNumber = new QLineEdit(this);
	line_newtrip_tabNumber = new QLineEdit(this);
	line_newtrip_city = new QLineEdit(this);
	line_newtrip_addCost = new QLineEdit(this);
	line_newtrip_date = new QLineEdit(this);
	line_newtrip_reason = new QLineEdit(this);

	line_gotoremont_carNumber->setPlaceholderText("Номер машины");
	line_changecar_tabNumber->setPlaceholderText("Таб. номер");
	line_changecar_carNumber->setPlaceholderText("Номер машины");
	line_newtrip_tabNumber->setPlaceholderText("Таб. номер");
	line_newtrip_city->setPlaceholderText("Город");
	line_newtrip_addCost->setPlaceholderText("Доп. траты");
	line_newtrip_date->setPlaceholderText("Дата");
	line_newtrip_reason->setPlaceholderText("Причина");

	QFont font1("Comic Sans MS", 10);
	QFont font2("Comic Sans MS", 12);

	lbl_driverlist->setFont(font2);
	lbl_triplist->setFont(font2);
	lbl_freecar->setFont(font2);
	lbl_gotoremont->setFont(font2);
	lbl_changecar->setFont(font2);
	lbl_newtrip->setFont(font2);

	but_driverlist->setFont(font1);
	but_triplist->setFont(font1);
	but_freecar->setFont(font1);
	but_gotoremont->setFont(font1);
	but_changecar->setFont(font1);
	but_newtrip->setFont(font1);
	btn_back->setFont(font1);
	line_gotoremont_carNumber->setFont(font1);
	line_changecar_tabNumber->setFont(font1);
	line_changecar_carNumber->setFont(font1);
	line_newtrip_tabNumber->setFont(font1);
	line_newtrip_city->setFont(font1);
	line_newtrip_addCost->setFont(font1);
	line_newtrip_date->setFont(font1);
	line_newtrip_reason->setFont(font1);

	lbl_driverlist->setGeometry(QRect(50, 50, 300, 30));
	but_driverlist->setGeometry(QRect(630, 50, 120, 30));

	lbl_triplist->setGeometry(QRect(50, 130, 300, 30));
	but_triplist->setGeometry(QRect(630, 130, 120, 30));

	lbl_freecar->setGeometry(QRect(50, 200, 210, 30));
	but_freecar->setGeometry(QRect(630, 200, 120, 30));

	lbl_gotoremont->setGeometry(QRect(50, 290, 300, 30));
	but_gotoremont->setGeometry(QRect(630, 290, 120, 30));
	line_gotoremont_carNumber->setGeometry(QRect(50, 330, 150, 30));

	lbl_changecar->setGeometry(QRect(50, 370, 300, 30));
	but_changecar->setGeometry(QRect(630, 370, 120, 30));
	line_changecar_tabNumber->setGeometry(QRect(50, 410, 150, 30));
	line_changecar_carNumber->setGeometry(QRect(220, 410, 150, 30));

	lbl_newtrip->setGeometry(QRect(50, 450, 300, 30));
	but_newtrip->setGeometry(QRect(630, 450, 120, 30));
	line_newtrip_tabNumber->setGeometry(QRect(50, 490, 100, 30));
	line_newtrip_city->setGeometry(QRect(170, 490, 100, 30));
	line_newtrip_addCost->setGeometry(QRect(290, 490, 100, 30));
	line_newtrip_date->setGeometry(QRect(410, 490, 100, 30));
	line_newtrip_reason->setGeometry(QRect(530, 490, 100, 30));

	btn_back->setGeometry(QRect(20, 20, 70, 30));

	QObject::connect(btn_back, SIGNAL(clicked()), parent, SLOT(openMain()));
	QObject::connect(this->but_driverlist, SIGNAL(clicked()), parent, SLOT(db_c_getDriverList()));

	QObject::connect(this->but_triplist, SIGNAL(clicked()), parent, SLOT(db_c_getTripList()));

	QObject::connect(this->but_freecar, SIGNAL(clicked()), parent, SLOT(db_c_getFreeCar()));

	QObject::connect(this->but_gotoremont, SIGNAL(clicked()), this, SLOT(remont()));
	QObject::connect(this, SIGNAL(goRem(QString)), parent, SLOT(db_c_goToRemont(QString)));

	QObject::connect(this->but_changecar, SIGNAL(clicked()), this, SLOT(change()));
	QObject::connect(this, SIGNAL(goChange(QString, QString)), parent, SLOT(db_c_changeCar(QString, QString)));

	QObject::connect(this->but_newtrip, SIGNAL(clicked()), this, SLOT(newtrip()));
	QObject::connect(this, SIGNAL(goNew(QString, QString, QString, QString, QString)), parent, SLOT(db_c_newTrip(QString, QString, QString, QString, QString)));


	}

chiefform::	~chiefform()
	{
	delete lbl_driverlist;
	delete lbl_triplist;
	delete lbl_freecar;
	delete lbl_gotoremont;
	delete lbl_changecar;
	delete lbl_newtrip;
	delete but_triplist;
	delete but_driverlist;
	delete but_freecar;
	delete but_gotoremont;
	delete but_changecar;
	delete but_newtrip;
	delete btn_back;
	delete line_gotoremont_carNumber;
	delete line_changecar_tabNumber;
	delete line_changecar_carNumber;
	delete line_newtrip_tabNumber;
	delete line_newtrip_city;
	delete line_newtrip_addCost;
	delete line_newtrip_date;
	delete line_newtrip_reason;
	}

void chiefform::remont()
	{
	if (!line_gotoremont_carNumber->text().isEmpty())
		emit goRem(line_gotoremont_carNumber->text());
	}

void chiefform::change()
	{
	if (!line_changecar_tabNumber->text().isEmpty() && !line_changecar_carNumber->text().isEmpty())
		emit goChange(line_changecar_tabNumber->text(), line_changecar_carNumber->text());
	}

void chiefform::newtrip()
	{
	if (!line_newtrip_tabNumber->text().isEmpty() && !line_newtrip_city->text().isEmpty()
			&& !line_newtrip_addCost->text().isEmpty() && !line_newtrip_date->text().isEmpty()
			&& !line_newtrip_reason->text().isEmpty())
		emit goNew(line_newtrip_tabNumber->text(),
							 line_newtrip_city->text(),
							 line_newtrip_addCost->text(),
							 line_newtrip_date->text(),
							 line_newtrip_reason->text());
	}

