#include "component/background.h"

#include "component/name_fixture.h"
#include "component/parse_fixture.h"

#include <gtest/gtest.h>

using namespace gxy;

using components::background;

// Background has no data.
static_assert(std::is_same<components::empty_data, background::data>{});

struct Fixture : public testing::Test
{
  glm::vec3 colour1{10, 11, 12};
  glm::vec3 colour2{13, 14, 15};

  background::const_data uut{colour1};
};

TEST_F(Fixture, Colour)
{
  ASSERT_EQ(colour1, uut.colour);
}

TEST_F(Fixture, IsEqualSelf)
{
  ASSERT_TRUE(background::const_data(colour1) == uut);
}

TEST_F(Fixture, NotNotEqualSelf)
{
  ASSERT_FALSE(background::const_data(colour1) != uut);
}

TEST_F(Fixture, NotEqualDifferentColour)
{
  ASSERT_FALSE(background::const_data(colour2) == uut);
}

TEST_F(Fixture, IsNotEqualDifferentColour)
{
  ASSERT_TRUE(background::const_data(colour2) != uut);
}

template <>
auto NameFixture<background>::expected() -> std::string
{
  return "background";
}

INSTANTIATE_TYPED_TEST_CASE_P(Background, NameFixture, background);

template<>
auto ParseFixture<background::const_data>::valid_cases()
  -> valid_cases_type
{
  return {
    std::make_pair(YAML::Load("{ colour: [1, 2, 3] }"), background::const_data{ glm::vec3(1, 2, 3) })
  };
}

template <>
auto ParseFixture<background::const_data>::invalid_cases()
  -> invalid_cases_type
{
  return {
    YAML::Load("{}"),
    YAML::Load("{ colour: [1, 2, 3], transform: [4, 5, 6] }"),

    YAML::Load("[colour]"),
    YAML::Load("[1, 2, 3]"),
    YAML::Load("42")
  };
}

INSTANTIATE_TYPED_TEST_CASE_P(Background, ParseFixture, background::const_data);


