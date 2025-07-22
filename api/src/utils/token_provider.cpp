#include "token_provider.h"
#include "config/env_config.h"

#include <chrono>
#include <crow/utility.h>
#include <exception>
#include <jwt-cpp/jwt.h>
#include <jwt-cpp/traits/kazuho-picojson/defaults.h>
#include <string>

namespace util::token_provider
{
  static int get_access_exp();
  static int get_refresh_exp();
  static std::string& get_access_secret();
  static std::string& get_refresh_secret();
  static std::string generate(const Claims& claims, 
      const std::string& secret_key, int exp_min);
  static bool validate(const std::string& jwt, Claims& claims,
      const std::string& secret_key);

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
    return validate(jwt, claims, get_refresh_secret());
  }

  bool validate_access(const std::string& jwt, Claims& claims)
  {
    return validate(jwt, claims, get_access_secret());
  }

  static int get_access_exp()
  {
    static int exp_min = config::get_int_env("ACCESS_EXCEPTED_MIN");
    return exp_min;
  }

  static int get_refresh_exp()
  {
    static int exp_days = config::get_int_env("REFRESH_EXCEPTED_DAYS");
    return exp_days; 
  }

  static std::string& get_access_secret()
  {
    static std::string access_secret = crow::utility::base64decode(
        config::get_env("ACCESS_TOKEN_ENCODED_SECRET"));
    return access_secret;
  }

  static std::string& get_refresh_secret()
  {
    static std::string refresh_secret = crow::utility::base64decode(
        config::get_env("REFRESH_TOKEN_ENCODED_SECRET"));
    return refresh_secret;
  }

  static std::string generate(const Claims& claims, 
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
        .sign(jwt::algorithm::hs256{secret_key});
    return token;
  }

  static bool validate(const std::string& jwt, Claims& claims, 
      const std::string& secret_key)
  {
    auto decoded = jwt::decode(jwt);

    auto verifier = jwt::verify()
        .allow_algorithm(jwt::algorithm::hs256(secret_key));
    try {
      verifier.verify(decoded);
      claims.subject = decoded.get_subject();
      claims.role = decoded.get_payload_claim("role").as_string();
      return true;
    } catch (const std::exception&) {
      return false;
    }
  }
}