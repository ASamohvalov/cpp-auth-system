#include "user_repo.h"
#include "db/db_connection.h"
#include "dto/user_dto.h"

#include <crow/logging.h>
#include <sqlite3.h>
#include <string>

namespace repositories::user
{
  void save(dto::UserDto user)
  {
    db::Connection conn;
    std::string sql = 
        "INSERT INTO users (username, password, first_name, last_name) "
        "VALUES (?, ?, ?, ?)";
    conn.execute(sql, {
      user.username,
      user.password,
      user.first_name,
      user.last_name
    });
  }

  dto::UserModel get_by_username(const std::string& username)
  {
    db::Connection conn;
    std::string sql = "SELECT * FROM users WHERE username = ?";
    std::vector<std::string> res = conn.get_single(sql, {username});
    if (res.empty()) {
      return dto::UserModel();
    }
    dto::UserModel model = {
      std::stol(res[0]),
      res[1],
      res[2],
      res[3],
      res[4]
    };
    return model;
  }

  bool exists_by_username(const std::string& username)
  {
    db::Connection conn;
    std::string sql = "SELECT COUNT(*) FROM users WHERE username = ?";
    return conn.get_count(sql, {username});
  }
}