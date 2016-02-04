#ifndef GL_CONTEXT_H
#define GL_CONTEXT_H

#include "utils/resource.h"

#include <GLFW/glfw3.h>

namespace gxy::gl {

class context
{
public:
  context(int width, int height, const char *title);

  // Can't copy, can move.
  context(const context &) = delete;
  auto operator=(const context &) -> context & = delete;

  context(context &&) = default;
  auto operator=(context &&) -> context & = default;

  // Swap buffers, poll for events and check for close request.
  auto run_one() -> bool;

private:
  resource<::GLFWwindow> window_;
};

} // namespace gl::gxy

#endif // GL_CONTEXT_H

