#ifndef COMPONENT_EMPTY_DATA_H
#define COMPONENT_EMPTY_DATA_H

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
} // namespace gxy

#endif // COMPONENT_EMPTY_DATA_H

