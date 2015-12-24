#include "components/empty_data.h"

#include <gtest/gtest.h>

using namespace gxy;

struct fixture : public ::testing::Test
{
  components::empty_data uut;
};

TEST_F(fixture, equal_empty_data)
{
  ASSERT_TRUE(uut == components::empty_data());
}

TEST_F(fixture, not_not_equal_empty_data)
{
  ASSERT_FALSE(uut != components::empty_data());
}

