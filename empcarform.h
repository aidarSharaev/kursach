#ifndef EMPCARFORM_H
#define EMPCARFORM_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class MainWindow;

class empcarform : public QWidget
	{
	Q_OBJECT
public:
	explicit empcarform(QWidget *parent = nullptr);
	~empcarform();

private:
	QLabel* empInfo;
	QLabel* carInfo;
	QLineEdit* ff;
	QLineEdit* ii;
	QLineEdit* oo;
	QLineEdit* tn;
	QLineEdit* cn;
	QPushButton* btn_back;
	QPushButton* btn_search;
	QWidget* p_parent;
	MainWindow* m_main;

public slots:
	void gotoSearch();

signals:
	void emp_emp(QString, QString, QString, QString);
	void emp_car(QString);
	};

#endif // EMPCARFORM_H
