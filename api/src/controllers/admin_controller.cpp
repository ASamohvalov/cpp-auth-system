#include "admin_controller.h"
#include "dto/user_dto.h"
#include "repositories/user_repo.h"

#include <crow/logging.h>
#include <vector>

namespace controllers::admin
{
  void users_info(const crow::request& req, crow::response& res)
  {
    std::vector<dto::UserDataResponse> users = repositories::user::get_all();
    res.body = dto::vectorToJson(users).dump();
    res.add_header("Content-Type", "application/json");
    res.end();
  }

  void give_admin_role(const crow::request& req, crow::response& res)
  {
    
  }
}
