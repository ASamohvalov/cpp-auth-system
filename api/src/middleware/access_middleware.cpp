#include "access_middleware.h"
#include <crow/logging.h>

namespace middleware
{
  void Access::after_handle(crow::request& req, crow::response& res, context& ctx)
  {}
}