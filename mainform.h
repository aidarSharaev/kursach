#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFont>

class mainform : public QWidget
	{
	Q_OBJECT
public:
	explicit mainform(QWidget *parent = nullptr);
	~mainform();

private:
	QLabel* name;
	QPushButton* btn_chief;
	QPushButton* btn_boss;
	QPushButton* btn_empl;
	QPushButton* btn_back;

signals:

	};

#endif // MAINFORM_H
