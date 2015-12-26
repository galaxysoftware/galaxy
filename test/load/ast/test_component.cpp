#include "load/ast/component.h"

#include <yaml-cpp/yaml.h>

#include <gtest/gtest.h>

using namespace gxy;

struct stub_component
{
  using data = int;
  using const_data = bool;
};

using stub_uut = ast::component_facade<stub_component>;

// Check that the types of our data has successfully propagated into the facade.
static_assert(std::is_same<decltype(std::declval<stub_uut>().data), int>{});
static_assert(std::is_same<decltype(std::declval<stub_uut>().const_data), bool>{});

// All existing components should be accessible in our ast::component variant.
using expected = eggs::variant<
  ast::component_facade<components::transform>
>;

static_assert(std::is_same<expected, ast::component>{});

struct fixture : public ::testing::Test{};

TEST_F(fixture, facade_data)
{
  const stub_uut uut(42, true);
  ASSERT_EQ(42, uut.data);
}

TEST_F(fixture, facade_const_data)
{
  const stub_uut uut(42, false);
  ASSERT_EQ(false, uut.const_data);
}

TEST_F(fixture, is_equal_self)
{
  const stub_uut uut(42, false);
  ASSERT_TRUE(uut == stub_uut(42, false));
}

TEST_F(fixture, not_not_equal_self)
{
  const stub_uut uut(42, false);
  ASSERT_FALSE(uut != stub_uut(42, false));
}

TEST_F(fixture, not_equal_different_data)
{
  const stub_uut uut(42, false);
  ASSERT_FALSE(uut == stub_uut(89, false));
}

TEST_F(fixture, is_not_equal_different_data)
{
  const stub_uut uut(42, false);
  ASSERT_TRUE(uut != stub_uut(89, false));
}

TEST_F(fixture, not_equal_different_const_data)
{
  const stub_uut uut(42, false);
  ASSERT_FALSE(uut == stub_uut(42, true));
}

TEST_F(fixture, is_not_equal_different_const_data)
{
  const stub_uut uut(42, false);
  ASSERT_TRUE(uut != stub_uut(42, true));
}

struct parse_fixture : public ::testing::Test{};

TEST_F(parse_fixture, parse_transform)
{
  const auto input = YAML::Load(
    "transform:\n"
    " data:\n"
    "   translate: [1, 2, 3]\n"
    "   rotate: [4, 5, 6]\n"
    "   scale: [7, 8, 9]\n"
    " const_data: {}\n"
  );

  std::vector<ast::component> expected{
    ast::component_facade<components::transform>(
      components::transform::data(glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9)),
      components::transform::const_data())
  };

  ASSERT_EQ(expected, parse<std::vector<ast::component>>(input));
}

