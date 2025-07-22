#ifndef AUTH_MIDDLEWARE_H
#define AUTH_MIDDLEWARE_H

#include <crow/http_request.h>
#include <crow/http_response.h>

namespace middleware
{
  struct Auth
  {
    struct context
    {
      long user_id;
      std::string username;
    };

    void before_handle(crow::request& req, crow::response& res, context& ctx);
    void after_handle(crow::request& req, crow::response& res, context& ctx);
  };
}

#endif