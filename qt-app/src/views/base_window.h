#pragma once

#include "utils/router.h"

#include <QWidget>

namespace views
{
  class BaseWindow : public QWidget
  {
    Q_OBJECT
  public:
    BaseWindow(QWidget* parent = nullptr);
		virtual ~BaseWindow();

		// call this after signal and slot connection
		virtual void after() = 0;

  signals:
		void setHeaderStyleSheet(const QString& styleSheet);
    void setHeaderTitle(const QString& text);
		void changeRoute(utils::Route route);
  };
}
