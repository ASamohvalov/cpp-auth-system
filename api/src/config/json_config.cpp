#include "json_config.h"

#include <crow/json.h>
#include <crow/logging.h>
#include <fstream>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>

namespace config
{
  namespace
  {
    const crow::json::rvalue& get_instance() 
    {
      static const crow::json::rvalue json = [] {
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
  
    std::vector<std::string> get_values_from_key(const crow::json::rvalue& json,
        const std::string& key)
    {
      std::vector<std::string> res;
      for (const auto& item : json[key]) {
        if (item.t() != crow::json::type::String) {
          throw std::runtime_error("wrong type inner list");
        }
        res.push_back(item.s());
      }
      return res;
    }
  }
  
  std::optional<std::vector<std::string>> get_route_json(const std::string& url)
  {
    const crow::json::rvalue& json = get_instance();
    if (json.has(url) && json[url].t() == crow::json::type::List) {
      return get_values_from_key(json, url);
    }

    std::vector<std::string> keys = json.keys();
    for (size_t i = 0; i < keys.size(); ++i) {
      size_t idx = keys[i].find('*');
      if (idx != std::string::npos && 
          url.rfind(keys[i].substr(0, idx), 0) == 0) {
        return get_values_from_key(json, keys[i]);
      }
    }

    CROW_LOG_WARNING << "this url - " + url + " not found in route_access.json";
    return std::nullopt;
  }
}