#ifndef BOSSFORM_H
#define BOSSFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

class bossform : public QWidget
	{
	Q_OBJECT
public:
	explicit bossform(QWidget *parent = nullptr);
	~bossform();

private:
	QLabel* lbl_changechief;
	QLabel* lbl_addnewtrip;
	QLabel* lbl_downgrade;
	QLabel* lbl_addnewcar;
	QLabel* lbl_booststaff;
	QLabel* lbl_mostemergensy;

	QPushButton* but_changechief;
	QPushButton* but_addnewtrip;
	QPushButton* but_downgrade;
	QPushButton* but_addnewcar;
	QPushButton* but_booststaff;
	QPushButton* but_mostemergensy;
	QPushButton* btn_back;

	QLineEdit* line_changechief_tabNumber;
	QLineEdit* line_changechief_newTabNumber;
	QLineEdit* line_addnewtrip_carType;
	QLineEdit* line_addnewtrip_kilometr;
	QLineEdit* line_addnewtrip_name;
	QLineEdit* line_downgrade_tabNumber;
	QLineEdit* line_addnewcar_carType;
	QLineEdit* line_addnewcar_garageNumber;
	QLineEdit* line_addnewcar_carNumber;
	QLineEdit* line_addnewcar_pts;
	QLineEdit* line_booststaff_tabNumber;

public slots:
	void change();
	void newTrip();
	void down();
	void boost();
	void newCar();

signals:
	void goChange(QString, QString);
	void goNewTrip(QString, QString, QString);
	void goDownBoost(QString, int);
	void goNewCar(QString, QString, QString, QString);
};

#endif // BOSSFORM_H
