#include "tableviewperpos.h"


TableViewPerpos::TableViewPerpos(QWidget *parent)
	: TableView(parent)
{
	model = new QStandardItemModel(this);
	setModel(model);
	const int columncount = 1;
	model->setColumnCount(columncount);
	QStringList headertypes;
	headertypes << "Î»ÖÃ(m)";
	setHorizontalHeaderTypes(headertypes);
	for (int i = 0; i < columncount; i++) {
		setNumberColumn(i);
		horizontalHeader()->setSectionResizeMode(i,QHeaderView::Stretch);
	}
	
}

TableViewPerpos::~TableViewPerpos()
{}

int TableViewPerpos::getCurrentCount() const
{
	return model->rowCount();
}

void TableViewPerpos::setRowCount(const int count)
{
	model->setRowCount(count);
}

void TableViewPerpos::setRowCount(const int currentcount, const int addcount)
{
	model->setRowCount(addcount);
	for (int i = 0; i < addcount; i++) {
		if (i >= currentcount) {
			model->setData(model->index(i, 0), 3000.00);
		}
	}
}

void TableViewPerpos::showPerData(const DoubleVector&perdata)
{
	int count = perdata.size();
	for (int i = 0; i < perdata.size(); i++) {
		model->setData(model->index(i, 0), perdata[i]);
	}
}

DoubleVector TableViewPerpos::getPerData() const
{
	DoubleVector perdata;
	int rowcount = model->rowCount();
	for (int i = 0; i < rowcount; i++) {
		perdata.push_back(model->index(i, 0).data().toDouble());
	}
	return perdata;
}
