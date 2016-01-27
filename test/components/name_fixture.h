#ifndef TEST_COMPONENTS_NAME_FIXTURE_H
#define TEST_COMPONENTS_NAME_FIXTURE_H

#include "components/name.h"

#include <gtest/gtest.h>

namespace gxy {

template <typename Component>
class NameFixture : public testing::Test
{
public:
  auto expected() const -> std::string;
};

TYPED_TEST_CASE_P(NameFixture);

TYPED_TEST_P(NameFixture, ComponentNameType_IsString)
{
  ASSERT_TRUE((std::is_same<decltype(components::name<TypeParam>), std::string>{}));
}

TYPED_TEST_P(NameFixture, ComponentName_IsExpected)
{
  ASSERT_EQ(TestFixture::expected(), components::name<TypeParam>);
}

REGISTER_TYPED_TEST_CASE_P(NameFixture,
  ComponentNameType_IsString,
  ComponentName_IsExpected);

} // namespace gxy

#endif // TEST_COMPONENTS_NAME_FIXTURE_H

