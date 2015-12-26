#include "load/ast/entity.h"

#include <yaml-cpp/yaml.h>
#include <iostream>
namespace gxy {
namespace ast {

entity::entity(std::string name, std::vector<component> components)
: name(std::move(name)),
  components(std::move(components))
{
}

} // namespace ast

template <>
auto parse<ast::entity>(const YAML::Node &node) -> ast::entity
{
  assert(node.IsMap());

  return { node["name"].as<std::string>(), parse<std::vector<ast::component>>(node["components"]) };
}

} // namespace gxy

