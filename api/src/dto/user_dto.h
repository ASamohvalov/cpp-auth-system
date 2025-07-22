#ifndef USER_DTO_H
#define USER_DTO_H

#include <string>

namespace dto 
{
  struct UserModel
  {
    long id = -1;

    std::string username = "";
    std::string password = "";
    std::string first_name = "";
    std::string last_name = "";
  
    static UserModel init_from_json(std::string json);
  };

  struct SignInDto
  {
    std::string username = "";
    std::string password = "";
  
    static SignInDto init_from_json(std::string json);
  };

  struct UserDto
  {
    std::string username = "";
    std::string password = "";
    std::string first_name = "";
    std::string last_name = "";

    static UserDto init_from_json(std::string json);
  };
}

#endif