#ifndef OUTPUTFORM_H
#define OUTPUTFORM_H

#include <QWidget>
#include <QSqlQuery>
#include <QTableWidget>
#include <QTextDocument>
#include <QPrinter>
#include <QPrintDialog>
#include <QHeaderView>
#include <QPushButton>

class outputform : public QWidget
	{
	Q_OBJECT
public:
	explicit outputform(QSqlQuery* query, int qsl_size, QStringList* l_list, QWidget* parent = nullptr);
	~outputform();

private:
	QTableWidget* table;
	QTextDocument* doc;
	QPushButton* but;

private slots:
	void p_print();

signals:

	};

#endif // OUTPUTFORM_H
