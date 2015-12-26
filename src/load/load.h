#ifndef LOAD_H
#define LOAD_H

#include "ast/entity.h"

#include <boost/filesystem/path.hpp>

#include <vector>

namespace gxy {

// Takes a config file on disk, loads and parses it into an abstract syntax tree.
auto load(const boost::filesystem::path &config)
  -> std::vector<ast::entity>;

} // namespace gxy

#endif // LOAD_H

