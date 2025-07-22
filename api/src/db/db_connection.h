#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <initializer_list>
#include <sqlite3.h>

#include <string>
#include <vector>

namespace db 
{
  class Connection
  {
  public:
    Connection();
    
    // sql example = "SELECT COUNT(*) FROM entity"
    int get_count(const std::string& sql, 
        std::initializer_list<const std::string> params) const;

    // sql example = "SELECT * FROM entity WHERE id = 1"
    std::vector<std::string> get_single(const std::string& sql,
        std::initializer_list<const std::string> params) const;

    // sql example = "SELECT * FROM entity"
    // return result in table view
    // {{'column_name_1', 'column_name_2', 'column_name_3'},
    // { 'value_1',       'value_2',       'value_3'      }
    // { 'value_1',       'value_2',       'value_3'      }}
    std::vector<std::vector<std::string>> get(const std::string& sql,
        std::initializer_list<const std::string> params) const;

    // sql example = "INSERT INTO entity VALUER (?, ?, ?)"
    // all queries that do not return a value
    // params must by std::string
    void execute(const std::string& sql,
        std::initializer_list<const std::string> params) const;

#if 0
    // sql example = "INSERT INTO entity VALUES (?, ?, ?)"
    template<typename T>
    void execute(const std::string& sql,
        std::initializer_list<std::pair<T, void (sqlite3_stmt&)>> params) const;
#endif

  private:
    static sqlite3* db;
  };
}

#endif