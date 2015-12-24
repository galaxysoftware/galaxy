#include "components/transform.h"

#include <gtest/gtest.h>

using namespace gxy;

using components::transform;

// Transform has no const_data.
static_assert(std::is_same<components::empty_data, transform::const_data>{});

struct fixture : public ::testing::Test
{
  glm::vec3 translate1{10, 11, 12};
  glm::vec3 translate2{13, 14, 15};

  glm::vec3 rotate1{20, 21, 22};
  glm::vec3 rotate2{23, 24, 25};

  glm::vec3 scale1{30, 31, 32};
  glm::vec3 scale2{33, 34, 35};

  transform::data uut{translate1, rotate1, scale1};
};

TEST_F(fixture, translate)
{
  ASSERT_EQ(translate1, uut.translate);
}

TEST_F(fixture, rotate)
{
  ASSERT_EQ(rotate1, uut.rotate);
}

TEST_F(fixture, scale)
{
  ASSERT_EQ(scale1, uut.scale);
}

TEST_F(fixture, is_equal_self)
{
  ASSERT_TRUE(transform::data(translate1, rotate1, scale1) == uut);
}

TEST_F(fixture, not_not_equal_self)
{
  ASSERT_FALSE(transform::data(translate1, rotate1, scale1) != uut);
}

TEST_F(fixture, not_equal_different_translate)
{
  ASSERT_FALSE(transform::data(translate2, rotate1, scale1) == uut);
}

TEST_F(fixture, is_not_equal_different_translate)
{
  ASSERT_TRUE(transform::data(translate2, rotate1, scale1) != uut);
}

TEST_F(fixture, not_equal_different_rotate)
{
  ASSERT_FALSE(transform::data(translate1, rotate2, scale1) == uut);
}

TEST_F(fixture, is_not_equal_different_rotate)
{
  ASSERT_TRUE(transform::data(translate1, rotate2, scale1) != uut);
}

TEST_F(fixture, not_equal_different_scale)
{
  ASSERT_FALSE(transform::data(translate1, rotate1, scale2) == uut);
}

TEST_F(fixture, is_not_equal_different_scale)
{
  ASSERT_TRUE(transform::data(translate1, rotate1, scale2) != uut);
}

