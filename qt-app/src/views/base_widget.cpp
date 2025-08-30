#include "base_widget.h"
#include "qboxlayout.h"
#include "views/base_window.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>
#include <QDebug>

namespace views
{
  BaseWidget::BaseWidget(QWidget* parent) : QWidget(parent)
      , mainLayout(new QVBoxLayout(this))
      , header(new QFrame(this))
      , headerTitle(new QLabel(header))
      , logoutLink(new QLabel(header))
      , content(new BaseWindow(this))
  {
    // init();

    // QLabel* noContentLabel = new QLabel("no content here", content);
    // QVBoxLayout* contentLayout = new QVBoxLayout(content);
    // contentLayout->addWidget(noContentLabel);
  }

  BaseWidget::BaseWidget(BaseWindow* content, QWidget* parent) : QWidget(parent)
      , mainLayout(new QVBoxLayout(this))
      , header(new QFrame(this))
      , headerTitle(new QLabel(header))
      , logoutLink(new QLabel(header))
      , content(content)
  {
    init();  
  }

  void BaseWidget::onSetHeaderTitle(const QString& text)
  {
    qInfo() << "slot";
    headerTitle->setText(text);
  }

  void BaseWidget::init()
  {
    setFixedSize(800, 600);

    mainLayout->setContentsMargins(0, 0, 0, 0);

    header->setFixedHeight(80);
    header->setStyleSheet("background-color: #288F32");

    QHBoxLayout* headerLayout = new QHBoxLayout(header);

    headerTitle->setFont( { "Aral", 43 } ); 
    logoutLink->setText("logout");

    headerLayout->addWidget(headerTitle);
    headerLayout->addStretch();
    headerLayout->addWidget(logoutLink);

    mainLayout->addWidget(header);
    mainLayout->addWidget(content);

    // signals and slots
    qInfo() << connect(content, &BaseWindow::setHeaderTitle, this, 
        &BaseWidget::onSetHeaderTitle);
  }

  void BaseWidget::setContent(BaseWindow* content)
  {
    this->content = content;
  }
}
