#pragma once

#include "views/base_window.h"
#include "components/line_edit.h"
#include "components/push_button.h"
#include "components/error_frame.h"

namespace views
{
	class SignUpWindow : public BaseWindow
	{
		Q_OBJECT
	public:
		SignUpWindow(QWidget* parent);

		void after() override;

	private slots:
		void onSubmitBtnClicked();

	private:
		components::LineEdit* usernameEdit;
		components::LineEdit* passwordEdit;
		components::LineEdit* firstNameEdit;
		components::LineEdit* lastNameEdit;

		components::PushButton* submitBtn;

		components::ErrorFrame* errorFrame;
	};
}
