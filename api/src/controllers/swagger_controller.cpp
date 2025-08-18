#include "swagger_controller.h"

#include "config/env_config.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace controllers::swagger
{
  crow::response load_file()
  {
    std::ifstream file(config::get_env("SWAGGER_DOCS_FILEPATH"));
    if (!file) {
      throw std::runtime_error("open swagger file error");
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return crow::response(buffer.str());
  }
}
