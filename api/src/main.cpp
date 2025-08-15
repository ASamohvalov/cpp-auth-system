#include "config/env_config.h"
#include "middleware/access_middleware.h"
#include "middleware/auth_middleware.h"
#include "routes/routes.h"
#include "utils/admin_initializer.h"
#include "db/migrations.h"
#include "utils/role_initializer.h"
#include <crow/app.h>

int main() 
{
  crow::App<middleware::Auth, middleware::Access> app; 

  crow::logger::setLogLevel(crow::LogLevel::Debug);

  util::migrations::migrate();
  util::initializer::init_roles();
  util::initializer::init_default_admin();
  routes::init(app);

  app.port(config::get_int_env("PORT"))
      .multithreaded()
      .run();

  return 0;
}