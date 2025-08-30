#include "sign_in_window.h"
#include "components/error_frame.h"
#include "views/base_widget.h"
#include "views/base_window.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QStackedLayout>
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
    qInfo() << "call constructor";
    emit setHeaderTitle("SIGN IN");

    QVBoxLayout* contentLayout = new QVBoxLayout(this);

    submitBtn->setText("submit");

    QLabel* bottomText = new QLabel("If you don't have an account - register", 
        this);
    bottomText->setMargin(20);
    
    errorFrame->setVisible(false);
    
    // content layout
    contentLayout->addStretch();
    contentLayout->addWidget(errorFrame, 0, Qt::AlignCenter);

    contentLayout->addWidget(usernameEdit, 0, Qt::AlignCenter);
    contentLayout->addWidget(passwordEdit, 0, Qt::AlignCenter);
    contentLayout->addWidget(submitBtn, 0, Qt::AlignCenter);

    contentLayout->addWidget(bottomText, 0, Qt::AlignCenter);
    contentLayout->addStretch();

    // signals and slots
    connect(submitBtn, &QPushButton::clicked, this, &SignInWindow::onSubmitBtnClick);
  }

  void SignInWindow::onSubmitBtnClick()
  {
    if (usernameEdit->text().isEmpty() || passwordEdit->text().isEmpty()) {
      showErrorFrame("all fields must be filled");
      QTimer::singleShot(360, this, &SignInWindow::errorFrameShowTimeout);
      return;
    }

    // send to server function
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
