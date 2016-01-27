#include "utils/throw_if.h"

#include <gtest/gtest.h>

using namespace gxy;

TEST(Fixture, PredFalse_NoThrow)
{
  ASSERT_NO_THROW(throw_if<std::exception>(false));
}

TEST(Fixture, PredTrue_Throws)
{
  ASSERT_ANY_THROW(throw_if<std::exception>(true));
}

TEST(Fixture, PredTrue_ThrowsExceptionType)
{
  class custom_error : public std::exception{};

  ASSERT_THROW(throw_if<custom_error>(true), custom_error);
}

