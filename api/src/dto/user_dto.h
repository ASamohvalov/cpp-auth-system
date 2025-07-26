#ifndef USER_DTO_H
#define USER_DTO_H

#include <string>

namespace dto 
{
  enum class UserRole { Admin, User };
  UserRole str_to_user_role(const std::string& str);

  struct UserModel
  {
    long id = -1;

    std::string username = "";
    std::string password = "";
    std::string first_name = "";
    std::string last_name = "";
  
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

    static UserDto init_from_json(const std::string& json);
  };

  struct UserDataResponse
  {
    std::string username;
    std::string first_name;
    std::string last_name;
  
    std::string to_json();
  };

  struct TokenDataResponse
  {
    std::string access_token;
    std::string refresh_token;

    std::string to_json();
  };
}

#endif