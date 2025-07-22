#ifndef AUTH_JWT_H
#define AUTH_JWT_H

#include <string>

namespace util::token_provider
{
  struct Claims
  {
    std::string subject;
    std::string role;    
  };

  std::string generate_refresh(const Claims& claims);
  std::string generate_access(const Claims& claims);

  bool validate_refresh(const std::string& jwt);
  bool validate_access(const std::string& jwt);
}

#endif