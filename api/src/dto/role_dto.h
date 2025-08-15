#ifndef ROLE_DTO_H
#define ROLE_DTO_H

#include <string>

namespace dto
{
  struct RoleModel
  {
    long id;
    std::string role;
  };

  enum class Role { Admin, User }; 
  Role str_to_user_role(const std::string& str);
  std::string role_to_string(const Role role);

  struct RoleDto 
  {
    long id;
    Role role;

    RoleDto(const Role role);

    static void set_ids(long admin_id, long user_id);
    
  private:
    static long admin_id;
    static long user_id; // bad
    static long get_id_by_role(const Role role);
  };
}

#endif