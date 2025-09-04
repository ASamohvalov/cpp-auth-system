#include "utils/window.h"

#include <QApplication>

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
	utils::initWindow();
  return app.exec();
}
