#pragma once

#include <QLabel>
#include <QString>

namespace components
{
	class ClickableLabel : public QLabel 
	{ 
    Q_OBJECT 

	public:
	  ClickableLabel(QWidget* parent = nullptr);
	  ClickableLabel(const QString& text, QWidget* parent = nullptr);
	
	signals:
	  void clicked();
	
	protected:
	  void mousePressEvent(QMouseEvent* event);

	private:
		void init();
	};
}
