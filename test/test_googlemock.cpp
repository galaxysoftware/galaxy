#include <gtest/gtest.h>

class foo
{
  void bar() const = 0;
};

class mock_foo
{
  GMOCK_CONST_METHOD0(bar, void());
};

TEST(foo, bar)
{
  mock_foo f;

  EXPECT_CALL(f, bar())
    .Times(1);

  f.bar();
}


