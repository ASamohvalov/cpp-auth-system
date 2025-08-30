#include "sql_exception.h"

#include <stdexcept>

namespace exception 
{
  SqlException::SqlException(const std::string& arg): runtime_error(arg) {}
}
