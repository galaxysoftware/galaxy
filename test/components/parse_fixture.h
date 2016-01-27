#ifndef TEST_COMPONENTS_PARSE_FIXTURE_H
#define TEST_COMPONENTS_PARSE_FIXTURE_H

#include "config/parse.h"
#include "config/parse_error.h"

#include <yaml-cpp/yaml.h>

#include <gtest/gtest.h>

namespace gxy {

template <typename Component>
class ParseFixture : public testing::Test
{
protected:
  using data = typename Component::data;
  using const_data = typename Component::const_data;

  template <typename T>
  using valid_cases = std::vector<std::pair<YAML::Node, T>>;

  template <typename T>
  using invalid_cases = std::vector<YAML::Node>;

  // Test case generators.
  static auto valid_data_cases() -> valid_cases<data>;
  static auto invalid_data_cases() -> invalid_cases<data>;

  static auto valid_const_data_cases() -> valid_cases<const_data>;
  static auto invalid_const_data_cases() -> invalid_cases<const_data>;
};

TYPED_TEST_CASE_P(ParseFixture);

TYPED_TEST_P(ParseFixture, ValidDataCases)
{
  for (const auto &test_case : TestFixture::valid_data_cases()) {
    SCOPED_TRACE(test_case.first);

    ASSERT_EQ(test_case.second, parse<typename TypeParam::data>(test_case.first));
  }
}

TYPED_TEST_P(ParseFixture, InvalidDataCases)
{
  for (const auto &test_case : TestFixture::invalid_data_cases()) {
    SCOPED_TRACE(test_case);

    ASSERT_THROW(parse<typename TypeParam::data>(test_case), parse_error);
  }
}

TYPED_TEST_P(ParseFixture, ValidConstDataCases)
{
  for (const auto &test_case : TestFixture::valid_const_data_cases()) {
    SCOPED_TRACE(test_case.first);

    ASSERT_EQ(test_case.second, parse<typename TypeParam::const_data>(test_case.first));
  }
}

TYPED_TEST_P(ParseFixture, InvalidConstDataCases)
{
  for (const auto &test_case : TestFixture::invalid_const_data_cases()) {
    SCOPED_TRACE(test_case);

    ASSERT_THROW(parse<typename TypeParam::const_data>(test_case), parse_error);
  }
}

REGISTER_TYPED_TEST_CASE_P(ParseFixture,
  ValidDataCases,
  InvalidDataCases,
  ValidConstDataCases,
  InvalidConstDataCases);

} // namespace gxy

#endif // TEST_COMPONENTS_PARSE_FIXTURE_H

