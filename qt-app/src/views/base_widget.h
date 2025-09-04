#pragma once

#include "utils/router.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QStackedWidget>
#include <QVector>

namespace views
{
  class BaseWidget : public QWidget
  {
    Q_OBJECT
  public:
    BaseWidget(QWidget* parent = nullptr);

  private slots:
    void onSetHeaderTitle(const QString& text);
		void onSetHederStyleSheet(const QString& styleSheet);
		void onChangeRoute(utils::Route route);

  private:
		void changeContent(utils::Route route);

    QVBoxLayout* mainLayout;
    QFrame* header;
    QLabel* headerTitle;
    QLabel* logoutLink;

    QStackedWidget* content;
  };
}
