#include "account_window.h"

namespace views
{
	AccountWindow::AccountWindow(QWidget* parent) : BaseWindow(parent)
	{}

	void AccountWindow::after()
	{
		emit setHeaderTitle("ACCOUNT");
		emit setHeaderStyleSheet("background-color: #316485");
	}
}
