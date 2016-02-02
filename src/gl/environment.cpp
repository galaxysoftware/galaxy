#include "gl/environment.h"

#include "gl/glfw_error.h"

#include <GLFW/glfw3.h>

namespace gxy::gl {

environment::environment()
{
  if (! ::glfwInit()) {
    throw glfw_error{"Unable to initialise GLFW."};
  }

  const auto previous(::glfwSetErrorCallback([](int error, const char *what) {
    throw glfw_error{static_cast<glfw_error::code>(error), what};
  }));

  // We don't support overloading an existing callback.
  assert(previous == nullptr);
}

environment::~environment()
{
  ::glfwSetErrorCallback(nullptr);
  ::glfwTerminate();
}

} // namespace gxy::gl

