#include "utils/scoped_directory.h"

#include <boost/filesystem/operations.hpp>

#include <gtest/gtest.h>

#include <fstream>

using namespace gxy;

struct fixture : public ::testing::Test
{
  const ::testing::TestInfo &info{*::testing::UnitTest::GetInstance()->current_test_info()};
};

TEST_F(fixture, directory_exists)
{
  scoped_directory dir{info.name()};
//  ASSERT_TRUE(boost::filesystem::exists(info.name()));
}

TEST_F(fixture, DISABLED_out_of_scope_directory_doesnt_exist)
{
  {
    scoped_directory dir{info.name()};
  }

  ASSERT_FALSE(boost::filesystem::exists(info.name()));
}

TEST_F(fixture, DISABLED_out_of_scope_nonempty_directory_doesnt_exist)
{
  {
    scoped_directory dir{info.name()};

    const auto file(dir.name() / info.name());
    std::ofstream fs(file.string());
  }

  ASSERT_FALSE(boost::filesystem::exists(info.name()));
}

TEST_F(fixture, name)
{
  scoped_directory dir{info.name()};
  ASSERT_EQ(info.name(), dir.name());
}

