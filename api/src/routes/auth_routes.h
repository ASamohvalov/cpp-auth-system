#ifndef AUTH_ROUTES_H
#define AUTH_ROUTES_H

#include "middleware/auth_middleware.h"
#include <crow/app.h>

namespace routes 
{
  void init_auth_routes(crow::App<middleware::Auth>& app);
}

#endif