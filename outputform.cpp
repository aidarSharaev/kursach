#include "outputform.h"

outputform::outputform(QSqlQuery* query, int qsl_size, QStringList* l_list, QWidget *parent)
		: QWidget{parent}
	{
	this->resize(800, 600);
	table = new QTableWidget(this);
	but = new QPushButton("Печать", this);
	but->setGeometry(QRect(920, 10, 60, 30));

	table->setGeometry(QRect(0, 40,800, 560));
	table->setColumnCount(qsl_size);
	table->setRowCount(query->size());
	table->setHorizontalHeaderLabels(*l_list);
	table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	int index{};
	qDebug() << query->size();
	while (query->next())
		{
		for (int i = 0; i < qsl_size; i++)
			{
			table->setItem(index, i, new QTableWidgetItem(query->value(i).toString()));
			}
		++index;
		}


	QObject::connect(this->but, SIGNAL(clicked()), this, SLOT(p_print()));

	}

void outputform::p_print()
	{
	QPrinter printer;
	QPrintDialog dialog(&printer, this);
	dialog.setWindowTitle("Печать отчета");
	if (dialog.exec() == QDialog::Accepted)
		{

		}
	}

outputform::~outputform()
	{
	delete but;
	delete table;
	delete doc;
	}
