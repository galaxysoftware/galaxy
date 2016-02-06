#ifndef TEST_GL_MOCKGLFW_H
#define TEST_GL_MOCKGLFW_H

#include <GLFW/glfw3.h>

#include <gmock/gmock.h>

namespace gxy::gl {

struct mockglfw
{
  mockglfw();

  MOCK_CONST_METHOD5(CreateWindow, ::GLFWwindow *(int, int, const char *, GLFWmonitor *, GLFWwindow *));
  MOCK_CONST_METHOD0(DefaultWindowHints, void());
  MOCK_CONST_METHOD1(DestroyWindow, void(::GLFWwindow *));
  MOCK_CONST_METHOD0(Init, int());
  MOCK_CONST_METHOD1(MakeContextCurrent, void(::GLFWwindow *));
  MOCK_CONST_METHOD0(PollEvents, void());
  MOCK_CONST_METHOD1(SetErrorCallback, ::GLFWerrorfun(::GLFWerrorfun));
  MOCK_CONST_METHOD1(SwapBuffers, void(::GLFWwindow *));
  MOCK_CONST_METHOD0(Terminate, void());
  MOCK_CONST_METHOD2(WindowHint, void(int, int));
  MOCK_CONST_METHOD1(WindowShouldClose, int(::GLFWwindow *));

  static mockglfw *instance;
};

inline
mockglfw::mockglfw()
{
  instance = this;
}

} // namespace gxy::gl

// Stub GLFW objects.
struct GLFWwindow{};

#endif // TEST_GL_MOCKGLFW_H

