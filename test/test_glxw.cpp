#include <GLXW/glxw.h>

#include <gtest/gtest.h>

TEST(GLXW, Init)
{
  ASSERT_EQ(0, ::glxwInit());
}

