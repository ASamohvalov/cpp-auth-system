#ifndef AUTH_ROUTES_H
#define AUTH_ROUTES_H

#include "middleware/access_middleware.h"
#include "middleware/auth_middleware.h"
#include <crow/app.h>

namespace routes 
{
  void init(crow::App<middleware::Auth, middleware::Access>& app);
}

#endif