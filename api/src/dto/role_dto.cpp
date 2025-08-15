#include "role_dto.h"

namespace dto
{
  long RoleDto::user_id = -1;
  long RoleDto::admin_id = -1;

  Role str_to_user_role(const std::string& str)
  {
    if (str == "Admin")
      return Role::Admin;
    return Role::User;
  }

  std::string role_to_string(const Role role)
  {
    if (role == Role::Admin) 
      return "Admin";
    return "User";
  }

  RoleDto::RoleDto(const Role role) : id(get_id_by_role(role)), role(role) {}

  void RoleDto::set_ids(long admin_id, long user_id)
  {
    RoleDto::admin_id = admin_id;
    RoleDto::user_id = user_id;
  }

  long RoleDto::get_id_by_role(const Role role)
  {
    if (role == Role::Admin) 
      return admin_id;
    return user_id;
  }
}