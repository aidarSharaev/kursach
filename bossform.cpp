#include "bossform.h"

bossform::bossform(QWidget *parent)
		: QWidget{parent}
	{
	this->resize(800, 600);
	lbl_changechief = new QLabel("Изменить начальника", this);
	lbl_addnewtrip = new QLabel("Добавить новый маршрут", this);
	lbl_downgrade = new QLabel("Понизить сотрудника", this);
	lbl_addnewcar = new QLabel("Добавить новую машину", this);
	lbl_booststaff = new QLabel("Повысить сотрудника", this);
	lbl_mostemergensy = new QLabel("Самый аварийный сотрудник", this);

	but_changechief = new QPushButton("Изменить", this);
	but_addnewtrip = new QPushButton("Внести", this);
	but_downgrade = new QPushButton("Понизить", this);
	but_addnewcar = new QPushButton("Внести", this);
	but_booststaff = new QPushButton("Повысить", this);
	but_mostemergensy = new QPushButton("Получить", this);
	btn_back = new QPushButton("Назад", this);

	line_changechief_tabNumber = new QLineEdit(this);
	line_changechief_newTabNumber = new QLineEdit(this);
	line_addnewtrip_carType = new QLineEdit(this);
	line_addnewtrip_kilometr = new QLineEdit(this);
	line_addnewtrip_name = new QLineEdit(this);
	line_downgrade_tabNumber = new QLineEdit(this);
	line_addnewcar_carType = new QLineEdit(this);
	line_addnewcar_garageNumber = new QLineEdit(this);
	line_addnewcar_carNumber = new QLineEdit(this);
	line_addnewcar_pts = new QLineEdit(this);
	line_booststaff_tabNumber = new QLineEdit(this);

	QFont font1("Comic Sans MS", 10);
	QFont font2("Comic Sans MS", 12);

	lbl_changechief->setFont(font2);
	lbl_addnewtrip->setFont(font2);
	lbl_downgrade->setFont(font2);
	lbl_addnewcar->setFont(font2);
	lbl_booststaff->setFont(font2);
	lbl_mostemergensy->setFont(font2);

	but_mostemergensy->setFont(font1);
	but_changechief->setFont(font1);
	but_addnewtrip->setFont(font1);
	but_downgrade->setFont(font1);
	but_addnewcar->setFont(font1);
	but_booststaff->setFont(font1);
	btn_back->setFont(font1);

	line_changechief_newTabNumber->setFont(font1);
	line_addnewcar_garageNumber->setFont(font1);
	line_changechief_tabNumber->setFont(font1);
	line_booststaff_tabNumber->setFont(font1);
	line_addnewtrip_kilometr->setFont(font1);
	line_downgrade_tabNumber->setFont(font1);
	line_addnewcar_carNumber->setFont(font1);
	line_addnewtrip_carType->setFont(font1);
	line_addnewcar_carType->setFont(font1);
	line_addnewtrip_name->setFont(font1);
	line_addnewcar_pts->setFont(font1);

	line_changechief_newTabNumber->setPlaceholderText("Новый начальник");
	line_addnewcar_garageNumber->setPlaceholderText("Номер гаража");
	line_changechief_tabNumber->setPlaceholderText("Таб.номер");
	line_booststaff_tabNumber->setPlaceholderText("Таб.номер");
	line_addnewtrip_kilometr->setPlaceholderText("Километраж");
	line_downgrade_tabNumber->setPlaceholderText("Таб.номер");
	line_addnewcar_carNumber->setPlaceholderText("Номер машины");
	line_addnewtrip_carType->setPlaceholderText("Вид кузова");
	line_addnewcar_carType->setPlaceholderText("Вид кузова");
	line_addnewtrip_name->setPlaceholderText("Город");
	line_addnewcar_pts->setPlaceholderText("ПТС");

	lbl_changechief->setGeometry(QRect(50, 50, 300, 30));
	but_changechief->setGeometry(QRect(630, 50, 120, 30));
	line_changechief_tabNumber->setGeometry(QRect(50, 90, 120, 30));
	line_changechief_newTabNumber->setGeometry(QRect(190, 90, 120, 30));

	lbl_addnewtrip->setGeometry(QRect(50, 130, 300, 30));
	but_addnewtrip->setGeometry(QRect(630, 130, 120, 30));
	line_addnewtrip_carType->setGeometry(QRect(50, 170, 120, 30));
	line_addnewtrip_kilometr->setGeometry(QRect(190, 170, 120, 30));
	line_addnewtrip_name->setGeometry(QRect(330, 170, 120, 30));

	lbl_downgrade->setGeometry(QRect(50, 200, 300, 30));
	but_downgrade->setGeometry(QRect(630, 200, 120, 30));
	line_downgrade_tabNumber->setGeometry(QRect(50, 240, 120, 30));

	lbl_addnewcar->setGeometry(QRect(50, 290, 300, 30));
	but_addnewcar->setGeometry(QRect(630, 290, 120, 30));
	line_addnewcar_pts->setGeometry(QRect(50, 330, 120, 30));
	line_addnewcar_carType->setGeometry(QRect(190, 330, 120, 30));
	line_addnewcar_garageNumber->setGeometry(QRect(330, 330, 120, 30));
	line_addnewcar_carNumber->setGeometry(QRect(470, 330, 120, 30));

	lbl_booststaff->setGeometry(QRect(50, 370, 300, 30));
	but_booststaff->setGeometry(QRect(630, 370, 120, 30));
	line_booststaff_tabNumber->setGeometry(QRect(50, 410, 120, 30));

	lbl_mostemergensy->setGeometry(QRect(50, 450, 300, 30));
	but_mostemergensy->setGeometry(QRect(630, 450, 120, 30));

	btn_back->setGeometry(QRect(20, 20, 70, 30));

	QObject::connect(this->btn_back, SIGNAL(clicked()), parent, SLOT(openMain()));

	QObject::connect(this->but_changechief, SIGNAL(clicked()), this, SLOT(change()));
	QObject::connect(this, SIGNAL(goChange(QString, QString)), parent, SLOT(db_b_changeChief(QString, QString)));

	QObject::connect(this->but_addnewtrip, SIGNAL(clicked()), this, SLOT(newTrip()));
	QObject::connect(this, SIGNAL(goNewTrip(QString, QString, QString)), parent, SLOT(db_b_addNewTrip(QString, QString, QString)));

	QObject::connect(this->but_downgrade, SIGNAL(clicked()), this, SLOT(down()));
	QObject::connect(this->but_booststaff, SIGNAL(clicked()), this, SLOT(boost()));
	QObject::connect(this, SIGNAL(goDownBoost(QString, int)), parent, SLOT(db_b_downgradeBoostStaff(QString, int)));

	QObject::connect(this->but_addnewcar, SIGNAL(clicked()), this, SLOT(newCar()));
	QObject::connect(this, SIGNAL(goNewCar(QString, QString, QString, QString)), parent, SLOT(db_b_addNewCar(QString, QString, QString, QString)));

	QObject::connect(this->but_mostemergensy, SIGNAL(clicked()), parent, SLOT(db_b_mostEmergensy()));
	}

bossform::~bossform()
	{
	delete line_changechief_tabNumber;
	delete line_changechief_newTabNumber;
	delete line_addnewtrip_carType;
	delete line_addnewtrip_kilometr;
	delete line_addnewtrip_name;
	delete line_downgrade_tabNumber;
	delete line_addnewcar_carType;
	delete line_addnewcar_garageNumber;
	delete line_addnewcar_carNumber;
	delete line_addnewcar_pts;
	delete line_booststaff_tabNumber;
	delete lbl_changechief;
	delete lbl_addnewtrip;
	delete lbl_downgrade;
	delete lbl_addnewcar;
	delete lbl_booststaff;
	delete lbl_mostemergensy;
	delete but_changechief;
	delete but_addnewtrip;
	delete but_downgrade;
	delete but_addnewcar;
	delete but_booststaff;
	delete but_mostemergensy;
	delete btn_back;
	}

void bossform::change()
	{
	if (!line_changechief_tabNumber->text().isEmpty()
			&& !line_changechief_newTabNumber->text().isEmpty())
		emit goChange(line_changechief_tabNumber->text(), line_changechief_newTabNumber->text());
	}
void bossform::newTrip()
	{
	if (!line_addnewtrip_carType->text().isEmpty() && !line_addnewtrip_kilometr->text().isEmpty()
			&& !line_addnewtrip_name->text().isEmpty())
		emit goNewTrip(line_addnewtrip_carType->text(),
									 line_addnewtrip_kilometr->text(),
									 line_addnewtrip_name->text());
	}
void bossform::down()
	{
	if (!line_downgrade_tabNumber->text().isEmpty())
		emit goDownBoost(line_downgrade_tabNumber->text(), 1);
	}
void bossform::boost()
	{

	if (!line_booststaff_tabNumber->text().isEmpty())
		{
		qDebug() << "sjk";
		emit goDownBoost(line_booststaff_tabNumber->text(), 0);
		}
	}
void bossform::newCar()
	{
	if (!line_addnewcar_pts->text().isEmpty() && !line_addnewcar_carType->text().isEmpty()
			&& !line_addnewcar_garageNumber->text().isEmpty()
			&& !line_addnewcar_carNumber->text().isEmpty())
		emit goNewCar(line_addnewcar_pts->text(),
									line_addnewcar_carType->text(),
									line_addnewcar_garageNumber->text(),
									line_addnewcar_carNumber->text());
	}
