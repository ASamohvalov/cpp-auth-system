#ifndef ENV_CONFIG_H
#define ENV_CONFIG_H

#include <string>

namespace config 
{
  std::string get_env(const std::string& key);
  int get_int_env(const std::string& key);
}

#endif