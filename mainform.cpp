#include "mainform.h"

mainform::mainform(QWidget *parent)
		: QWidget{parent}
	{
	this->resize(800, 600);

	name = new QLabel("База данных \"Транспортная компания\"\nШараева Айдара 4207", this);
	btn_chief = new QPushButton("Транспортный отдел", this);
	btn_boss = new QPushButton("Изменение структуры работы", this);
	btn_empl = new QPushButton("Сотрудник / Машина", this);
	btn_back = new QPushButton("Завершение", this);

	QFont font1("Comic Sans MS", 18);
	QFont font2("Comic Sans MS", 10);
	name->setFont(font1);
	btn_chief->setFont(font2);
	btn_boss->setFont(font2);
	btn_empl->setFont(font2);
	btn_back->setFont(font2);

	name->setGeometry(QRect(180, 100, 500, 100));
	btn_chief->setGeometry(QRect(100, 300, 150, 50));
	btn_boss->setGeometry(QRect(300, 300, 200, 50));
	btn_empl->setGeometry(QRect(550, 300, 150, 50));
	btn_back->setGeometry(QRect(680, 530, 80, 30));

	QObject::connect(this->btn_back, SIGNAL(clicked()), parent, SLOT(close()));
	}

mainform::~mainform()
	{
	delete name;
	delete btn_chief;
	delete btn_boss;
	delete btn_empl;
	delete btn_back;
	}
