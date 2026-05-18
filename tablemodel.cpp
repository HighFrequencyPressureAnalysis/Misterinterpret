#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
	: QAbstractTableModel(parent)
{

}

TableModel::~TableModel()
{
}

void TableModel::setHeaderTypes(const QStringList&types)
{
	headertypes = types;
}

void TableModel::updateModel()
{
	beginResetModel();
	endResetModel();
}

void TableModel::setIndex(const QString&index)
{
	dataindex = index;
}

void TableModel::clearModel()
{
	dataindex.clear();
	updateModel();
	
}

void TableModel::changeUnit()
{
	updateModel();
}


//int TableModel::rowCount(const QModelIndex & parent) const
//{
//	return 0;
//}
//
//int TableModel::columnCount(const QModelIndex & parent) const
//{
//	return 0;
//}
//
//QVariant TableModel::data(const QModelIndex & index, int role) const
//{
//	return QVariant();
//}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal)
	{
		if (role == Qt::DisplayRole)
		{	
			if (!headertypes.isEmpty()) {
				return headertypes.at(section);
			}
			
		}
	}else {
		if (role == Qt::DisplayRole)
		{
			return QAbstractTableModel::headerData(section, orientation, role);

		}
	}
	return QVariant();
}
