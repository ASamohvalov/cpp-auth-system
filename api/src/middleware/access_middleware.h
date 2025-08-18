#ifndef ACCESS_MIDDLEWARE_H
#define ACCESS_MIDDLEWARE_H

#include <crow/http_request.h>
#include <crow/http_response.h>
#include "config/json_config.h"
#include "middleware/auth_middleware.h"
#include <crow/logging.h>
#include <vector>

namespace middleware 
{
  struct Access 
  {
    struct context 
    {};

    template <typename AllContext>
    void before_handle(crow::request& req, crow::response& res, 
        context& ctx, AllContext& all_ctx) 
    {
      std::vector<std::string> values = config::get_route_json(req.url);
      if (values[0] == "*") return;
      Auth::context auth_ctx = all_ctx.template get<Auth>();
      for (std::string& val : values) {
        if (val == auth_ctx.role) return;
      }
      res.code = 403;
      res.end();
    }

    void after_handle(crow::request &req, crow::response &res, context &ctx);
  };
}

#endif