#include "role_repo.h"
#include "db/db_connection.h"

#include <string>
#include <vector>

namespace repositories::role
{
  long save_if_exists(const std::string& role_name)
  {
    db::Connection connection;

    std::string check_sql = "SELECT id FROM roles WHERE role = ?";
    std::vector<std::string> res = 
        connection.get_single(check_sql, { role_name });
    if (!res.empty()) {
      long id = std::stol(res[0]);
      return id;
    }

    std::string insert_sql = "INSERT INTO roles (role) VALUES (?)";
    std::string get_id_sql = "SELECT last_insert_rowid()";

    connection.execute(insert_sql, { role_name });
    return std::stol(connection.get_single(get_id_sql)[0]);
  }
}