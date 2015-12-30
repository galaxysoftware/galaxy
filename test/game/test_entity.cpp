#include "game/entity.h"

#include "config/ast/entity.h"

#include <gtest/gtest.h>

using namespace gxy;

struct Fixture : public ::testing::Test
{
  entity uut{"badger", std::vector<component>{}};
};

TEST_F(Fixture, NameIsExpected)
{
  ASSERT_EQ("badger", uut.name);
}

TEST_F(Fixture, ComponentsIsExpected)
{
  ASSERT_EQ(std::vector<component>(), uut.components);
}

TEST_F(Fixture, IsEqualSelf)
{
  ASSERT_TRUE(uut == entity("badger", std::vector<component>()));
}

TEST_F(Fixture, NotNotEqualSelf)
{
  ASSERT_FALSE(uut != entity("badger", std::vector<component>()));
}

TEST_F(Fixture, NotEqualDifferentName)
{
  ASSERT_FALSE(uut == entity("fox", std::vector<component>()));
}

TEST_F(Fixture, IsNotEqualDifferentName)
{
  ASSERT_TRUE(uut != entity("fox", std::vector<component>()));
}

TEST_F(Fixture, NotEqualDifferentComponents)
{
  using components::transform;

  std::vector<component> components{
    component_facade<transform>({glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9)}, {})
  };

  ASSERT_FALSE(uut == entity("badger", components));
}

TEST_F(Fixture, IsNotEqualDifferentComponents)
{
  using components::transform;

  std::vector<component> components{
    component_facade<transform>({glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9)}, {})
  };

  ASSERT_TRUE(uut != entity("badger", components));
}

struct MakeEntityFixture : public ::testing::Test{};

TEST_F(MakeEntityFixture, MakeEntity)
{
  using components::transform;

  std::vector<ast::component> components{
    ast::component_facade<transform>(
      {glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9)}, {})
  };

  ast::entity uut("badger", components);

  std::vector<component> expected_components{
    component_facade<transform>({glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9)}, {})
  };

  ASSERT_EQ(entity("badger", expected_components), make_entity(uut));
}
