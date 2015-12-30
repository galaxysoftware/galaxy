#include "config/yaml/vec3.h"

#include <gtest/gtest.h>

TEST(fixture, decode_returns_true)
{
  glm::vec3 vec;
  const auto node(YAML::Load("[0, 0, 0]"));

  ASSERT_TRUE(YAML::convert<glm::vec3>::decode(node, vec));
}

TEST(fixture, decode_expected)
{
  glm::vec3 vec;
  const auto node(YAML::Load("[1, 2, 3]"));

  YAML::convert<glm::vec3>::decode(node, vec);
  ASSERT_EQ(glm::vec3(1, 2, 3), vec);
}

TEST(fixture, decode_wrong_length_false)
{
  glm::vec3 vec;
  const auto node(YAML::Load("[1, 2]"));

  ASSERT_FALSE(YAML::convert<glm::vec3>::decode(node, vec));
}

TEST(fixture, decode_scalar_false)
{
  glm::vec3 vec;
  const auto node(YAML::Load("1"));

  ASSERT_FALSE(YAML::convert<glm::vec3>::decode(node, vec));
}

TEST(fixture, decode_map_false)
{
  glm::vec3 vec;
  const auto node(YAML::Load("{a: 1, b: 2, c: 3}"));

  ASSERT_FALSE(YAML::convert<glm::vec3>::decode(node, vec));
}

