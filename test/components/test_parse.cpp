#include "component/list.h"
#include "component/parse.h"

#include "utils/meta/apply.h"

#include <yaml-cpp/yaml.h>

#include <gtest/gtest.h>

using namespace gxy;
using namespace components;

template <typename T>
YAML::Node uut;

template <typename T>
auto expected() -> T;

template <>
auto uut<transform::data> = YAML::Load("{ translate: [1, 2, 3], rotate: [4, 5, 6], scale: [7, 8, 9] }");

template <>
auto expected<transform::data>() -> transform::data
{
  return { glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9) };
}

template <typename T>
struct fixture : public ::testing::Test{};

using types = meta::apply_t<::testing::Types, components::list>;

TYPED_TEST_CASE(fixture, types);

TYPED_TEST(fixture, parse)
{
  using data_type = typename TypeParam::data;
  ASSERT_EQ(expected<data_type>(), parse<data_type>(uut<data_type>));
}

