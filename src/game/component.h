#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "component/list.h"

#include "config/ast/component.h"

#include "utils/meta/apply.h"
#include "utils/meta/transform.h"

#include <eggs/variant.hpp>

namespace gxy {

// An active component in the ECS.
template <typename T>
class component_facade
{
public:
  using data_type = typename T::data;
  using const_data_type = typename T::const_data;

  // Create a component from it's data.
  component_facade(data_type data, const_data_type const_data);

  auto operator==(const component_facade &o) const -> bool;
  auto operator!=(const component_facade &o) const -> bool;

  // The components current state and a placeholder for calculating it's next state.
  data_type current;
  data_type next;

  const_data_type const_data;
};

// A component can be any of our defined components.
using component = meta::apply_t<eggs::variant,
  meta::transform_t<components::list, component_facade>>;

// Create a component from it's AST representation.
auto make_component(const ast::component &) -> component;

// Definitions.

template <typename T>
component_facade<T>::component_facade(data_type data, const_data_type const_data)
: current(data),
  next(data),
  const_data(const_data)
{
}

template <typename T>
auto component_facade<T>::operator==(const component_facade &o) const -> bool
{
  return current == o.current
    && next == o.next
    && const_data == o.const_data;
}

template <typename T>
auto component_facade<T>::operator!=(const component_facade &o) const -> bool
{
  return ! (*this == o);
}

} // namespace gxy

#endif // GAME_COMPONENT_H

