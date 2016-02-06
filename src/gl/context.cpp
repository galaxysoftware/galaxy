#include "gl/context.h"

#include <cassert>

namespace gxy::gl {

namespace {

auto make_window(const int width, const int height, const char *title) -> GLFWwindow *
{
  ::glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  ::glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  ::glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  ::glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  auto *window(::glfwCreateWindow(width, height, title, nullptr, nullptr));

  ::glfwDefaultWindowHints();
  return window;
}

} // unnamed namespace

context::context(environment &, const int width, const int height, const char *title)
: window_(make_window(width, height, title), ::glfwDestroyWindow)
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

