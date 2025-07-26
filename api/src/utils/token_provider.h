#ifndef AUTH_JWT_H
#define AUTH_JWT_H

#include <string>

namespace util::token_provider
{
    struct Claims
    {
      long user_id;
      std::string subject;
      std::string role;    
    
      // Claims(Claims&&) noexcept;
    };

    std::string generate_refresh(const Claims& claims);
    std::string generate_access(const Claims& claims);

    // set claims from token if it's valid
    bool validate_refresh(const std::string& jwt, Claims& claims);
    bool validate_access(const std::string& jwt, Claims& claims);

    bool validate_refresh(const std::string& jwt);
    bool validate_access(const std::string& jwt);
}

#endif