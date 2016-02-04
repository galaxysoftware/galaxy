#ifndef UTILS_RESOURCE_H
#define UTILS_RESOURCE_H

#include <memory>

namespace gxy {

template <typename T>
using resource = std::unique_ptr<T, void(*)(T *)>;

} // namespace gxy

#endif // UTILS_RESOURCE_H

