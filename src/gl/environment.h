#ifndef GL_ENVIRONMENT_H
#define GL_ENVIRONMENT_H

#include <boost/predef.h>

#include <GLFW/glfw3.h>

#if BOOST_OS_LINUX
#include <GLXW/glxw.h>
#endif

namespace gxy::gl {

// Stateless class that handles initialising and tearing down GLFW. Also manages the error callback.
class environment
{
public:
  environment();
  ~environment();

  // Can't copy or move.
  environment(const environment &) = delete;
  auto operator=(const environment &) = delete;
};

} // namespace gl::gxy

#endif // GL_ENVIRONMENT_H
