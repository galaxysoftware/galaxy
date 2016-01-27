#include "config/ast/component.h"

#include "component/utils/for_each.h"

#include <yaml-cpp/yaml.h>

namespace gxy {

namespace {

template <typename T>
auto parse_facade(const YAML::Node &node) -> ast::component_facade<T>
{
  using data_type = typename std::decay_t<T>::data;
  using const_data_type = typename std::decay_t<T>::const_data;

  return { parse<data_type>(node["data"]), parse<const_data_type>(node["const_data"]) };
}

} // unnamed namespace

template <>
auto parse<std::vector<ast::component>>(const YAML::Node &nodes)
  -> std::vector<ast::component>
{
  assert(nodes.IsMap());

  std::vector<ast::component> components;

  for (const auto &node : nodes) {
    // TODO: make Boost.Hana map that contains name -> component.
    //  use map to dispatch to correct parse_facade() call.
    components::for_each([&](auto c) {
      using component_type = typename decltype(c)::type;

      if (components::name<component_type> == node.first.as<std::string>()) {
        components.push_back(parse_facade<component_type>(node.second));
      }
    });
  }

  return components;
}

} // namespace gxy

