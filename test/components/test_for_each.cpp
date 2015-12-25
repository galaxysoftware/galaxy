#include "components/for_each.h"

#include "components/name.h"

#include <gtest/gtest.h>

using namespace gxy;

struct fixture : public ::testing::Test{};

TEST_F(fixture, for_each_name)
{
  std::stringstream ss;
  components::for_each([&ss](auto component) {
    using type = typename decltype(component)::type;

    ss << components::name<type> << std::endl;
  });

  ASSERT_EQ("transform\n", ss.str());
}

