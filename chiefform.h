#ifndef CHIEFFORM_H
#define CHIEFFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class chiefform : public QWidget
	{
	Q_OBJECT
public:
	explicit chiefform(QWidget *parent = nullptr);
	~chiefform();

private:
	QLabel* lbl_driverlist;
	QLabel* lbl_triplist;
	QLabel* lbl_freecar;
	QLabel* lbl_gotoremont;
	QLabel* lbl_changecar;
	QLabel* lbl_newtrip;

	QPushButton* but_driverlist;
	QPushButton* but_triplist;
	QPushButton* but_freecar;
	QPushButton* but_gotoremont;
	QPushButton* but_changecar;
	QPushButton* but_newtrip;
	QPushButton* btn_back;

	QLineEdit* line_gotoremont_carNumber;
	QLineEdit* line_changecar_tabNumber;
	QLineEdit* line_changecar_carNumber;
	QLineEdit* line_newtrip_tabNumber;
	QLineEdit* line_newtrip_city;
	QLineEdit* line_newtrip_addCost;
	QLineEdit* line_newtrip_date;
	QLineEdit* line_newtrip_reason;

public slots:
	void remont();
	void change();
	void newtrip();

signals:
	void goRem(QString);
	void goChange(QString, QString);
	void goNew(QString, QString, QString, QString, QString);
	};

#endif // CHIEFFORM_H
