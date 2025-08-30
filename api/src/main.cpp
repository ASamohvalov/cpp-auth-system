#include "config/env_config.h"
#include "routes/routes.h"
#include "utils/admin_initializer.h"
#include "db/migrations.h"
#include "utils/app.h"
#include "utils/role_initializer.h"

#include <crow/app.h>
#include <crow/logging.h>

int main() 
{
  Application app; 

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