#include "views/auth/sign_in_window.h"
#include "views/base_widget.h"

#include <QApplication>

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  views::BaseWidget widget(new views::SignInWindow());
  widget.show();
  return app.exec();
}