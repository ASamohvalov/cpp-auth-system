#include "base_widget.h"
#include "qboxlayout.h"
#include "views/base_window.h"
#include "utils/router.h"
#include "utils/window.h"

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
			, content(new QStackedWidget(this))
  {
    setFixedSize(800, 600);

    mainLayout->setContentsMargins(0, 0, 0, 0);

    header->setFixedHeight(80);

    QHBoxLayout* headerLayout = new QHBoxLayout(header);

    headerTitle->setFont( { "Aral", 43 } ); 
    logoutLink->setText("logout");

    headerLayout->addWidget(headerTitle);
    headerLayout->addStretch();
    headerLayout->addWidget(logoutLink);

    // init routes
		QVector<BaseWindow*> windows = utils::getWindowVector(this);
		for (BaseWindow* window : windows) {
			content->addWidget(window);
			connect(window, &BaseWindow::setHeaderTitle, this, 
    	    &BaseWidget::onSetHeaderTitle);
			connect(window, &BaseWindow::setHeaderStyleSheet, this, 
    	    &BaseWidget::onSetHederStyleSheet);
			connect(window, &BaseWindow::changeRoute, this, 
    	    &BaseWidget::onChangeRoute);
		}

		changeContent(utils::SignUp);

    mainLayout->addWidget(header);
    mainLayout->addWidget(content);
  }

  void BaseWidget::onSetHeaderTitle(const QString& text)
  {
    headerTitle->setText(text);
  }

	void BaseWidget::onSetHederStyleSheet(const QString& styleSheet)
	{
		header->setStyleSheet(styleSheet);
	}

	void BaseWidget::onChangeRoute(utils::Route route)
	{
		changeContent(route);
	}

	void BaseWidget::changeContent(utils::Route route)
	{
		content->setCurrentIndex(route);
		utils::getWindowByRoute(this, route)->after();
	}
}
