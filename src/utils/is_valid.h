#ifndef UTILS_IS_VALID_H
#define UTILS_IS_VALID_H

#include <type_traits>
#include <utility>

// Inspired by Boost.Hana.

namespace detail {

template <typename F, typename... Args,
  typename = decltype(std::declval<F&&>()(std::declval<Args&&>()...))>
auto is_valid_impl(int) -> std::true_type;

template <typename F, typename... Args>
auto is_valid_impl(...) -> std::false_type;

template <typename F>
struct is_valid_fun
{
  template <typename ...Args>
  constexpr auto operator()(Args&& ...) const -> decltype(is_valid_impl<F, Args&&...>(int{}))
  {
    return {};
  }
};

} // namespace detail

template <typename F>
constexpr auto is_valid(F&&) -> detail::is_valid_fun<F&&>
{
  return {};
}

#endif // UTILS_IS_VALID_H

