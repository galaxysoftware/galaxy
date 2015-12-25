#ifndef UTILS_BOX_H
#define UTILS_BOX_H

namespace gxy {

// Generic wrapper around a type.
template <typename T>
struct box
{
  using type = T;
};

} // namespace gxy

#endif // UTILS_BOX_H
