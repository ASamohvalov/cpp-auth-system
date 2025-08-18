#include "routes.h"
#include "controllers/admin_controller.h"
#include "controllers/auth_controller.h"
#include "controllers/user_controller.h"
#include "middleware/access_middleware.h"
#include "middleware/auth_middleware.h"

#include <crow/app.h>
#include <crow/http_request.h>
#include <crow/http_response.h>

namespace routes
{
  void init(crow::App<middleware::Auth, middleware::Access>& app)
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
  
    CROW_ROUTE(app, "/account")
    .methods("GET"_method)
    ([&](const crow::request& req, crow::response& res)
    {
      controllers::user::account_info(app, req, res);
    });

    CROW_ROUTE(app, "/users_info")
    .methods("GET"_method)
    ([](const crow::request& req, crow::response& res)
    {
      controllers::admin::users_info(req, res);
    });

#if 0
    CROW_ROUTE(app, "/give_admin_role")
    .methods("GET"_method)
    ([](const crow::request& req, crow::response& res)
    {
      controllers::admin::give_admin_role(req, res);
    });

    CROW_ROUTE(app, "/swagger.json")
    .methods("GET"_method)
    ([]()
    {
      return controllers::swagger::load_file();
    });
#endif
  }
}