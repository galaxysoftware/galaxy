#include "gl/mockglfw.h"

namespace gxy::gl {

mockglfw *mockglfw::instance = nullptr;

} // namespace gxy::gl

auto glfwInit() -> int
{
  return gxy::gl::mockglfw::instance->Init();
}

auto glfwSetErrorCallback(GLFWerrorfun fn) -> GLFWerrorfun
{
  return gxy::gl::mockglfw::instance->SetErrorCallback(std::move(fn));
}

auto glfwTerminate() -> void
{
  gxy::gl::mockglfw::instance->Terminate();
}

