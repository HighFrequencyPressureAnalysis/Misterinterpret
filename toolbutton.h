#pragma once
#include <QToolButton>

//工具栏按钮

class ToolButton : public QToolButton
{
	Q_OBJECT

public:
	ToolButton(QWidget *parent);
	~ToolButton();
};
