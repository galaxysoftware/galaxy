#include "config/load.h"

#include "utils/scoped_directory.h"

#include <gtest/gtest.h>

#include <boost/filesystem/operations.hpp>

#include <fstream>

using namespace gxy;

struct fixture : public ::testing::Test
{
  const ::testing::TestInfo &info;
  scoped_directory dir;
  boost::filesystem::path uut;

  fixture(const boost::filesystem::path &file)
  : info{*::testing::UnitTest::GetInstance()->current_test_info()},
    dir{info.name()},
    uut{dir.name() / file}
  {
  }
};

struct no_entities : public fixture
{
  no_entities()
  : fixture("no_entity.yml")
  {
    std::ofstream fs(uut.string());
    fs << "entities: []" << std::endl;
  }
};

TEST_F(no_entities, empty_vector)
{
  ASSERT_EQ(std::vector<ast::entity>(), load(uut));
}

struct single_entity : public fixture
{
  single_entity()
  : fixture("single_entity.yml")
  {
    std::ofstream fs(uut.string());
    fs << "entities:" << std::endl
       << "  - name: game_object1" << std::endl
       << "    components: {}" << std::endl
       << std::endl;
  }
};

TEST_F(single_entity, vector_with_single_entity)
{
  std::vector<ast::entity> expected{ ast::entity("game_object1", std::vector<ast::component>()) };
  ASSERT_EQ(expected, load(uut));
}

struct multiple_entities : public fixture
{
  multiple_entities()
  : fixture("multiple_entities.yml")
  {
    std::ofstream fs(uut.string());
    fs << "entities:" << std::endl
       << "  - name: game_object1" << std::endl
       << "    components: {}" << std::endl
       << "  - name: game_object2" << std::endl
       << "    components: {}" << std::endl
       << std::endl;
  }
};

TEST_F(multiple_entities, vector_with_multiple_entities)
{
  std::vector<ast::entity> expected{
    ast::entity("game_object1", std::vector<ast::component>()),
    ast::entity("game_object2", std::vector<ast::component>())
  };

  ASSERT_EQ(expected, load(uut));
}

