#include "component/list.h"
#include "component/name.h"

#include "utils/meta/apply.h"

#include <gtest/gtest.h>

using namespace gxy;

template <typename T>
std::string expected;

template <>
auto expected<components::transform> = "transform";

template <typename T>
struct fixture : public ::testing::Test{};

using types = meta::apply_t<::testing::Types, components::list>;

TYPED_TEST_CASE(fixture, types);

TYPED_TEST(fixture, component_name)
{
  ASSERT_EQ(expected<TypeParam>, components::name<TypeParam>);
}

