#pragma once
#include <QItemDelegate>
#include <QRegularExpression>
//==========数字代理==========//

class NumberItemDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	NumberItemDelegate(QObject *parent=nullptr);
	~NumberItemDelegate();

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const  QModelIndex &index)  const;
	void  setEditorData(QWidget *editor, const  QModelIndex &index)  const;
	void  setModelData(QWidget *editor, QAbstractItemModel *model,
		const  QModelIndex &index)  const;
	void  updateEditorGeometry(QWidget *editor,
		const  QStyleOptionViewItem &option, const  QModelIndex &index) const;
};
