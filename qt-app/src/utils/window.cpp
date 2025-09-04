#include "window.h"

#include "views/auth/sign_in_window.h"
#include "views/auth/sign_up_window.h"
#include "views/account/account_window.h"

namespace utils
{
	void initWindow()
	{
		views::BaseWidget* widget = new views::BaseWidget();
		widget->show();
	}

	QVector<views::BaseWindow*> getWindowVector(views::BaseWidget* baseWidget)
	{
		static QVector<views::BaseWindow*> windows = {
			new views::SignInWindow(baseWidget),
			new views::SignUpWindow(baseWidget),
			new views::AccountWindow(baseWidget)
		};
		return windows;
	}

	views::BaseWindow* getWindowByRoute(views::BaseWidget* baseWidget, Route route)
	{
		return getWindowVector(baseWidget)[route];
	}
}
