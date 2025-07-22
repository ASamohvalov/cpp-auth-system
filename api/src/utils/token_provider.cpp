#include "token_provider.h"
#include "config/env_config.h"

#include <crow/utility.h>
#include <jwt-cpp/jwt.h>
#include <jwt-cpp/traits/kazuho-picojson/defaults.h>

namespace util
{
  TokenProvider::TokenProvider()
  {
    
    load_env(); 
  }

  void TokenProvider::load_env()
  {
    access_excepted_min = config::get_int_env("ACCESS_EXCEPTED_MIN");
    refresh_excepted_min = config::get_int_env("REFRESH_EXCEPTED_DAYS");

    access_secret = crow::utility::base64decode(
        config::get_env("ACCESS_TOKEN_ENCODED_SECRET"));
    refresh_secret = crow::utility::base64decode(
        config::get_env("REFRESH_TOKEN_ENCODED_SECRET"));
  }

#if 0
  static int access_excepted_min = config::get_int_env("ACCESS_EXCEPTED_MIN");
  static int refresh_excepted_min = config::get_int_env("REFRESH_EXCEPTED_DAYS");
  static std::string access_secret = crow::utility::base64decode(
      config::get_env("ACCESS_TOKEN_ENCODED_SECRET"));
  static std::string refresh_secret = crow::utility::base64decode(
      config::get_env("REFRESH_TOKEN_ENCODED_SECRET"));

  std::string generate_refresh(const Claims& claims) 
  {
    
    std::string token = jwt::create()
				.set_issuer("auth0")
		    .set_type("JWT")
		    .set_id("rsa-create-example")
		    .set_issued_now()
		    .set_expires_in(std::chrono::seconds{36000})
		    .set_payload_claim("sample", jwt::claim(std::string{"test"}))
		    .sign(jwt::algorithm::hs256("", refresh_secret_encoded, "", ""));
  }

  std::string generate_access(const Claims& claims)
  {}

  bool validate_refresh(const std::string& jwt)
  {}

  bool validate_access(const std::string& jwt)
  {}
#endif
}