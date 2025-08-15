#ifndef USER_REPO_H
#define USER_REPO_H

#include "dto/user_dto.h"
#include <vector>

namespace repositories::user
{
  // all functions throws SqlException
  void save(const dto::UserDto& user);
  dto::UserModel get_by_username(const std::string& username);
  bool exists_by_username(const std::string& username);
  dto::UserModel get_by_id(long id);
  std::vector<dto::UserDataResponse> get_all();
}

#endif