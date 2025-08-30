#ifndef APP_H
#define APP_H

#include "middleware/access_middleware.h"
#include "middleware/auth_middleware.h"

#include <crow/app.h>

using Application = crow::App<middleware::Auth, middleware::Access>;

#endif