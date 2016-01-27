#ifndef TEST_COMPONENTS_PARSE_FIXTURE_H
#define TEST_COMPONENTS_PARSE_FIXTURE_H

#include "config/parse.h"
#include "config/parse_error.h"

#include <yaml-cpp/yaml.h>

#include <gtest/gtest.h>

namespace gxy {

template <typename T>
class ParseFixture : public testing::Test
{
protected:
  using valid_cases_type = std::vector<std::pair<YAML::Node, T>>;
  using invalid_cases_type = std::vector<YAML::Node>;

  // Test case generators.
  static auto valid_cases() -> valid_cases_type;
  static auto invalid_cases() -> invalid_cases_type;
};

TYPED_TEST_CASE_P(ParseFixture);

TYPED_TEST_P(ParseFixture, ValidDataCases)
{
  for (const auto &test_case : TestFixture::valid_cases()) {
    SCOPED_TRACE(test_case.first);

    ASSERT_EQ(test_case.second, parse<TypeParam>(test_case.first));
  }
}

TYPED_TEST_P(ParseFixture, InvalidDataCases)
{
  for (const auto &test_case : TestFixture::invalid_cases()) {
    SCOPED_TRACE(test_case);

    ASSERT_THROW(parse<TypeParam>(test_case), parse_error);
  }
}

REGISTER_TYPED_TEST_CASE_P(ParseFixture,
  ValidDataCases,
  InvalidDataCases);

} // namespace gxy

#endif // TEST_COMPONENTS_PARSE_FIXTURE_H

