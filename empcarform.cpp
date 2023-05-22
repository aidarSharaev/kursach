#include "empcarform.h"

empcarform::empcarform(QWidget *parent)
		: QWidget{parent}
	{
	this->resize(800, 600);
	empInfo = new QLabel("Введите данные о сотруднике", this);
	carInfo = new QLabel("Введите данные о машине", this);
	ff = new QLineEdit(this);
	ii = new QLineEdit(this);
	oo = new QLineEdit(this);
	tn = new QLineEdit(this);
	cn = new QLineEdit(this);
	btn_back = new QPushButton("Назад", this);
	btn_search = new QPushButton("Поиск", this);

	QFont font1("Comic Sans MS", 10);
	QFont font2("Comic Sans MS", 12);
	ff->setFont(font1);
	ii->setFont(font1);
	oo->setFont(font1);
	tn->setFont(font1);
	cn->setFont(font1);
	btn_back->setFont(font1);
	btn_search->setFont(font1);
	empInfo->setFont(font2);
	carInfo->setFont(font2);

	ff->setPlaceholderText("Введите фамилию");
	ii->setPlaceholderText("Введите имя");
	oo->setPlaceholderText("Введите отчество");
	tn->setPlaceholderText("Введите табельный");
	cn->setPlaceholderText("Введите номер");

	btn_back->setGeometry(QRect(20, 20, 70, 30));
	btn_search->setGeometry(QRect(680, 530, 80, 30));

	empInfo->setGeometry(QRect(80, 170, 300, 30));
	ff->setGeometry(QRect(80, 220, 150, 30));
	ii->setGeometry(QRect(80, 270, 150, 30));
	oo->setGeometry(QRect(80, 320, 150, 30));
	tn->setGeometry(QRect(80, 370, 150, 30));

	carInfo->setGeometry(QRect(480, 170, 240, 30));
	cn->setGeometry(QRect(480, 220, 150, 30));

	QObject::connect(this->btn_back, SIGNAL(clicked()), parent, SLOT(openMain()));
	QObject::connect(this->btn_search, SIGNAL(clicked()), this, SLOT(gotoSearch()));
	QObject::connect(this, SIGNAL(emp_emp(QString, QString, QString, QString)), parent, SLOT(db_e_getempinfo(QString, QString, QString, QString)));
	QObject::connect(this, SIGNAL(emp_car(QString)), parent, SLOT(db_e_getcarinfo(QString)));

	}

empcarform::~empcarform()
	{
	delete empInfo;
	delete carInfo;
	delete ff;
	delete ii;
	delete oo;
	delete tn;
	delete cn;
	delete btn_back;
	delete btn_search;
	}

void empcarform::gotoSearch()
	{
	if (ff->text().isEmpty() && ii->text().isEmpty() && oo->text().isEmpty() && cn->text().isEmpty()
			&& tn->text().isEmpty())
		return;
	if ((!ff->text().isEmpty() || !ii->text().isEmpty() || !oo->text().isEmpty()
			 || !tn->text().isEmpty())
			&& !cn->text().isEmpty())
		return;
	if (!ff->text().isEmpty() || !ii->text().isEmpty() || !oo->text().isEmpty()
			|| !tn->text().isEmpty())
		emit emp_emp(ff->text(), ii->text(), oo->text(), tn->text());
	else
		emit emp_car(cn->text());
	}

















