#ifndef COMPONENT_UTILS_EMPTY_DATA_H
#define COMPONENT_UTILS_EMPTY_DATA_H

#include "config/parse.h"

namespace gxy {
namespace components {

// A memberless data object that contains no fields. Used as a typedef for components
// that have no state.
struct empty_data{};

auto operator==(const empty_data &, const empty_data &) -> bool;
auto operator!=(const empty_data &, const empty_data &) -> bool;

// Definitions.

inline
auto operator==(const empty_data &, const empty_data &) -> bool
{
  return true;
}

inline
auto operator!=(const empty_data &, const empty_data &) -> bool
{
  return false;
}

} // namespace components

// Transform a YAML node into component empty data.
template <>
auto parse<components::empty_data>(const YAML::Node &)
  -> components::empty_data;

} // namespace gxy

#endif // COMPONENT_UTILS_EMPTY_DATA_H

