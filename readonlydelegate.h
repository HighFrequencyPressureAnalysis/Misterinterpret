#pragma once

#include <QItemDelegate>


//==========只读代理==========//

class ReadOnlyDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	ReadOnlyDelegate(QWidget *parent=nullptr);
	~ReadOnlyDelegate();
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const override;
	
};
