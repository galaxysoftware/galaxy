#include "gl/context.h"

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

  ::GLFWwindow window{};
  NiceMock<gl::mockglfw> mockglfw{};

  Fixture()
  {
    ON_CALL(mockglfw, CreateWindow(_, _, _, _, _))
      .WillByDefault(Return(&window));
  }
};

using FixtureDeathTest = Fixture;

TEST_F(Fixture, CreateContext_CreatesWindow)
{
  EXPECT_CALL(mockglfw, CreateWindow(width, height, title.c_str(), nullptr, nullptr))
    .Times(1);

  gl::context ctx{width, height, title.c_str()};
}

TEST_F(FixtureDeathTest, CreateWindowReturnsNullptr_Death)
{
  ASSERT_DEATH({
    ON_CALL(mockglfw, CreateWindow(_, _, _, _, _))
      .WillByDefault(Return(nullptr));

    gl::context ctx(width, height, title.c_str());
  }, "");
}

TEST_F(Fixture, CreateContext_MakesContextCurrent)
{
  EXPECT_CALL(mockglfw, MakeContextCurrent(&window))
    .Times(1);

  gl::context ctx{width, height, title.c_str()};
}

TEST_F(Fixture, DestructContext_CallsDestroyWindow)
{
  gl::context ctx{width, height, title.c_str()};

  EXPECT_CALL(mockglfw, DestroyWindow(&window))
    .Times(1);
}

struct ContextFixture : public Fixture
{
  gl::context uut{width, height, title.c_str()};
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

