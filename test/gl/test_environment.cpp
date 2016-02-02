#include "gl/environment.h"

#include "gl/glfw_error.h"
#include "gl/mockglfw.h"

#include <gmock/gmock.h>

using namespace gxy;

using testing::_;
using testing::DoAll;
using testing::InvokeArgument;
using testing::IsNull;
using testing::NiceMock;
using testing::NotNull;
using testing::Return;

struct Fixture : public testing::Test
{
  NiceMock<gl::mockglfw> mockglfw{};

  Fixture()
  {
    ON_CALL(mockglfw, Init())
      .WillByDefault(Return(GL_TRUE));
  }
};

TEST_F(Fixture, CreateEnvironment_CallsInit)
{
  EXPECT_CALL(mockglfw, Init())
    .Times(1);

  gl::environment env;
}

TEST_F(Fixture, InitReturnsFalse_Throw)
{
  EXPECT_CALL(mockglfw, Init())
    .WillOnce(Return(GL_FALSE));

  ASSERT_THROW(gl::environment(), gl::glfw_error);
}

TEST_F(Fixture, SetErrorCallbackCalled)
{
  EXPECT_CALL(mockglfw, SetErrorCallback(NotNull()))
    .Times(1);

  gl::environment env;

  EXPECT_CALL(mockglfw, SetErrorCallback(IsNull()))
    .Times(1);
}

TEST_F(Fixture, SetErrorCallback_InvokeThrows)
{
  auto callback([](int, const char *) {});

  EXPECT_CALL(mockglfw, SetErrorCallback(_))
    .WillOnce(DoAll(InvokeArgument<0>(0, "badger"), Return(callback)));

  ASSERT_THROW(gl::environment(), gl::glfw_error);
}

TEST_F(Fixture, SetErroCallback_InvokeThrowsParametersPropagated)
{
  auto callback([](int, const char *) {});

  EXPECT_CALL(mockglfw, SetErrorCallback(_))
    .WillOnce(DoAll(InvokeArgument<0>(GLFW_INVALID_ENUM, "badger"), Return(callback)));

  try {
    gl::environment env;
  } catch(const std::exception &e) {
    ASSERT_STREQ("invalid_enum: badger", e.what());
  }
}

TEST_F(Fixture, TerminateCalledOnDestruction)
{
  gl::environment env;

  EXPECT_CALL(mockglfw, Terminate())
    .Times(1);
}

using FixtureDeathTest = Fixture;

TEST_F(FixtureDeathTest, SetErrorCallbackReturnsNull)
{
  ASSERT_DEATH({
    auto callback([](int, const char *) {});
    EXPECT_CALL(mockglfw, SetErrorCallback(_))
      .WillOnce(Return(callback));

    gl::environment env;
  }, "");
}
