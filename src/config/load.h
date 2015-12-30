#ifndef CONFIG_LOAD_H
#define CONFIG_LOAD_H

#include "ast/scene.h"

#include <boost/filesystem/path.hpp>

#include <vector>

namespace gxy {

// Takes a config file on disk, loads and parses it into an abstract syntax tree.
auto load(const boost::filesystem::path &config) -> ast::scene;

} // namespace gxy

#endif // CONFIG_LOAD_H

