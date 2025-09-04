#include "sign_in_window.h"
#include "components/error_frame.h"
#include "views/base_window.h"
#include "utils/router.h"
#include "components/clickable_label.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QTimer>
#include <QDebug>

namespace views 
{
  SignInWindow::SignInWindow(QWidget* parent) 
      : BaseWindow(parent)
      , usernameEdit(new components::LineEdit(this))
      , passwordEdit(new components::LineEdit(this))
      , submitBtn(new components::PushButton(this))
      , errorFrame(new components::ErrorFrame(300, this))
  {
    // components
    QVBoxLayout* contentLayout = new QVBoxLayout(this);

    submitBtn->setText("submit");

		QFrame* bottomTextFrame = new QFrame(this);
		
		QHBoxLayout* bottomTextLayout = new QHBoxLayout(bottomTextFrame);
    QLabel* bottomText = new QLabel("If you don't have an account - ", this);
		components::ClickableLabel* bottomLabel = new components::ClickableLabel(this);

		bottomLabel->setText("sign up");
		bottomTextLayout->addWidget(bottomText);
		bottomTextLayout->addWidget(bottomLabel);
    
    errorFrame->setVisible(false);
    
    // content layout
    contentLayout->addStretch();
    contentLayout->addWidget(errorFrame, 0, Qt::AlignCenter);

    contentLayout->addWidget(usernameEdit, 0, Qt::AlignCenter);
    contentLayout->addWidget(passwordEdit, 0, Qt::AlignCenter);
    contentLayout->addWidget(submitBtn, 0, Qt::AlignCenter);

    contentLayout->addWidget(bottomTextFrame, 0, Qt::AlignCenter);
    contentLayout->addStretch();

    // signals and slots
    connect(submitBtn, &QPushButton::clicked, this, &SignInWindow::onSubmitBtnClick);
		connect(bottomLabel, &components::ClickableLabel::clicked, this, [this]() {
			emit changeRoute(utils::Route::SignUp);
		});
  }

	void SignInWindow::after() 
	{
    emit setHeaderTitle("SIGN IN");
		emit setHeaderStyleSheet("background-color: #288F32");
	}

  void SignInWindow::onSubmitBtnClick()
  {
    if (usernameEdit->text().isEmpty() || passwordEdit->text().isEmpty()) {
      showErrorFrame("all fields must be filled");
      QTimer::singleShot(360, this, &SignInWindow::errorFrameShowTimeout);
      return;
    }

    // send to server function
		emit changeRoute(utils::Route::Account);
  }

  void SignInWindow::errorFrameShowTimeout()
  {
    errorFrame->setVisible(false);
  }

  void SignInWindow::showErrorFrame(const QString& msg)
  {
    errorFrame->setVisible(true);
    errorFrame->setText(msg);
  }
}
