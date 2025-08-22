#ifndef JSON_CONFIG_H
#define JSON_CONFIG_H

#include <optional>
#include <string>
#include <vector>

namespace config
{
  // result is empty if route is not found in route_access.json
  std::optional<std::vector<std::string>> get_route_json(const std::string& key);
}

#endif