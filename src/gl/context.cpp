#include "gl/context.h"

#include <cassert>

namespace gxy::gl {

context::context(environment &, const int width, const int height, const char *title)
: window_(::glfwCreateWindow(width, height, title, nullptr, nullptr), ::glfwDestroyWindow)
{
  assert(window_ != nullptr);
  ::glfwMakeContextCurrent(window_.get());
}

auto context::run_one() -> bool
{
  if (::glfwWindowShouldClose(window_.get())) {
    return false;
  }

  ::glfwSwapBuffers(window_.get());
  ::glfwPollEvents();
  return true;
}

} // namespace gxy::gl

