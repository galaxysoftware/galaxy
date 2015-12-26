#ifndef LOAD_AST_ENTITY_H
#define LOAD_AST_ENTITY_H

#include "load/ast/component.h"

#include "load/parse.h"

#include <string>
#include <vector>

namespace gxy {
namespace ast {

// A representation of an entity in the AST. Basically consists of a name and some components.
class entity
{
public:
  entity(std::string name, std::vector<component> components);

  std::string name;
  std::vector<component> components;
};

} // namespace ast

// Transform a component into an AST node.
template <>
auto parse<ast::entity>(const YAML::Node &) -> ast::entity;

} // namespace gxy

#endif // LOAD_AST_ENTITY_H

