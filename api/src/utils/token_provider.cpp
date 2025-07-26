#include "token_provider.h"
#include "config/env_config.h"

#include <chrono>
#include <crow/utility.h>
#include <jwt-cpp/jwt.h>
#include <jwt-cpp/traits/kazuho-picojson/defaults.h>
#include <picojson/picojson.h>
#include <string>

#define JWT_ALGORITHM(secret) (jwt::algorithm::hs256((secret)))

namespace util::token_provider
{
  namespace
  {
    // @return number of seconds
    int get_access_exp()
    {
      static int exp_time = config::get_int_env("ACCESS_EXCEPTED_MIN") * 60;
      return exp_time;
    }

    // @return number of seconds
    int get_refresh_exp()
    {
      static int exp_time = 
          config::get_int_env("REFRESH_EXCEPTED_DAYS") * 24 * 60 * 60;
      return exp_time; 
    }

    std::string& get_access_secret()
    {
      static std::string access_secret = crow::utility::base64decode(
          config::get_env("ACCESS_TOKEN_ENCODED_SECRET"));

      return access_secret;
    }

    std::string& get_refresh_secret()
    {
      static std::string refresh_secret = crow::utility::base64decode(
          config::get_env("REFRESH_TOKEN_ENCODED_SECRET"));

      return refresh_secret;
    }

    std::string generate(const Claims& claims, 
        const std::string& secret_key, int exp_sec)
    {
      auto current_time = std::chrono::system_clock::now();
      auto exp_time = current_time + std::chrono::seconds{exp_sec};

      std::string token = jwt::create()
          .set_type("JWT")
          .set_issued_at(current_time)
          .set_expires_at(exp_time)
          .set_subject(claims.subject)
          .set_payload_claim("role", jwt::claim(claims.role))
          .set_payload_claim("user_id", picojson::value(int64_t{claims.user_id})) 
          .sign(JWT_ALGORITHM(secret_key));
      return token;
    }

    bool validate_with_claims(const std::string& jwt, Claims& claims, 
        const std::string& secret_key)
    {
      auto decoded = jwt::decode(jwt);
      auto verifier = jwt::verify()
          .allow_algorithm(JWT_ALGORITHM(secret_key));
      try {
        verifier.verify(decoded);
        claims.user_id = decoded.get_payload_claim("user_id").as_number();
        claims.subject = decoded.get_subject();
        claims.role = decoded.get_payload_claim("role").as_string();
        return true;
      } catch (...) {
        return false;
      }
    }

    bool validate(const std::string& jwt, const std::string& secret_key)
    {
      auto decoded = jwt::decode(jwt);
      auto verifier = jwt::verify()
          .allow_algorithm(JWT_ALGORITHM(secret_key));
      try {
        verifier.verify(decoded);
        return true;
      } catch (...) {
        return false;
      }
    }
  }

  std::string generate_refresh(const Claims& claims) 
  {
    return generate(claims, get_refresh_secret(), get_refresh_exp());
  }

  std::string generate_access(const Claims& claims)
  {
    return generate(claims, get_access_secret(), get_access_exp());
  }

  bool validate_refresh(const std::string& jwt, Claims& claims)
  {
    return validate_with_claims(jwt, claims, get_refresh_secret());
  }

  bool validate_access(const std::string& jwt, Claims& claims)
  {
    return validate_with_claims(jwt, claims, get_access_secret());
  }
  
  bool validate_refresh(const std::string& jwt)
  {
    return validate(jwt, get_refresh_secret());
  }

  bool validate_access(const std::string& jwt)
  {
    return validate(jwt, get_access_secret());
  }
}