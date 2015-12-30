#include <boost/version.hpp>

#include <gtest/gtest.h>

TEST(BoostVersion, 1_59_0)
{
  ASSERT_EQ(BOOST_VERSION, 105900);
}
