#include "gl/context.h"
#include "gl/environment.h"

#include <gtest/gtest.h>

using namespace gxy;

struct Fixture : public testing::Test
{
  int width{42};
  int height{89};
  std::string title{"badger"};

  gl::environment env{};
  gl::context ctx{env, width, height, title.c_str()};
};

TEST_F(Fixture, OpenGLMajorVersion)
{
  int major{};
  ::glGetIntegerv(GL_MAJOR_VERSION, &major);

  ASSERT_EQ(4, major);
}

TEST_F(Fixture, OpenGLMinorVersion)
{
  int minor{};
  ::glGetIntegerv(GL_MINOR_VERSION, &minor);

  ASSERT_EQ(1, minor);
}

