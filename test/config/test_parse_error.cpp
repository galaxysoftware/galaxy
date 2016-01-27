#include "config/parse_error.h"

#include <gtest/gtest.h>

using namespace gxy;

TEST(Fixture, Throw_WhatIsParseError)
{
  try {
    throw parse_error{};
  } catch(const std::exception &e) {
    ASSERT_STREQ("parse error", e.what());
  }
}

