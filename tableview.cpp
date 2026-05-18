#include "tableview.h"


TableView::TableView(QWidget *parent)
	: QTableView(parent)
{}

TableView::~TableView()
{}

void TableView::addSelectConnect()
{
	connect(selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(sendSelectRange(const QItemSelection&, const QItemSelection&)));
}

void TableView::initTable()
{	
	if (!model) {
		model = new QStandardItemModel(this);
		setModel(model);
		horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	}
	
}

void TableView::setHorizontalHeaderTypes(const QStringList&types)
{
	if (model) {
		model->setHorizontalHeaderLabels(types);
		model->setColumnCount(types.size());
	}
}

void TableView::setVerticalHeaderTypes(const QStringList&types)
{
	if (model) {
		model->setVerticalHeaderLabels(types);
		model->setRowCount(types.size());
	}
}

void TableView::setHorizontalHeaderVisible(bool visible)
{
	horizontalHeader()->setVisible(visible);
}

void TableView::setVerticalHeaderVisible(bool visible)
{
	verticalHeader()->setVisible(false);
}

void TableView::setRowAndColumnCount(const int rows, const int column)
{
	if (model) {
		model->setRowCount(rows);
		model->setColumnCount(column);
	}
}


void TableView::setTableEditUnable()
{
	setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void TableView::setColumnEditUnable(const int column)
{
	ReadOnlyDelegate* delegate = new ReadOnlyDelegate();
	setItemDelegateForColumn(column, delegate);
}

void TableView::setRowEditUnable(const int row)
{
	ReadOnlyDelegate* delegate = new ReadOnlyDelegate();
	setItemDelegateForRow(row, delegate);
}

void TableView::setNumberColumn(const int column)
{
	NumberItemDelegate* delegate = new NumberItemDelegate();
	setItemDelegateForColumn(column, delegate);
}

IntVector TableView::getSelectRows() const
{
	QItemSelectionModel* selections = selectionModel();
	QModelIndexList selected = selections->selectedRows();
	IntVector rownumber;
	rownumber.resize(0);
	if (selected.size())
	{
		rownumber.push_back(selected.first().row());
		rownumber.push_back(selected.last().row());
	}
	return rownumber;
}

void TableView::sendSelectRange(const QItemSelection&, const QItemSelection&)
{
	IntVector selectrow = getSelectRows();
	if (selectrow.size()) {
		emit sendSelectSignal(selectrow);
	}
}