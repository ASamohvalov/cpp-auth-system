#include "error.h"

namespace error
{
  std::string json_message(const std::string& msg)
  {
    return "\"message\": \"" + msg + "\"";
  }

  void bad_request(crow::response& res, const std::string& msg)
  {
    res.code = 400;
    res.body = "\"message\": \"" + msg + "\"";
    res.end();
  }
}