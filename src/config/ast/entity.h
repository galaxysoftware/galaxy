#ifndef CONFIG_AST_ENTITY_H
#define CONFIG_AST_ENTITY_H

#include "config/ast/component.h"

#include "config/parse.h"

#include <string>
#include <vector>

namespace gxy {
namespace ast {

// A representation of an entity in the AST. Basically consists of a name and some components.
class entity
{
public:
  entity(std::string name, std::vector<component> components);

  auto operator==(const entity &o) const -> bool;
  auto operator!=(const entity &o) const -> bool;

  std::string name;
  std::vector<component> components;
};

} // namespace ast

// Transform a component into an AST node.
template <>
auto parse<ast::entity>(const YAML::Node &) -> ast::entity;

} // namespace gxy

#endif // CONFIG_AST_ENTITY_H

