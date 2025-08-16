#include "migrations.h"
#include "db_connection.h"
#include <crow/logging.h>
#include <fstream>
#include <stdexcept>
#include <string>

namespace util::migrations
{
  namespace 
  {
    std::string get_migration_sql()
    {
      std::ifstream file("../db/migrations.sql");
      if (!file) {
        throw std::runtime_error("error open file - db/migrations.sql");
      } 
      std::string file_content((std::istreambuf_iterator<char>(file)),
          std::istreambuf_iterator<char>());
      return file_content;
    }
  }

  void migrate()
  {
    constexpr int number_of_tables = 3;

    db::Connection connection;
    int count = connection.get_count(
        "SELECT COUNT(*) FROM sqlite_schema " 
        "WHERE type = 'table' AND name NOT LIKE 'sqlite_%'"
    );
    if (count != number_of_tables) {
      std::string sql = get_migration_sql();
      connection.multi_execute(sql);
      CROW_LOG_DEBUG << "migrations done";
    }
  }
}