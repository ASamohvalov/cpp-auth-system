#ifndef AUTH_ERROR_H
#define AUTH_ERROR_H

#include <crow/http_response.h>
#include <string>

namespace error
{
  // the function enters an error message and terminates the response
  void bad_request(crow::response& res, const std::string& msg);
}

#endif