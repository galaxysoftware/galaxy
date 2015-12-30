#ifndef CONFIG_AST_COMPONENT_H
#define CONFIG_AST_COMPONENT_H

#include "components/list.h"

#include "config/parse.h"

#include "utils/meta/apply.h"
#include "utils/meta/transform.h"

#include <eggs/variant.hpp>

#include <vector>

namespace gxy {
namespace ast {

// A representation of a component in an initial state. Useful for building up a scene tree
// in an AST as stated by a configuration.
template <typename T>
class component_facade
{
public:
  using type = T;
  using data_type = typename type::data;
  using const_data_type = typename type::const_data;

  component_facade(data_type data, const_data_type const_data);

  auto operator==(const component_facade &o) const -> bool;
  auto operator!=(const component_facade &o) const -> bool;

  data_type data;
  const_data_type const_data;
};

// An ast::component can be any of our defined components.
using component = meta::apply_t<eggs::variant,
  meta::transform_t<components::list, component_facade>>;

// Definitions.

template <typename T>
component_facade<T>::component_facade(data_type data, const_data_type const_data)
: data(std::move(data)),
  const_data(std::move(const_data))
{
}

template <typename T>
auto component_facade<T>::operator==(const component_facade<T> &o) const -> bool
{
  return data == o.data
    && const_data == o.const_data;
}

template <typename T>
auto component_facade<T>::operator!=(const component_facade<T> &o) const -> bool
{
  return ! (*this == o);
}

} // namespace ast

// Transform a component into an AST node.
template <>
auto parse<std::vector<ast::component>>(const YAML::Node &) -> std::vector<ast::component>;

} // namespace gxy

#endif // CONFIG_AST_COMPONENT_H

