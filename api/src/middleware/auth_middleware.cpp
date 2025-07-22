#include "auth_middleware.h"
#include <crow/logging.h>

namespace middleware
{
  void Auth::before_handle(crow::request& req, crow::response& res, context& cxt)
  {
    CROW_LOG_DEBUG << "hello from middleware";

    // std::string key = res.get_header_value("Authorization");
    // if (key.substr(7) == "Bearer ") {

    // }
  }

  void Auth::after_handle(crow::request& req, crow::response& res, context& cxt)
  {}
}