#include "load/ast/component.h"

#include <yaml-cpp/yaml.h>

#include <gtest/gtest.h>

using namespace gxy;

struct stub_component
{
  using data = int;
  using const_data = bool;
};

using uut = ast::component_facade<stub_component>;

// Check that the types of our data has successfully propagated into the facade.
static_assert(std::is_same<decltype(std::declval<uut>().data), int>{});
static_assert(std::is_same<decltype(std::declval<uut>().const_data), bool>{});

// All existing components should be accessible in our ast::component variant.
using expected = eggs::variant<
  ast::component_facade<components::transform>
>;

static_assert(std::is_same<expected, ast::component>{});

struct fixture : public ::testing::Test{};

TEST(fixture, parse_transform)
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

