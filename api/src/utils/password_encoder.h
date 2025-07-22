#ifndef AUTH_PASSWORD_ENCODER_H
#define AUTH_PASSWORD_ENCODER_H

#include <sodium.h>
#include <string>

namespace util::password_hash
{
  std::string get_hash(const std::string& password);
  bool verify(const std::string& hashed_password, const std::string& password);
}

#endif