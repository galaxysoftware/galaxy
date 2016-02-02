#include "gl/glfw_error.h"

#include <gtest/gtest.h>

using namespace gxy;

TEST(GlfwError, WhatIsBadger)
{
  gl::glfw_error e{"badger"};
  ASSERT_STREQ("unknown_error: badger", e.what());
}

using params = std::pair<gl::glfw_error::code, std::string>;
struct Fixture : public testing::TestWithParam<params>
{
  gl::glfw_error uut{GetParam().first, "badger"};
  std::string expected{GetParam().second};
};

TEST_P(Fixture, ErrorCode)
{
  ASSERT_EQ(expected, uut.what());
}

INSTANTIATE_TEST_CASE_P(WithErrorCodes, Fixture, testing::Values(
  std::make_pair(gl::glfw_error::code::unknown_error, "unknown_error: badger"),
  std::make_pair(gl::glfw_error::code::not_initialised, "not_initialised: badger"),
  std::make_pair(gl::glfw_error::code::no_current_context, "no_current_context: badger"),
  std::make_pair(gl::glfw_error::code::invalid_enum, "invalid_enum: badger"),
  std::make_pair(gl::glfw_error::code::invalid_value, "invalid_value: badger"),
  std::make_pair(gl::glfw_error::code::out_of_memory, "out_of_memory: badger"),
  std::make_pair(gl::glfw_error::code::api_unavailable, "api_unavailable: badger"),
  std::make_pair(gl::glfw_error::code::version_unavailable, "version_unavailable: badger"),
  std::make_pair(gl::glfw_error::code::platform_error, "platform_error: badger"),
  std::make_pair(gl::glfw_error::code::format_unavailable, "format_unavailable: badger")
),);

