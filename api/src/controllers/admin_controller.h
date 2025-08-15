#ifndef ADMIN_CONTROLLER_H
#define ADMIN_CONTROLLER_H

#include <crow/http_request.h>
#include <crow/http_response.h>

namespace controllers::admin
{
  void users_info(const crow::request& req, crow::response& res);
  void give_admin_role(const crow::request& req, crow::response& res);
}

#endif