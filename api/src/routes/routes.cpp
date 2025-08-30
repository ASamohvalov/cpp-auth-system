#include "routes.h"
#include "controllers/admin_controller.h"
#include "controllers/auth_controller.h"
#include "controllers/user_controller.h"
#include "utils/app.h"

#include <crow/app.h>
#include <crow/http_request.h>
#include <crow/http_response.h>
#include <crow/logging.h>

namespace routes
{
  void init(Application& app)
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

    CROW_ROUTE(app, "/update_tokens")
    .methods("POST"_method)
    ([&](const crow::request& req, crow::response& res)
    {
      controllers::auth::update_tokens(app, req, res);
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

    CROW_ROUTE(app, "/give_admin_role/<int>")
    .methods("POST"_method)
    ([](const crow::request& req, crow::response& res, long user_id)
    {
      controllers::admin::give_admin_role(req, res, user_id);
    });
  }
}

