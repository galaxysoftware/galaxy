#include "config/ast/scene.h"

#include <yaml-cpp/yaml.h>

#include <gtest/gtest.h>

using namespace gxy;

struct Fixture : public ::testing::Test{};

TEST_F(Fixture, EntityEmptyList)
{
  const auto uut(YAML::Load("entities: []"));
  ASSERT_EQ(ast::scene(), parse<ast::scene>(uut));
}

TEST_F(Fixture, SingleEntity)
{
  const auto uut(YAML::Load(
    "entities:\n"
    " - name: game_object1\n"
    "   components: {}\n"
  ));

  const ast::scene expected{ ast::entity("game_object1", std::vector<ast::component>()) };
  ASSERT_EQ(expected, parse<ast::scene>(uut));
}

TEST_F(Fixture, MultipleEntities)
{
  const auto uut(YAML::Load(
    "entities:\n"
    " - name: game_object1\n"
    "   components: {}\n"
    " - name: game_object2\n"
    "   components: {}\n"
  ));

  const ast::scene expected{
    ast::entity("game_object1", std::vector<ast::component>()),
    ast::entity("game_object2", std::vector<ast::component>())
  };
  ASSERT_EQ(expected, parse<ast::scene>(uut));
}

