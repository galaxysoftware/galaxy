#ifndef UTILS_THROW_IF_H
#define UTILS_THROW_IF_H

namespace gxy {

template <typename E>
auto throw_if(bool pred) -> void
{
  if (pred) {
    throw E();
  }
}

} // namespace gxy

#endif // UTILS_THROW_IF_H

