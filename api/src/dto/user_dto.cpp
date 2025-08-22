#include "user_dto.h"

#include <crow/json.h>

namespace dto 
{
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

  crow::json::wvalue UserDataResponse::to_json() const
  {
    crow::json::wvalue obj;
    obj["id"] = id;
    obj["username"] = username;
    obj["first_name"] = first_name;
    obj["last_name"] = last_name;
    obj["role"] = role;
    return obj;
  }

  crow::json::wvalue TokenDataResponse::to_json() const
  {
    crow::json::wvalue obj;
    obj["refresh_token"] = refresh_token;
    obj["access_token"] = access_token;
    return obj;
  }
}