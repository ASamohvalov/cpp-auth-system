#pragma once

#include <QLineEdit>
#include <QWidget>

namespace components
{
  class LineEdit : public QLineEdit
  {
    Q_OBJECT
  public:
    LineEdit(QWidget* parent = nullptr);
  };
}
