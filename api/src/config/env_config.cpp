#include "env_config.h"
#include "dotenv.h"

namespace config 
{
  const dotenv& get_instance()
  {
    static const dotenv env("../.env");
    return env;
  }

  std::string get_env(const std::string& key)
  {
    return get_instance().get(key);
  }
  
  int get_int_env(const std::string& key)
  {
    return std::stoi(get_instance().get(key));
  }
}