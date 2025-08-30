#pragma once

#include "views/base_window.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QFrame>
#include <QLabel>

namespace views
{
  class BaseWidget : public QWidget
  {
    Q_OBJECT
  public:
    BaseWidget(QWidget* parent = nullptr);
    BaseWidget(BaseWindow* content, QWidget* parent = nullptr);

    void setContent(BaseWindow* content);

  private slots:
    void onSetHeaderTitle(const QString& text);

  private:
    void init();

    QVBoxLayout* mainLayout;
    QFrame* header;
    QLabel* headerTitle;
    QLabel* logoutLink;

    BaseWindow* content;
  };
}