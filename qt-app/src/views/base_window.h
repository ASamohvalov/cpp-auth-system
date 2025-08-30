#pragma once

#include <QWidget>

namespace views
{
  class BaseWindow : public QWidget
  {
    Q_OBJECT
  public:
    BaseWindow(QWidget* parent = nullptr);

  signals:
    void setHeaderBackground();
    void setHeaderTitle(const QString& text);
  };
}
