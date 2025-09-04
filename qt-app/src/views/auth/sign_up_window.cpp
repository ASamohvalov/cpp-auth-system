#include "sign_up_window.h"
#include "components/clickable_label.h"
#include "utils/router.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>

namespace views
{
	SignUpWindow::SignUpWindow(QWidget* parent) : BaseWindow(parent)
			, usernameEdit(new components::LineEdit(this))
			, passwordEdit(new components::LineEdit(this))
			, firstNameEdit(new components::LineEdit(this))
			, lastNameEdit(new components::LineEdit(this))
			, submitBtn(new components::PushButton(this))
			,	errorFrame(new components::ErrorFrame(300, this))
	{
		QHBoxLayout* contentLayout = new QHBoxLayout(this);
		QFrame* editsFrame = new QFrame(this);

		QVBoxLayout* editsLayout = new QVBoxLayout(editsFrame);
		
    errorFrame->setVisible(false);

		QLabel* usernameTopText = new QLabel("username", this);
		QLabel* passwordTopText = new QLabel("password", this);
		QLabel* firstNameTopText = new QLabel("first name", this);
		QLabel* lastNameTopText = new QLabel("last name", this);

		submitBtn->setText("submit");

		QFrame* haveAccountFrame = new QFrame(editsFrame);
		QHBoxLayout* haveAccountLayout = new QHBoxLayout(haveAccountFrame);
		QLabel* haveAccountLabel = new QLabel("already have an account? ", 
				haveAccountFrame);
		components::ClickableLabel* haveAccountClickableLabel = 
				new components::ClickableLabel("sign in", haveAccountFrame);
		haveAccountLayout->addWidget(haveAccountLabel);
		haveAccountLayout->addWidget(haveAccountClickableLabel);

		editsLayout->addStretch();
		editsLayout->addWidget(errorFrame, 0, Qt::AlignCenter);
		editsLayout->addWidget(usernameTopText);
		editsLayout->addWidget(usernameEdit, 0, Qt::AlignCenter);

		editsLayout->addWidget(passwordTopText);
		editsLayout->addWidget(passwordEdit, 0, Qt::AlignCenter);

		editsLayout->addWidget(firstNameTopText);
		editsLayout->addWidget(firstNameEdit, 0, Qt::AlignCenter);

		editsLayout->addWidget(lastNameTopText);
		editsLayout->addWidget(lastNameEdit, 0, Qt::AlignCenter);

		editsLayout->addWidget(submitBtn, 0, Qt::AlignCenter);

		editsLayout->addWidget(haveAccountFrame, 0, Qt::AlignCenter);
		editsLayout->addStretch();

		contentLayout->addStretch();
		contentLayout->addWidget(editsFrame);
		contentLayout->addStretch();

		// signals and slots connection
		connect(submitBtn, &components::PushButton::clicked, this, 
				&SignUpWindow::onSubmitBtnClicked);
		connect(haveAccountClickableLabel, &components::ClickableLabel::clicked, this,
				[this]() {
					emit changeRoute(utils::Route::SignIn);
				}
		);
	}

	void SignUpWindow::after()
	{
		emit setHeaderTitle("SIGN UP");
		emit setHeaderStyleSheet("background-color: #45A2A3");
	}

	void SignUpWindow::onSubmitBtnClicked()
	{
    if (usernameEdit->text().isEmpty() || passwordEdit->text().isEmpty() ||
				firstNameEdit->text().isEmpty() || lastNameEdit->text().isEmpty()) {
			errorFrame->setText("all fields must be filled");
			errorFrame->setVisible(true);	
		} else if (usernameEdit->text().size() < 5 || passwordEdit->text().size() < 5) {
			errorFrame->setText("username or password is to short");
			errorFrame->setVisible(true);	
		}

		// send to server function ... 

		emit changeRoute(utils::Route::Account);
	}
}

