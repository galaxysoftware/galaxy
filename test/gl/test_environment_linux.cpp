#include "gl/environment.h"

#include "gl/mockglfw.h"
#include "gl/mockglxw.h"

#include <gmock/gmock.h>

using namespace gxy;

using testing::InSequence;
using testing::NiceMock;
using testing::Return;

struct Fixture : public testing::Test
{
  NiceMock<gl::mockglxw> mockglxw{};
  NiceMock<gl::mockglfw> mockglfw{};

  Fixture()
  {
    ON_CALL(mockglfw, Init())
      .WillByDefault(Return(GL_TRUE));
  }
};

TEST_F(Fixture, GlxwInitCalledAfterGlfwInit)
{
  InSequence s;

  EXPECT_CALL(mockglfw, Init())
    .Times(1);

  EXPECT_CALL(mockglxw, Init())
    .Times(1);

  gl::environment env;
}

TEST_F(Fixture, GlfwInitReturnsFalse_GlxwInitNeverCalled)
{
  EXPECT_CALL(mockglfw, Init())
    .WillOnce(Return(GL_FALSE));

  EXPECT_CALL(mockglxw, Init())
    .Times(0);

  ASSERT_ANY_THROW(gl::environment());
}

TEST_F(Fixture, GlfwInitReturnsNonZero_Throws)
{
  EXPECT_CALL(mockglxw, Init())
    .WillOnce(Return(-1));

  ASSERT_THROW(gl::environment(), std::runtime_error);
}

