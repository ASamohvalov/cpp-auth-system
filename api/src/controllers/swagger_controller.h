#ifndef SWAGGER_CONTROLLER_H
#define SWAGGER_CONTROLLER_H

#include <crow/http_response.h>

namespace controllers::swagger
{
  crow::response load_file();
}

#endif