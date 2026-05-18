#include "loadtablemodel.h"
#include"ConstCharacter.h"
#include"DataProcess.h"


LoadTableModel::LoadTableModel(QObject *parent)
	: TableModel(parent)
{
}

LoadTableModel::~LoadTableModel()
{
}

void LoadTableModel::stopRead()
{
	isread = false;
}

void LoadTableModel::setRowCount(const int count)
{
	rowcount = count;
	loaddata.resize(count);
	for (int i = 0; i < rowcount; i++) {
		loaddata[i].resize(columncount);
	}
}

void LoadTableModel::setColumnCount(const int count)
{
	columncount = count;
	headertypes.resize(count);
	for (int i = 0; i < rowcount; i++) {
		loaddata[i].resize(columncount);
	}
}

void LoadTableModel::setRowAndColumn(const int i_rowcount, const int i_columncount) 
{	
	editable = true;
	loaddata.clear();
	rowcount = i_rowcount;
	columncount = i_columncount;
	headertypes.clear();
	headertypes.resize(columncount);
	StringVector tempstringlist;
	for (int i = 0; i < columncount; i++) {
		tempstringlist.push_back(QString());
	}
	for (int i = 0; i < rowcount; i++) {
		loaddata.push_back(tempstringlist);
	}
}

void LoadTableModel::setLoadData(const QString&sloaddata)
{	
	editable = false;
	DataProcess* historydataprocess = SingleTemplate<DataProcess>::getInstance();
	loaddata = historydataprocess->changeStringToStringVectorVector(sloaddata,columncount,rowcount,true);
	rowcount = loaddata.size();
	headertypes.clear();
	headertypes.resize(columncount);
}

void LoadTableModel::setStringList(const StringVectorVector&doublestringvector)
{	
	editable = false;
	loaddata = doublestringvector;
	rowcount = loaddata.size();
	for (int i = 0; i < loaddata.size(); i++) {
		if (columncount < loaddata[i].size()) {
			columncount = loaddata[i].size();
		}
	}
	headertypes.clear();
	headertypes.resize(columncount);
}

void LoadTableModel::updateModel()
{
	beginResetModel();
	endResetModel();
}


void LoadTableModel::setHeader(const int section, const QString&content)
{
	headertypes[section] = content;
	emit headerDataChanged(Qt::Horizontal, section, section);
}

void LoadTableModel::clearAppointHeader(const int section)
{
	headertypes[section] = QString();
	emit headerDataChanged(Qt::Horizontal, section, section);
}

QString LoadTableModel::getCurrentType(const int column)
{	
	QString datatype;
	QString type = headertypes[column];
	if (!type.isEmpty()) {
		datatype = type.split(s_interval).first();
	}
	return datatype;
}

StringVectorVector LoadTableModel::getTableStringVectorVector() const
{
	return loaddata;
}



QStringList LoadTableModel::getDataTypes() const
{
	QStringList types;
	for (int i = 0; i < headertypes.size(); i++) {
		if (!headertypes[i].isEmpty()) {
			types.push_back(headertypes[i].split(s_interval).first());
		}
	}
	return types;
}

QStringList LoadTableModel::getAllDataTypes() const
{
	QStringList types;
	for (int i = 0; i < headertypes.size(); i++) {
		if (!headertypes[i].isEmpty()) {
			types.push_back(headertypes[i]);
		}else {
			types.push_back(s_empty);
		}
	}
	return types;
}

QVariant LoadTableModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) {
		return QVariant();
	}
	if (loaddata.isEmpty()) {
		return QVariant();
	}
	if (role == Qt::DisplayRole) {
		int column = index.column();
		int row = index.row();
		StringVector tempstringvector = loaddata[row];
		if (column < tempstringvector.size()) {
			QString content= tempstringvector[column];
			bool ok;
			double value = content.toDouble(&ok);
			
		
			if (ok) {
				content = QString::number(value,'f', 6);
			}
			return content;
		}else {
			return QString();
		}
	}
	return QVariant();
}

int LoadTableModel::rowCount(const QModelIndex & parent) const
{	
	return rowcount;
}

int LoadTableModel::columnCount(const QModelIndex & parent) const
{
	return columncount;
}

QVariant LoadTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{	
	QVariant variant;
	if (orientation == Qt::Vertical&&role==Qt::DisplayRole) {
		variant = QAbstractTableModel::headerData(section, orientation, role);
	}else if(orientation==Qt::Horizontal&&role==Qt::DisplayRole){
		if (section < headertypes.size()) {
			QString content = headertypes[section];
			if (content.isEmpty()) {
				variant = QAbstractTableModel::headerData(section, orientation, role);
			}else {
				variant = content;
			}
		}
	}else {
		;
	}
	return variant;
}

Qt::ItemFlags LoadTableModel::flags(const QModelIndex& index) const
{
	if (index.isValid() && editable) {
		return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
	}
	else {
		return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	}
}



bool LoadTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (index.isValid() && role == Qt::EditRole) {
		emit dataChanged(index, index, QVector<int>() << role);
		int row = index.row();
		int column = index.column();
		loaddata[row][column] = value.toString();
		return true;
	}else {
		return false;
	}
}


