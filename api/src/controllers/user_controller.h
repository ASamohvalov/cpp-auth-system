#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "utils/app.h"
#include <crow/app.h>
#include <crow/http_request.h>
#include <crow/http_response.h>

namespace controllers::user 
{
  void account_info(Application& app,
      const crow::request& req, crow::response& res);
}

#endif