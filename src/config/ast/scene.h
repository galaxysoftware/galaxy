#ifndef CONFIG_AST_SCENE_H
#define CONFIG_AST_SCENE_H

#include "config/ast/entity.h"

#include "config/parse.h"

#include <vector>

namespace gxy {
namespace ast {

// A scene is just a collection of entities.
using scene = std::vector<entity>;

} // namespace ast

// Transform an entity into an AST node.
template <>
auto parse<ast::scene>(const YAML::Node &) -> ast::scene;

} // namespace gxy

#endif // CONFIG_AST_SCENE_H

