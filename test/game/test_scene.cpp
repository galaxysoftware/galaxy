#include "game/scene.h"

#include <gtest/gtest.h>

using namespace gxy;

struct Fixture : public ::testing::Test{};

TEST_F(Fixture, MakeScene)
{
  scene expected{{
    entity{"badger", std::vector<component>{}},
    entity{"fox", std::vector<component>{}}
  }};

  ast::scene uut{{
    ast::entity{"badger", std::vector<ast::component>{}},
    ast::entity{"fox", std::vector<ast::component>{}}
  }};

  ASSERT_EQ(expected, make_scene(uut));
}

