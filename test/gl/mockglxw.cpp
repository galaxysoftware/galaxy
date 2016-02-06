#include "gl/mockglxw.h"

namespace gxy::gl {

mockglxw *mockglxw::instance = nullptr;

} // namespace gl::gxy

using gxy::gl::mockglxw;

auto glxwInit() -> int
{
  return mockglxw::instance->Init();
}

