#include "env_config.h"
#include "dotenv.h"

namespace config 
{
  static const dotenv env("../.env");

  std::string get_env(const std::string& key)
  {
    return env.get(key);
  }
  
  int get_int_env(const std::string& key)
  {
    return std::stoi(env.get(key));
  }
}