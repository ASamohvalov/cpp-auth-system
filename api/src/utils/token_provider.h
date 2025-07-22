#ifndef AUTH_JWT_H
#define AUTH_JWT_H

#include <string>

namespace util
{
  class TokenProvider
  {
  public:
    TokenProvider();

    struct Claims
    {
      std::string subject;
      std::string role;    
    };

    std::string generate_refresh(const Claims& claims);
    std::string generate_access(const Claims& claims);

    bool validate_refresh(const std::string& jwt);
    bool validate_access(const std::string& jwt);

  private:
    void load_env();

    static int access_excepted_min;
    static int refresh_excepted_min;
    static std::string access_secret;
    static std::string refresh_secret;
  };
}

#endif