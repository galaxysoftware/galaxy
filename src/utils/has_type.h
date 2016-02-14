#ifndef UTILS_HAS_TYPE_H
#define UTILS_HAS_TYPE_H

#include <type_traits>

namespace gxy {

template <typename T, typename = void>
struct has_type : public std::false_type{};

template <typename T>
struct has_type<T, std::void_t<typename T::type>> : public std::true_type{};

} // namespace gxy

#endif // UTILS_HAS_TYPE_H

