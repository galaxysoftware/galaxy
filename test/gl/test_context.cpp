#include "gl/context.h"

#include "gl/environment.h"
#include "gl/mockglfw.h"

#include <gmock/gmock.h>

using namespace gxy;

using testing::_;
using testing::InSequence;
using testing::NiceMock;
using testing::Return;

struct Fixture : public testing::Test
{
  const int width{42};
  const int height{89};
  const std::string title{"badger"};

  NiceMock<gl::mockglfw> mockglfw{};

  ::GLFWwindow window{};

  Fixture()
  {
    ON_CALL(mockglfw, Init())
      .WillByDefault(Return(GL_TRUE));

    ON_CALL(mockglfw, CreateWindow(_, _, _, _, _))
      .WillByDefault(Return(&window));
  }
};

struct EnvironmentFixture : public Fixture
{
  gl::environment env{};
};

TEST_F(EnvironmentFixture, CreateContext_CreatesWindow)
{
  EXPECT_CALL(mockglfw, CreateWindow(width, height, title.c_str(), nullptr, nullptr))
    .Times(1);

  gl::context ctx{env, width, height, title.c_str()};
}

TEST_F(EnvironmentFixture, CreateContext_SetsWindowHintsBefore)
{
  InSequence s;

  EXPECT_CALL(mockglfw, WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4))
    .Times(1);

  EXPECT_CALL(mockglfw, WindowHint(GLFW_CONTEXT_VERSION_MINOR, 1))
    .Times(1);

  EXPECT_CALL(mockglfw, WindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE))
    .Times(1);

  EXPECT_CALL(mockglfw, WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE))
    .Times(1);

  EXPECT_CALL(mockglfw, CreateWindow(_, _, _, _, _))
    .Times(1);

  gl::context ctx{env, width, height, title.c_str()};
}

TEST_F(EnvironmentFixture, CreateContext_ResetWindowHintsAfter)
{
  InSequence s;

  EXPECT_CALL(mockglfw, CreateWindow(_, _, _, _, _))
    .Times(1);

  EXPECT_CALL(mockglfw, DefaultWindowHints())
    .Times(1);

  gl::context ctx{env, width, height, title.c_str()};
}

TEST_F(EnvironmentFixture, CreateContext_MakesContextCurrent)
{
  EXPECT_CALL(mockglfw, MakeContextCurrent(&window))
    .Times(1);

  gl::context ctx{env, width, height, title.c_str()};
}

TEST_F(EnvironmentFixture, DestructContext_CallsDestroyWindow)
{
  gl::context ctx{env, width, height, title.c_str()};

  EXPECT_CALL(mockglfw, DestroyWindow(&window))
    .Times(1);
}

using EnvironmentFixtureDeathTest = EnvironmentFixture;

TEST_F(EnvironmentFixtureDeathTest, CreateWindowReturnsNullptr_Death)
{
  ASSERT_DEATH({
    ON_CALL(mockglfw, CreateWindow(_, _, _, _, _))
      .WillByDefault(Return(nullptr));

    gl::context ctx(env, width, height, title.c_str());
  }, "");
}

struct ContextFixture : public EnvironmentFixture
{
  gl::context uut{env, width, height, title.c_str()};
};

TEST_F(ContextFixture, RunOneWindowShouldCloseTrue_ReturnsFalse)
{
  EXPECT_CALL(mockglfw, WindowShouldClose(&window))
    .WillOnce(Return(true));

  ASSERT_FALSE(uut.run_one());
}

struct ContextFixtureWindowShouldntClose : public ContextFixture
{
  ContextFixtureWindowShouldntClose()
  {
    ON_CALL(mockglfw, WindowShouldClose(&window))
      .WillByDefault(Return(false));
  }
};

TEST_F(ContextFixtureWindowShouldntClose, RunOne_ReturnsTrue)
{
  ASSERT_TRUE(uut.run_one());
}

TEST_F(ContextFixtureWindowShouldntClose, RunOne_CallsSwapBuffersThenPollEvents)
{
  InSequence s;

  EXPECT_CALL(mockglfw, SwapBuffers(&window))
    .Times(1);

  EXPECT_CALL(mockglfw, PollEvents())
    .Times(1);

  uut.run_one();
}

