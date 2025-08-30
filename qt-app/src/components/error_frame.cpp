#include "error_frame.h"

#include <QVBoxLayout>

namespace components
{
  ErrorFrame::ErrorFrame(int width, QWidget* parent) 
      : QFrame(parent)
      , textLabel(new QLabel(this))
  {
    QVBoxLayout* errorFrameLayout = new QVBoxLayout(this);
    setFixedWidth(width);
    setStyleSheet("background-color: #4A1212;"
                              "border: 2px solid #A33434;"
                              "border-radius: 3px;");
    textLabel->setStyleSheet("border: none; font-size: 15px;");
    textLabel->setMargin(15);
  
    errorFrameLayout->addWidget(textLabel, 0, Qt::AlignCenter);
  }

  void ErrorFrame::setText(const QString& text)
  {
    textLabel->setText(text);
  }
}