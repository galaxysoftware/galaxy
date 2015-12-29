#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "components/list.h"

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

  // The components current state and a placeholder for calculating it's next state.
  data_type &current;
  data_type &next;

  const const_data_type &const_data;
};

// A component can be any of our defined components.
using component = meta::apply_t<eggs::variant,
  meta::transform_t<components::list, component_facade>>;

} // namespace gxy

#endif // GAME_COMPONENT_H

