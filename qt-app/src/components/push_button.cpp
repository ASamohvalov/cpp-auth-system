#include "push_button.h"

namespace components
{
  PushButton::PushButton(QWidget* parent) : QPushButton(parent)
  {
    setDefault(true);
    setFixedSize(100, 40);
    setStyleSheet("font-size: 20px; background-color: #2D3F47");
  }
}
