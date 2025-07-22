#include "config/env_config.h"
#include "middleware/auth_middleware.h"
#include "routes/auth_routes.h"
#include <crow/app.h>

int main() 
{
  crow::App<middleware::Auth> app; 

  crow::logger::setLogLevel(crow::LogLevel::Debug);

  routes::init_auth_routes(app);

  app.port(config::get_int_env("PORT"))
      .multithreaded()
      .run();

  return 0;
}