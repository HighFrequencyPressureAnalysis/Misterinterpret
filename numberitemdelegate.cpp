#include "numberitemdelegate.h"
#include"QLineEdit"

NumberItemDelegate::NumberItemDelegate(QObject *parent)
	: QItemDelegate(parent)
{
}

NumberItemDelegate::~NumberItemDelegate()
{
}

QWidget* NumberItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
	QLineEdit *editor = new  QLineEdit(parent);
	QRegularExpression regExp("^(?:[1-9][0-9]*\\.[0-9]+|0\\.(?!0+$)[0-9]+)$");
	editor->setValidator(new  QRegularExpressionValidator(regExp, parent));
	return  editor;
}

void NumberItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index)const
{
	QString text = index.model()->data(index, Qt::EditRole).toString();
	QLineEdit *lineEdit = static_cast <QLineEdit*>(editor);
	lineEdit->setText(text);
}

void NumberItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index)const
{
	QLineEdit *lineEdit = static_cast <QLineEdit*>(editor);
	QString text = lineEdit->text();
	model->setData(index, text, Qt::EditRole);
}

void NumberItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
	editor->setGeometry(option.rect);
}