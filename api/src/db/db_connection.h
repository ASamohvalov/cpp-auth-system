#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <initializer_list>
#include <sqlite3.h>

#include <string>
#include <unordered_map>
#include <vector>

namespace db 
{
  class Connection
  {
  public:
    Connection();
    
    // sql example = "SELECT column FROM entity"
    std::string get_one(const std::string& sql, 
        std::initializer_list<const std::string> params = {}) const;

    // sql example = "SELECT COUNT(*) FROM entity"
    int get_count(const std::string& sql, 
        std::initializer_list<const std::string> params = {}) const;

    // sql example = "SELECT * FROM entity WHERE id = 1"
    std::vector<std::string> get_single(const std::string& sql,
        std::initializer_list<const std::string> params = {}) const;

    // duplicate column names are ignored
    std::unordered_map<std::string, std::string> get_single_map(
        const std::string& sql,
        std::initializer_list<const std::string> params = {}) const;

    // sql example = "SELECT * FROM entity"
    // return result in table view
    // {{'column_name_1', 'column_name_2', 'column_name_3'},
    // { 'value_1',       'value_2',       'value_3'      }
    // { 'value_1',       'value_2',       'value_3'      }}
    std::vector<std::vector<std::string>> get(const std::string& sql,
        std::initializer_list<const std::string> params = {}) const;

    // sql example = "INSERT INTO entity VALUES (?, ?, ?)"
    // all queries that do not return a value
    // params must by std::string
    // execute only one query
    void execute(const std::string& sql,
        std::initializer_list<const std::string> params = {}) const;
    
    // sql example = "INSERT INTO entity VALUES (?, ?, ?); 
    //                INSERT INTO entity2 VALUES (?, ?, ?)"
    // multi query execution
    // work without params
    void multi_execute(const std::string& sql) const;

  private:
    static sqlite3* db;
  };
}

#endif