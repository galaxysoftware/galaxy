#ifndef COMPONENTS_UTILS_FOR_EACH_H
#define COMPONENTS_UTILS_FOR_EACH_H

#include "components/list.h"

#include "utils/box.h"

namespace gxy::components {

template <typename Fn>
auto for_each(Fn &&) -> void;

// Definition.

namespace detail {

template <typename Fn, typename... Components>
inline
auto for_each_impl(Fn &&fn, meta::typelist<Components...>) -> void
{
  // magic.
  [](...) {}((std::forward<Fn>(fn)(box<Components>{}), 0)...);
}

} // namespace detail

template <typename Fn>
inline
auto for_each(Fn &&fn) -> void
{
  detail::for_each_impl<Fn>(std::forward<Fn>(fn), list{});
}

} // namespace gxy::components

#endif // COMPONENTS_UTILS_FOR_EACH_H

