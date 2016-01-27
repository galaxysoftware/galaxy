#include "components/transform.h"

#include "components/name_fixture.h"
#include "components/parse_fixture.h"

#include <gtest/gtest.h>

using namespace gxy;

using components::transform;

// Transform has no const_data.
static_assert(std::is_same<components::empty_data, transform::const_data>{});

struct Fixture : public testing::Test
{
  glm::vec3 translate1{10, 11, 12};
  glm::vec3 translate2{13, 14, 15};

  glm::vec3 rotate1{20, 21, 22};
  glm::vec3 rotate2{23, 24, 25};

  glm::vec3 scale1{30, 31, 32};
  glm::vec3 scale2{33, 34, 35};

  transform::data uut{translate1, rotate1, scale1};
};

TEST_F(Fixture, Translate)
{
  ASSERT_EQ(translate1, uut.translate);
}

TEST_F(Fixture, Rotate)
{
  ASSERT_EQ(rotate1, uut.rotate);
}

TEST_F(Fixture, Scale)
{
  ASSERT_EQ(scale1, uut.scale);
}

TEST_F(Fixture, IsEqualSelf)
{
  ASSERT_TRUE(transform::data(translate1, rotate1, scale1) == uut);
}

TEST_F(Fixture, NotNotEqualSelf)
{
  ASSERT_FALSE(transform::data(translate1, rotate1, scale1) != uut);
}

TEST_F(Fixture, NotEqualDifferentTranslate)
{
  ASSERT_FALSE(transform::data(translate2, rotate1, scale1) == uut);
}

TEST_F(Fixture, IsNotEqualDifferentTranslate)
{
  ASSERT_TRUE(transform::data(translate2, rotate1, scale1) != uut);
}

TEST_F(Fixture, NotEqualDifferentRotate)
{
  ASSERT_FALSE(transform::data(translate1, rotate2, scale1) == uut);
}

TEST_F(Fixture, IsNotEqualDifferentRotate)
{
  ASSERT_TRUE(transform::data(translate1, rotate2, scale1) != uut);
}

TEST_F(Fixture, NotEqualDifferentScale)
{
  ASSERT_FALSE(transform::data(translate1, rotate1, scale2) == uut);
}

TEST_F(Fixture, IsNotEqualDifferentScale)
{
  ASSERT_TRUE(transform::data(translate1, rotate1, scale2) != uut);
}

template <>
auto NameFixture<transform>::expected() -> std::string
{
  return "transform";
}

INSTANTIATE_TYPED_TEST_CASE_P(Transform, NameFixture, transform);

template<>
auto ParseFixture<transform::data>::valid_cases()
  -> valid_cases_type
{
  return {
    std::make_pair(
      YAML::Load("{ translate: [1, 2, 3], rotate: [4, 5, 6], scale: [7, 8, 9] }"),
      transform::data{ glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9) }
    )
  };
}

template <>
auto ParseFixture<transform::data>::invalid_cases()
  -> invalid_cases_type
{
  return {
    YAML::Load("{ translate: [1, 2, 3], rotate: [4, 5, 6] }"),
    YAML::Load("{ translate: [1, 2, 3], scale: [4, 5, 6] }"),
    YAML::Load("{ rotate: [1, 2, 3], scale: [4, 5, 6] }"),

    YAML::Load("{ translate: [1, 2, 3], rotate: [4, 5, 6], scale: [7, 8, 9], time: 4 }"),

    YAML::Load("[ translate, rotate, scale ]"),
    YAML::Load("42")
  };
}

INSTANTIATE_TYPED_TEST_CASE_P(Transform, ParseFixture, transform::data);

