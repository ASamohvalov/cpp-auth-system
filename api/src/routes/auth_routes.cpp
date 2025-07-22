#include "auth_routes.h"
#include "controllers/auth_controller.h"
#include "middleware/auth_middleware.h"

namespace routes
{
  void init_auth_routes(crow::App<middleware::Auth>& app)
  {
    CROW_ROUTE(app, "/sign_in")
    .methods("POST"_method)
    ([](const crow::request& req, crow::response& res)
    {
      controllers::auth::sign_in(req, res);
    });
    
    CROW_ROUTE(app, "/sign_up")
    .methods("POST"_method)
    ([](const crow::request& req, crow::response& res)
    {
      controllers::auth::sign_up(req, res);
    });
  }
}