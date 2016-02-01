#include <GLFW/glfw3.h>

#include <gtest/gtest.h>

TEST(GLFW, IncludesGLCoreArb)
{
#ifndef GLFW_INCLUDE_GLCOREARB
  FAIL();
#endif
}

struct Fixture : public testing::Test
{
  int major, minor, patch;

  Fixture()
  {
    ::glfwGetVersion(&major, &minor, &patch);
  }
};

TEST_F(Fixture, MajorVersion3)
{
  ASSERT_EQ(3, major);
}

TEST_F(Fixture, MinorVersionIs1)
{
  ASSERT_EQ(1, minor);
}

TEST_F(Fixture, PatchVersionIs2)
{
  ASSERT_EQ(2, patch);
}

