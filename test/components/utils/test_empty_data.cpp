#include "components/utils/empty_data.h"

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

TEST_F(Fixture, ParseEmptyMap)
{
  const auto yaml(YAML::Load("{}"));
  ASSERT_EQ(uut, parse<components::empty_data>(yaml));
}

