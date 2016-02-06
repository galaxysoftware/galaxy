#include "gl/mockglfw.h"

namespace gxy::gl {

mockglfw *mockglfw::instance = nullptr;

} // namespace gxy::gl

using gxy::gl::mockglfw;

auto glfwCreateWindow(const int width, const int height, const char *title, GLFWmonitor *monitor, GLFWwindow *window)
  -> ::GLFWwindow *
{
  return mockglfw::instance->CreateWindow(width, height, title, monitor, window);
}

auto glfwDefaultWindowHints() -> void
{
  mockglfw::instance->DefaultWindowHints();
}

auto glfwDestroyWindow(::GLFWwindow *window) -> void
{
  return mockglfw::instance->DestroyWindow(window);
}

auto glfwInit() -> int
{
  return mockglfw::instance->Init();
}

auto glfwMakeContextCurrent(::GLFWwindow *window) -> void
{
  mockglfw::instance->MakeContextCurrent(window);
}

auto glfwPollEvents() -> void
{
  mockglfw::instance->PollEvents();
}

auto glfwSetErrorCallback(::GLFWerrorfun fn) -> ::GLFWerrorfun
{
  return mockglfw::instance->SetErrorCallback(std::move(fn));
}

auto glfwSwapBuffers(::GLFWwindow *window) -> void
{
  mockglfw::instance->SwapBuffers(window);
}

auto glfwTerminate() -> void
{
  mockglfw::instance->Terminate();
}

auto glfwWindowHint(int target, int value) -> void
{
  mockglfw::instance->WindowHint(target, value);
}

auto glfwWindowShouldClose(::GLFWwindow *window) -> int
{
  return mockglfw::instance->WindowShouldClose(window);
}

