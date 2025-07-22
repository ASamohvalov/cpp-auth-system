#ifndef AUTH_CONTROLLER_H
#define AUTH_CONTROLLER_H

#include <crow/http_request.h>
#include <crow/http_response.h>

namespace controllers::auth
{
  void sign_in(const crow::request& req, crow::response& res);
  void sign_up(const crow::request& req, crow::response& res);
}

#endif