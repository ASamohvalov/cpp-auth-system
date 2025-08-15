#ifndef ROLE_REPO_H
#define ROLE_REPO_H

#include <string>

namespace repositories::role
{
  // multithread unsave
  // return id
  long save(const std::string& role_name);
}

#endif