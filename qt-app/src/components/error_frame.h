#pragma once

#include <QFrame>
#include <QLabel>

namespace components
{
  class ErrorFrame : public QFrame
  {
    Q_OBJECT
  public:
    ErrorFrame(int width, QWidget* parent = nullptr);

    void setText(const QString& text);

  private:
    QLabel* textLabel;
  };
}