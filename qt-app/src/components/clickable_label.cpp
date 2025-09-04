#include "clickable_label.h"

namespace components
{
	ClickableLabel::ClickableLabel(QWidget* parent)
    : QLabel(parent) 
	{
		init();
	}

	ClickableLabel::ClickableLabel(const QString& text, QWidget* parent)
			: QLabel(text, parent)
	{
		init();	
	}

	void ClickableLabel::mousePressEvent(QMouseEvent*) 
	{
	  emit clicked();
	}

	void ClickableLabel::init()
	{
		setCursor(Qt::PointingHandCursor);
		setStyleSheet("color: blue");
	}
}
