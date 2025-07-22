#ifndef USER_REPO_H
#define USER_REPO_H

#include "dto/user_dto.h"

namespace repositories::user
{
  // all functions throws SqlException
  void save(dto::UserDto user);
  dto::UserModel get_by_username(const std::string& username);
  bool exists_by_username(const std::string& username);
}

#endif