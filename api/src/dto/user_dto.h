#ifndef USER_DTO_H
#define USER_DTO_H

#include <crow/json.h>
#include <jwt-cpp/jwt.h>
#include <string>
#include <vector>

#include "role_dto.h"

namespace dto 
{
  // models are objects that correspond exactly to tables in the database
  struct UserModel
  {
    long id = -1;

    std::string username = "";
    std::string password = "";
    std::string first_name = "";
    std::string last_name = "";
  
    RoleModel role { -1, "User" };
    
    static UserModel init_from_json(const std::string& json);
  };

  struct SignInDto
  {
    std::string username = "";
    std::string password = "";
  
    static SignInDto init_from_json(const std::string& json);
  };

  struct UserDto
  {
    std::string username = "";
    std::string password = "";
    std::string first_name = "";
    std::string last_name = "";

    RoleDto role { Role::User };

    static UserDto init_from_json(const std::string& json);
  };

  struct UserDataResponse
  {
    long id;

    std::string username;
    std::string first_name;
    std::string last_name;
  
    std::string role;
  
    crow::json::wvalue to_json() const;
  };

  struct TokenDataResponse
  {
    std::string access_token;
    std::string refresh_token;

    crow::json::wvalue to_json() const;
  };

  template<typename T>
  crow::json::wvalue vector_to_json(const std::vector<T>& dtos)
  {
    crow::json::wvalue::list array;
    for (const auto& dto : dtos) {
      array.push_back(dto.to_json());
    }
    return array;
  }
}

#endif