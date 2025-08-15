#include "db_connection.h"
#include "config/env_config.h"
#include "exceptions/sql_exception.h"

#include <crow/logging.h>
#include <sqlite3.h>
#include <vector>

namespace db
{
  sqlite3* Connection::db = nullptr;
  
  Connection::Connection()
  {
    if (db == nullptr) {
      sqlite3_open(config::get_env("DB_FILE_PATH").c_str(), &db);
      CROW_LOG_DEBUG << "make db connection with file - " + 
          config::get_env("DB_FILE_PATH");
    }
  }

  int Connection::get_count(const std::string& sql, 
        std::initializer_list<const std::string> params) const
  {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr)) {
      throw exception::SqlException("error prepare sql");
    }
    
    int index = 1;
    for (const std::string& param : params) {
      sqlite3_bind_text(
          stmt, index++, param.c_str(), param.length(), SQLITE_TRANSIENT);
    }

    int count = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
      count = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return count;
  }

  std::vector<std::string> Connection::get_single(const std::string& sql,
      std::initializer_list<const std::string> params) const
  {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr)) {
      throw exception::SqlException("error prepare sql");
    }
    
    int index = 1;
    for (const std::string& param : params) {
      sqlite3_bind_text(
          stmt, index++, param.c_str(), param.length(), SQLITE_TRANSIENT);
    }

    std::vector<std::string> res {};
    if (sqlite3_step(stmt) == SQLITE_ROW) {
      int column_count = sqlite3_column_count(stmt);
      for (int i = 0; i < column_count; ++i) {
        const unsigned char* text = sqlite3_column_text(stmt, i);
        // if text is NULL => "NULL"
        res.push_back(text ? reinterpret_cast<const char*>(text) : "NULL");
      }
    }

    sqlite3_finalize(stmt);
    return res;
  }
  
  std::vector<std::vector<std::string>> Connection::get(const std::string& sql,
      std::initializer_list<const std::string> params) const
  {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr)) {
      throw exception::SqlException("error prepare sql");
    }
    
    int index = 1;
    for (const std::string& param : params) {
      sqlite3_bind_text(
          stmt, index++, param.c_str(), param.length(), SQLITE_TRANSIENT);
    }

    std::vector<std::string> column_names {};
    for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
      column_names.push_back(sqlite3_column_name(stmt, i));
    }

    std::vector<std::vector<std::string>> res {};
    res.push_back(column_names);

    while(sqlite3_step(stmt) == SQLITE_ROW) {
      int column_count = sqlite3_column_count(stmt);
      std::vector<std::string> column;
      for (int i = 0; i < column_count; ++i) {
        const unsigned char* text = sqlite3_column_text(stmt, i);
        // if text is NULL => "NULL"
        column.push_back(text ? reinterpret_cast<const char*>(text) : "NULL");
      }
      res.push_back(column);
    }

    sqlite3_finalize(stmt);
    return res;
  }

  void Connection::execute(const std::string& sql,
      std::initializer_list<const std::string> params) const
  {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr)) {
      throw exception::SqlException("error prepare sql");
    }
    
    int index = 1;
    for (const std::string& param : params) {
      sqlite3_bind_text(
          stmt, index++, param.c_str(), param.length(), SQLITE_TRANSIENT);
    }

    if (sqlite3_step(stmt) != SQLITE_DONE) {
      sqlite3_finalize(stmt);
      throw exception::SqlException("sql execution failed");
    }

    sqlite3_finalize(stmt);
  }

  void Connection::multi_execute(const std::string& sql) const
  {
    char* errmsg;
    if (sqlite3_exec(db, sql.c_str(), 0, 0, &errmsg)) {
      throw exception::SqlException("error prepare sql, message - " + 
          std::string(errmsg));
    }
  }
}