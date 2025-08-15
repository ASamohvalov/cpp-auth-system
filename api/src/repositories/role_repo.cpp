#include "role_repo.h"
#include "db/db_connection.h"

#include <string>

namespace repositories::role
{
  long save(const std::string& role_name)
  {
    db::Connection connection;
    std::string sql = "INSERT INTO roles (role) VALUES (?)";
    std::string sql2 = "SELECT last_insert_rowid()";
    connection.execute(sql, { role_name });
    return std::atol(connection.get_single(sql2)[0].c_str());
  }
}