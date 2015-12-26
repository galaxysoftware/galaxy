#include "load/ast/entity.h"

#include <yaml-cpp/yaml.h>

#include <gtest/gtest.h>

using namespace gxy;

struct fixture : public ::testing::Test{};

TEST_F(fixture, name)
{
  const ast::entity uut("badger", {});
  ASSERT_EQ("badger", uut.name);
}

TEST_F(fixture, components)
{
  std::vector<ast::component> components{
    ast::component_facade<components::transform>(
      components::transform::data(glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9)),
      components::transform::const_data())
  };

  const ast::entity uut("", components);
  ASSERT_EQ(components, uut.components);
}

TEST_F(fixture, is_equal_self)
{
  const ast::entity uut("badger", {});
  ASSERT_TRUE(uut == ast::entity("badger", {}));
}

TEST_F(fixture, not_not_equal_self)
{
  const ast::entity uut("badger", {});
  ASSERT_FALSE(uut != ast::entity("badger", {}));
}

TEST_F(fixture, not_equal_different_name)
{
  const ast::entity uut("badger", {});
  ASSERT_FALSE(uut == ast::entity("fox", {}));
}

TEST_F(fixture, is_not_equal_different_name)
{
  const ast::entity uut("badger", {});
  ASSERT_TRUE(uut != ast::entity("fox", {}));
}

TEST_F(fixture, not_equal_different_components)
{
  std::vector<ast::component> components{
    ast::component_facade<components::transform>(
      components::transform::data(glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9)),
      components::transform::const_data())
  };

  const ast::entity uut("badger", components);
  ASSERT_FALSE(uut == ast::entity("badger", {}));
}

TEST_F(fixture, is_not_equal_different_components)
{
  std::vector<ast::component> components{
    ast::component_facade<components::transform>(
      components::transform::data(glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9)),
      components::transform::const_data())
  };

  const ast::entity uut("badger", components);
  ASSERT_TRUE(uut != ast::entity("badger", {}));
}

struct parse_fixture : public ::testing::Test
{
  const YAML::Node uut = YAML::Load(
    "name: badger\n"
    "components:\n"
    " transform:\n"
    "   data:\n"
    "     translate: [1, 2, 3]\n"
    "     rotate: [4, 5, 6]\n"
    "     scale: [7, 8, 9]\n"
    "   const_data: {}\n"
  );
};

TEST_F(parse_fixture, name)
{
  const auto result(parse<ast::entity>(uut));
  ASSERT_EQ("badger", result.name);
}

TEST_F(parse_fixture, components)
{
  const auto result(parse<ast::entity>(uut));

  std::vector<ast::component> expected{
    ast::component_facade<components::transform>(
      components::transform::data(glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9)),
      components::transform::const_data())
  };

  ASSERT_EQ(expected, result.components);
}

