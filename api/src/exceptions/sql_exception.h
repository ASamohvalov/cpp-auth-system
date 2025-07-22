#ifndef AUTH_SYSTEM_SQL_EXCEPTION_H
#define AUTH_SYSTEM_SQL_EXCEPTION_H

#include <stdexcept>

namespace exception 
{
  struct SqlException : std::runtime_error 
  {
    SqlException(const std::string&);
  };
}

#endif