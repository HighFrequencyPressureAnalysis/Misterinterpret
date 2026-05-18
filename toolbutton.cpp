#include "toolbutton.h"

ToolButton::ToolButton(QWidget *parent)
	: QToolButton(parent)
{
	setPopupMode(QToolButton::MenuButtonPopup);
	setAutoRaise(true);
	setArrowType(Qt::NoArrow);
	setToolButtonStyle(Qt::ToolButtonIconOnly);
}

ToolButton::~ToolButton()
{
}
