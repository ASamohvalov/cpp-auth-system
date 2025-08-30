#pragma once

#include "views/base_widget.h"

namespace utils
{
  enum class Route
  {
    SignIn, SignUp, Account
  };

  void showWindow(const views::BaseWidget& baseWidget, Route route);
}