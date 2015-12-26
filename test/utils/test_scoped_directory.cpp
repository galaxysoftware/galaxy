#include "utils/scoped_directory.h"

#include <boost/filesystem/operations.hpp>

#include <gtest/gtest.h>

#include <fstream>

using namespace gxy;

struct fixture : public ::testing::Test{};

TEST_F(fixture, directory_exists)
{
  scoped_directory dir{"badger.dir"};
  ASSERT_TRUE(boost::filesystem::exists("badger.dir"));
}

TEST_F(fixture, out_of_scope_directory_doesnt_exist)
{
  {
    scoped_directory dir{"badger.dir"};
  }

  ASSERT_FALSE(boost::filesystem::exists("badger.dir"));
}

TEST_F(fixture, out_of_scope_nonempty_directory_doesnt_exist)
{
  {
    scoped_directory dir{"badger.dir"};

    const auto file(dir.name() / "badger.txt");
    std::ofstream fs(file.string());

    ASSERT_TRUE(boost::filesystem::exists("badger.dir/badger.txt"));
  }

  ASSERT_FALSE(boost::filesystem::exists("badger.dir"));
}

TEST_F(fixture, name)
{
  scoped_directory dir{"badger.dir"};
  ASSERT_EQ("badger.dir", dir.name());
}

