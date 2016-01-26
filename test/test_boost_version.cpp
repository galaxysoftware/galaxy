#include <boost/version.hpp>

#include <gtest/gtest.h>

TEST(BoostVersion, 1_60_0)
{
  ASSERT_EQ(BOOST_VERSION, 106000);
}
