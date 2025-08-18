#include "auth_controller.h"
#include "dto/user_dto.h"
#include "errors/error.h"
#include "repositories/user_repo.h"
#include "utils/password_encoder.h"
#include "utils/token_provider.h"

#include <crow/json.h>
#include <crow/logging.h>
#include <stdexcept>
#include <string>
#include <utility>

namespace controllers::auth
{
  void sign_in(const crow::request& req, crow::response& res)
  {
    dto::SignInDto user;
    try {
      user = dto::SignInDto::init_from_json(req.body);
    } catch(const std::runtime_error&) {
      error::bad_request(res, "username and password is required");
      return;
    }

    dto::UserModel model = repositories::user::get_by_username(user.username);
    if (!util::password_hash::verify(model.password, user.password)) {
      error::bad_request(res, "wrong username or password");
      return;
    }

    util::token_provider::Claims claims = {
        model.id, std::move(model.username), model.role.role
    }; 
    dto::TokenDataResponse tokenRes = {
      util::token_provider::generate_access(claims),
      util::token_provider::generate_refresh(claims)
    };

    res.body = tokenRes.to_json().dump();
    res.set_header("Content-Type", "application/json");
    res.end();
  }

  void sign_up(const crow::request& req, crow::response& res)
  {
    dto::UserDto user;
    try {
      user = dto::UserDto::init_from_json(req.body);
    } catch (const std::runtime_error&) {
      error::bad_request(
        res, "username, password, first_name and last_name is required"
      );
      return;
    }

    if (repositories::user::exists_by_username(user.username)) {
      error::bad_request(res, "this username already taken");
      return;
    }
    user.password = util::password_hash::get_hash(user.password);
    repositories::user::save(user);

    res.code = 201;
    res.set_header("Content-Type", "application/json");
    res.end();
  }
}
