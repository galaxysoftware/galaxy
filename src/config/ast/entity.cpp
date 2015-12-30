#include "config/ast/entity.h"

#include <yaml-cpp/yaml.h>

namespace gxy {
namespace ast {

entity::entity(std::string name, std::vector<component> components)
: name(std::move(name)),
  components(std::move(components))
{
}

auto entity::operator==(const entity &o) const -> bool
{
  return name == o.name
    && components == o.components;
}

auto entity::operator!=(const entity &o) const -> bool
{
  return ! (*this == o);
}

} // namespace ast

template <>
auto parse<ast::entity>(const YAML::Node &node) -> ast::entity
{
  assert(node.IsMap());

  return { node["name"].as<std::string>(), parse<std::vector<ast::component>>(node["components"]) };
}

} // namespace gxy

