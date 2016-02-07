#include "gl/environment.h"

#include "gl/glfw_error.h"

namespace gxy::gl {

environment::environment()
{
  if (::glfwInit() != GL_TRUE) {
    throw std::runtime_error{"Unable to initialise GLFW."};
  }

#if BOOST_OS_LINUX
  if (::glxwInit() != 0) {
    throw std::runtime_error{"Unable to initialise GLXW."};
  }
#endif

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

