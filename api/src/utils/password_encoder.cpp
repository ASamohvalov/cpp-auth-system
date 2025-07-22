#include "password_encoder.h"
#include <sodium/core.h>
#include <sodium/crypto_pwhash.h>
#include <stdexcept>

namespace util::password_hash
{
  std::string get_hash(const std::string& password)
  {
    if (sodium_init() < 0) {
      throw std::runtime_error("error to init sodium");
    }

    char hashed[crypto_pwhash_STRBYTES];
    if (crypto_pwhash_str
        (hashed, password.c_str(), password.length(),
        crypto_pwhash_OPSLIMIT_MIN, crypto_pwhash_MEMLIMIT_MIN) != 0) {
      throw std::runtime_error("out of memory error");
    }

    return hashed;
  }

  bool verify(const std::string& hashed_password, const std::string& password)
  {
    return crypto_pwhash_str_verify(
        hashed_password.c_str(), password.c_str(), password.length()) == 0;
  }
}