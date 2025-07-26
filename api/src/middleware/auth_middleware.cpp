#include "auth_middleware.h"
#include "dto/user_dto.h"
#include "utils/token_provider.h"

#include <crow/logging.h>

namespace middleware 
{
  void Auth::before_handle(crow::request &req, crow::response &res, 
      context &cxt) 
  {
    std::string auth = req.get_header_value("Authorization");
    if (auth.rfind("Bearer ", 0) == 0) {

      util::token_provider::Claims claims;

      std::string token = auth.substr(7);
      if (util::token_provider::validate_access(token, claims)) {
        CROW_LOG_DEBUG << "token is valid";
        cxt.user_id = claims.user_id;
        cxt.username = claims.subject;
        cxt.role = claims.role;
        return;
      }
    }
  }

  void Auth::after_handle(crow::request &req, crow::response &res, 
      context &cxt) 
  {}
}