#include "user_repo.h"
#include "db/db_connection.h"
#include "dto/role_dto.h"
#include "dto/user_dto.h"

#include <crow/logging.h>
#include <sqlite3.h>
#include <string>
#include <utility>

namespace repositories::user
{
  void save(const dto::UserDto& user)
  {
    db::Connection conn;
    std::string sql = 
        "INSERT INTO users (username, password, first_name, last_name, role_id) "
        "VALUES (?, ?, ?, ?, ?)";
    conn.execute(sql, {
      user.username,
      user.password,
      user.first_name,
      user.last_name,
      std::to_string(user.role.id)
    });
  }

  dto::UserModel get_by_id(long id)
  {
    db::Connection conn;
    std::string sql = "SELECT * FROM users WHERE id = ?";
    std::vector<std::string> res = conn.get_single(sql, {std::to_string(id)});
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

  dto::UserModel get_by_username(const std::string& username)
  {
    db::Connection conn;
    std::string sql = "SELECT * FROM users "
                      "JOIN roles ON users.role_id = roles.id "
                      "WHERE username = ?";
    std::vector<std::string> res = conn.get_single(sql, {username});
    if (res.empty()) {
      return dto::UserModel();
    }
    dto::UserModel model = {
      std::stol(res[0]),
      res[1],
      res[2],
      res[3],
      res[4],
      dto::RoleModel { std::stol(res[5]), res[6] }
    };
    return model;
  }

  bool exists_by_username(const std::string& username)
  {
    db::Connection conn;
    std::string sql = "SELECT COUNT(*) FROM users WHERE username = ?";
    return conn.get_count(sql, {username});
  }

  std::vector<dto::UserDataResponse> get_all()
  {
    db::Connection conn;
    std::string sql = "SELECT * FROM users";
    std::vector<std::vector<std::string>> res = conn.get(sql);
    std::vector<dto::UserDataResponse> response;
    for (size_t i = 1; i < res.size(); ++i) {
      response.push_back(dto::UserDataResponse {
        std::move(res[i][1]),
        std::move(res[i][3]),
        std::move(res[i][4]),
        std::move(res[i][5]),
      });
    }
    return response;
  }
}