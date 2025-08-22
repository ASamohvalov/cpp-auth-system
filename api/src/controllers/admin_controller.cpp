#include "admin_controller.h"
#include "dto/role_dto.h"
#include "dto/user_dto.h"
#include "errors/error.h"
#include "repositories/user_repo.h"

#include <crow/logging.h>
#include <vector>

namespace controllers::admin
{
  void users_info(const crow::request& req, crow::response& res)
  {
    std::vector<dto::UserDataResponse> users = repositories::user::get_all();
    res.body = dto::vector_to_json(users).dump();
    res.add_header("Content-Type", "application/json");
    res.end();
  }

  void give_admin_role(const crow::request& req, crow::response& res, 
      long user_id)
  {
    dto::UserModel user = repositories::user::get_by_id(user_id);
    if (user.id == -1) { // if empty result
      error::bad_request(res, "such id not found");
      return;
    }
    user.role = { dto::RoleDto(dto::Role::Admin).id };
    repositories::user::update(user);
    res.end();
  }
}
