#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainform.h"
//#include <QLabel>
//#include <QLineEdit>
//#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:

	mainform* wgt1;
//	QWidget* wgt2;
//	QWidget* wgt3;
//	QWidget* wgt4;
	Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
