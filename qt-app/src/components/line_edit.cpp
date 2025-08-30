#include "line_edit.h"

namespace components
{
  LineEdit::LineEdit(QWidget* parent) : QLineEdit(parent)
  {
    setFixedSize(300, 40);
    setStyleSheet("font-size: 25px");
  }
}