#include "component/utils/empty_data.h"

#include "component/parse_fixture.h"

#include <gtest/gtest.h>

#include <yaml-cpp/yaml.h>

using namespace gxy;

struct Fixture : public ::testing::Test
{
  components::empty_data uut;
};

TEST_F(Fixture, EqualEmptyData)
{
  ASSERT_TRUE(uut == components::empty_data());
}

TEST_F(Fixture, NotNotEqualEmptyData)
{
  ASSERT_FALSE(uut != components::empty_data());
}

template <>
auto ParseFixture<components::empty_data>::valid_cases()
  -> valid_cases_type
{
  return {
    std::make_pair(YAML::Load("{}"), components::empty_data{})
  };
}

template <>
auto ParseFixture<components::empty_data>::invalid_cases()
  -> invalid_cases_type
{
  return {
    YAML::Load("1"),
    YAML::Load("[]"),
    YAML::Load("[0]"),
    YAML::Load("{ a: 0 }")
  };
}

INSTANTIATE_TYPED_TEST_CASE_P(EmptyData, ParseFixture, components::empty_data);

