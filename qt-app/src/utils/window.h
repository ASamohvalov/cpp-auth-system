#pragma once

#include "views/base_window.h"
#include "views/base_widget.h"

#include <QVector>

namespace utils
{
	void initWindow();

	// indexes correspond to routes in enum
	QVector<views::BaseWindow*> getWindowVector(views::BaseWidget* baseWidget);
	views::BaseWindow* getWindowByRoute(views::BaseWidget* baseWidget, Route route);
}
