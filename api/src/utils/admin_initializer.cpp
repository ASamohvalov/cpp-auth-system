#include "admin_initializer.h"
#include "config/env_config.h"
#include "dto/role_dto.h"
#include "dto/user_dto.h"
#include "repositories/user_repo.h"
#include "utils/password_encoder.h"

#include <crow/logging.h>
#include <string>

namespace util::initializer 
{
  void init_default_admin()
  {
    std::string username = config::get_env("ADMIN_USERNAME");
    std::string password = 
          util::password_hash::get_hash(config::get_env("ADMIN_PASSWORD"));

    dto::UserDto admin = { username, password, "", "", dto::RoleDto(dto::Role::Admin) };
    if (!repositories::user::exists_by_username(username)) {
      repositories::user::save(admin);
    }
  }
}