#include "json_config.h"
#include <crow/json.h>
#include <crow/logging.h>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace config
{
  static crow::json::rvalue& get_instance() 
  {
    static crow::json::rvalue json = [] {
      std::ifstream file("../route_access.json");
      if (!file) {
        throw std::runtime_error("error open file - route_access.json");
      }
      std::stringstream buffer;
      buffer << file.rdbuf();

      crow::json::rvalue parsed = crow::json::load(buffer.str());
      if (!parsed) {
        throw std::runtime_error("error parse json file");
      }
      return parsed;
    }();
    return json;
  }
  
  std::vector<std::string> get_route_json(const std::string& key)
  {
    auto json = get_instance();
    if (json.has(key) && json[key].t() == crow::json::type::List) {
      std::vector<std::string> res;
      for (const auto& item : json[key]) {
        if (item.t() != crow::json::type::String) {
          throw std::runtime_error("wrong type inner list");
        }
        res.push_back(item.s());
      }
      return res;
    }
    throw std::runtime_error("error get value from json with key " + key);
  }
}