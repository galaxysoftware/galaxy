#include "config/load.h"

#include "game/scene.h"

#include "utils/scoped_directory.h"

#include <gtest/gtest.h>

#include <boost/filesystem/operations.hpp>

#include <fstream>

using namespace gxy;

struct Fixture : public ::testing::Test
{
  const ::testing::TestInfo &info{*::testing::UnitTest::GetInstance()->current_test_info()};
  scoped_directory dir{info.name()};
  boost::filesystem::path uut{dir.name() / "badger.yml"};

  Fixture()
  {
    std::ofstream fs{uut.string()};
    fs << "entities:" << std::endl
       << "  - name: game_object1" << std::endl
       << "    components: {}" << std::endl
       << "  - name: game_object2" << std::endl
       << "    components: {}" << std::endl
       << std::endl;
  }
};

TEST_F(Fixture, FileToScene)
{
  std::vector<entity> expected{
    entity("game_object1", std::vector<component>()),
    entity("game_object2", std::vector<component>())
  };

  ASSERT_EQ(expected, make_scene(load(uut)));
}
