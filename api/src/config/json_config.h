#ifndef JSON_CONFIG_H
#define JSON_CONFIG_H

#include <string>
#include <vector>

namespace config
{
  std::vector<std::string> get_route_json(const std::string& key);
}

#endif