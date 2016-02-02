#ifndef TEST_GL_MOCKGLFW_H
#define TEST_GL_MOCKGLFW_H

#include <GLFW/glfw3.h>

#include <gmock/gmock.h>

namespace gxy::gl {

struct mockglfw
{
  mockglfw();

  MOCK_CONST_METHOD0(Init, int());
  MOCK_CONST_METHOD1(SetErrorCallback, ::GLFWerrorfun(::GLFWerrorfun));
  MOCK_CONST_METHOD0(Terminate, void());

  static mockglfw *instance;
};

inline
mockglfw::mockglfw()
{
  instance = this;
}

} // namespace gxy::gl

#endif // TEST_GL_MOCKGLFW_H

