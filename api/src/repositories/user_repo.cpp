#include "user_repo.h"
#include "db/db_connection.h"
#include "dto/role_dto.h"
#include "dto/user_dto.h"

#include <crow/logging.h>
#include <sqlite3.h>
#include <string>
#include <unordered_map>
#include <utility>

namespace repositories::user
{
  namespace 
  {
    dto::UserModel map_to_model(
        const std::unordered_map<std::string, std::string>& map)
    {
      dto::UserModel model = {
        std::stol(map.at("id")),
        map.at("username"),
        map.at("password"),
        map.at("first_name"),
        map.at("last_name"),
        dto::RoleModel { std::stol(map.at("role_id")), map.at("role") }
      };
      return model;     
    }
  }

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

  void update(const dto::UserModel& user)
  {
    CROW_LOG_DEBUG << user.role.id;
    db::Connection conn;
    std::string sql = 
        "UPDATE users "
        "SET password = ?, first_name = ?, last_name = ?, role_id = ? "
        "WHERE id = ?";
    conn.execute(sql, {
      user.password,
      user.first_name,
      user.last_name,
      std::to_string(user.role.id),
      std::to_string(user.id)
    });
  }

  dto::UserModel get_by_id(long id)
  {
    db::Connection conn;
    std::string sql = "SELECT * FROM users "
                      "JOIN roles ON roles.id = role_id "
                      "WHERE users.id = ?";
    std::unordered_map<std::string, std::string> res = 
        conn.get_single_map(sql, { std::to_string(id) });
    if (res.empty()) {
      return dto::UserModel();
    }
    return map_to_model(res);
  }

  dto::UserModel get_by_username(const std::string& username)
  {
    db::Connection conn;
    std::string sql = "SELECT * FROM users "
                      "JOIN roles ON users.role_id = roles.id "
                      "WHERE username = ?";
    std::unordered_map<std::string, std::string> res = 
        conn.get_single_map(sql, { username });
    if (res.empty()) {
      return dto::UserModel();
    }
    return map_to_model(res);
  }

  bool exists_by_username(const std::string& username)
  {
    db::Connection conn;
    std::string sql = "SELECT COUNT(*) FROM users WHERE username = ?";
    return conn.get_count(sql, { username });
  }

  std::vector<dto::UserDataResponse> get_all()
  {
    db::Connection conn;
    std::string sql = "SELECT * FROM users "
                      "JOIN roles ON role_id = roles.id";
    auto res = conn.get_vector_map(sql);
    std::vector<dto::UserDataResponse> response;
    for (size_t i = 0; i < res.size(); ++i) {
      response.push_back(dto::UserDataResponse {
        std::stol(res[i]["id"]),
        std::move(res[i]["username"]),
        std::move(res[i]["first_name"]),
        std::move(res[i]["last_name"]),
        std::move(res[i]["role"])
      });
    }
    return response;
  }
}