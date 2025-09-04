#pragma once

#include "views/base_window.h"

namespace views
{
	class AccountWindow : public BaseWindow
	{
		Q_OBJECT
	public:
		AccountWindow(QWidget* parent = nullptr);
		void after() override;
	};
}
