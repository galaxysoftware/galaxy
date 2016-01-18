#include "components/list.h"
#include "components/name.h"

#include "utils/meta/apply.h"

#include <gtest/gtest.h>

using namespace gxy;

template <typename T>
std::string expected;

template <>
auto expected<components::transform> = "transform";

template <>
auto expected<components::background> = "background";

template <typename T>
struct Fixture : public ::testing::Test{};

using types = meta::apply_t<::testing::Types, components::list>;

TYPED_TEST_CASE(Fixture, types);

TYPED_TEST(Fixture, ComponentNameType)
{
  using components::name;

  ASSERT_TRUE((std::is_same<decltype(name<TypeParam>), std::string>{}));
}

TYPED_TEST(Fixture, ComponentName)
{
  ASSERT_EQ(expected<TypeParam>, components::name<TypeParam>);
}

