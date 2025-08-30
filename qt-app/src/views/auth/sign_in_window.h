#pragma once

#include "components/error_frame.h"
#include "components/line_edit.h"
#include "components/push_button.h"
#include "views/base_window.h"

#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

namespace views
{
  class SignInWindow : public BaseWindow 
  {
    Q_OBJECT    
  public:
    SignInWindow(QWidget* parent = nullptr);
  
  private slots:
    void onSubmitBtnClick();
    void errorFrameShowTimeout();
  
  private:
    void showErrorFrame(const QString& msg);

    components::LineEdit* usernameEdit;
    components::LineEdit* passwordEdit;
    components::PushButton* submitBtn;
    components::ErrorFrame* errorFrame;
  };
}
