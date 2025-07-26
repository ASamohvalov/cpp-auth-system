#include "user_dto.h"

#include <crow/json.h>
#include <sstream>

namespace dto 
{
  UserRole str_to_user_role(const std::string& str)
  {
    if (str == "Admin")
      return UserRole::Admin;
    return UserRole::User;
  }

  UserModel UserModel::init_from_json(const std::string& json)
  {
    crow::json::rvalue json_body = crow::json::load(json);
    dto::UserModel user {
      json_body["id"].i(),
      json_body["username"].s(), 
      json_body["password"].s(),
      json_body["first_name"].s(),
      json_body["last_name"].s(),
    };
    return user;
  }

  SignInDto SignInDto::init_from_json(const std::string& json)
  {
    crow::json::rvalue json_body = crow::json::load(json);
    dto::SignInDto user {
      json_body["username"].s(), 
      json_body["password"].s(),
    };
    return user;   
  }

  UserDto UserDto::init_from_json(const std::string& json)
  {
    crow::json::rvalue json_body = crow::json::load(json);
    dto::UserDto user {
      json_body["username"].s(), 
      json_body["password"].s(),
      json_body["first_name"].s(),
      json_body["last_name"].s(),
    };
    return user;
  }

  std::string UserDataResponse::to_json()
  {
    std::ostringstream ss;
    ss << "{ \"username\": \"" << username << "\", \"first_name\": \""
        << first_name << "\", \"last_name\": \"" << last_name << "\" }";
    return ss.str();
  }

  std::string TokenDataResponse::to_json()
  {
    std::ostringstream ss;
    ss << "{ \"access_token\": \"" << access_token << "\","
          "\"refresh_token\": \"" << refresh_token << "\" }";
    return ss.str();
  }
}