#pragma once

#include <QPushButton>
#include <QWidget>

namespace components
{
  class PushButton : public QPushButton
  {
    Q_OBJECT
  public:
    PushButton(QWidget* parent = nullptr);
  };
}
