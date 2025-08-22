#include "user_controller.h"
#include "dto/user_dto.h"
#include "middleware/access_middleware.h"
#include "middleware/auth_middleware.h"
#include "repositories/user_repo.h"

#include <crow/mustache.h>

namespace controllers::user 
{
  void account_info(crow::App<middleware::Auth, middleware::Access>& app,
      const crow::request& req, crow::response& res)
  {
    middleware::Auth::context ctx = app.get_context<middleware::Auth>(req);
    dto::UserModel model = repositories::user::get_by_id(ctx.user_id);
    dto::UserDataResponse data = 
        { model.id, model.username, model.first_name, model.last_name, model.role.role };
    res.body = data.to_json().dump();
    res.set_header("Content-Type", "application/json");
    res.end();
  }
}