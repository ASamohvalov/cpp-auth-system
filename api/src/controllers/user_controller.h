#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "middleware/access_middleware.h"
#include "middleware/auth_middleware.h"
#include <crow/app.h>
#include <crow/http_request.h>
#include <crow/http_response.h>

namespace controllers::user 
{
  void account_info(crow::App<middleware::Auth, middleware::Access>& app,
      const crow::request& req, crow::response& res);
}

#endif