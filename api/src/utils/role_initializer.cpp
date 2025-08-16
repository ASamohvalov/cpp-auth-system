#include "role_initializer.h"
#include "dto/role_dto.h"
#include "repositories/role_repo.h"

#include <crow/logging.h>
#include <string>

namespace util::initializer
{
  void init_roles()
  {
    long admin_id = repositories::role::save_if_exists("Admin");
    long user_id = repositories::role::save_if_exists("User");
    dto::RoleDto::set_ids(admin_id, user_id);
  }
}