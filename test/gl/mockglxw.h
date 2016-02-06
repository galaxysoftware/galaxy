#ifndef TEST_GL_MOCKGLXW_H
#define TEST_GL_MOCKGLXW_H

#if BOOST_OS_LINUX
#include <GLXW/glxw.h>
#endif

#include <gmock/gmock.h>

namespace gxy::gl {

struct mockglxw
{
  mockglxw();

  MOCK_CONST_METHOD0(Init, int());

  static mockglxw *instance;
};

inline
mockglxw::mockglxw()
{
  instance = this;
}

} // namespace gl::gxy

#endif // TEST_GL_MOCKGLXW_H

