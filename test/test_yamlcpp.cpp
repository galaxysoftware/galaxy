#include <yaml-cpp/yaml.h>

#include <gtest/gtest.h>

TEST(foo, bar)
{
  YAML::Node node = YAML::Load("[1, 2, 3]");
  ASSERT_EQ(node.Type(), YAML::NodeType::Sequence);
}

