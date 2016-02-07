#include "gl/mockglxw.h"

namespace gxy::gl {

mockglxw *mockglxw::instance = nullptr;

} // namespace gl::gxy

#ifdef __cplusplus
extern "C" {
#endif

using gxy::gl::mockglxw;

auto glxwInit() -> int
{
  return mockglxw::instance->Init();
}

#ifdef __cplusplus
} // extern "C"
#endif

