#include "game/component.h"

#include <gtest/gtest.h>

using namespace gxy;

struct stub_component
{
  using data = int;
  using const_data = bool;
};

using stub_uut = component_facade<stub_component>;

// Check that the types of our data has successfully propagated into the facade.
static_assert(std::is_same<decltype(std::declval<stub_uut>().current), int>{});
static_assert(std::is_same<decltype(std::declval<stub_uut>().next), int>{});
static_assert(std::is_same<decltype(std::declval<stub_uut>().const_data), bool>{});

// All existing components should be accessible in our ast::component variant.
using expected = eggs::variant<
  component_facade<components::background>,
  component_facade<components::transform>
>;

static_assert(std::is_same<expected, component>{});

struct Fixture : public ::testing::Test{};

TEST_F(Fixture, FacadeExpectedNextData)
{
  const stub_uut uut(42, true);
  ASSERT_EQ(42, uut.next);
}

TEST_F(Fixture, FacadeExpectedCurrentData)
{
  const stub_uut uut(42, true);
  ASSERT_EQ(42, uut.current);
}

TEST_F(Fixture, FacadeExpectedConstData)
{
  const stub_uut uut(42, true);
  ASSERT_EQ(true, uut.const_data);
}

TEST_F(Fixture, IsEqualSelf)
{
  const stub_uut uut(42, false);
  ASSERT_TRUE(uut == stub_uut(42, false));
}

TEST_F(Fixture, NotNotEqualSelf)
{
  const stub_uut uut(42, false);
  ASSERT_FALSE(uut != stub_uut(42, false));
}

TEST_F(Fixture, NotEqualDifferentData)
{
  const stub_uut uut(42, false);
  ASSERT_FALSE(uut == stub_uut(89, false));
}

TEST_F(Fixture, IsNotEqualDifferentData)
{
  const stub_uut uut(42, false);
  ASSERT_TRUE(uut != stub_uut(89, false));
}

TEST_F(Fixture, NotEqualDifferentConstData)
{
  const stub_uut uut(42, false);
  ASSERT_FALSE(uut == stub_uut(42, true));
}

TEST_F(Fixture, IsNotEqualDifferentConstData)
{
  const stub_uut uut(42, false);
  ASSERT_TRUE(uut != stub_uut(42, true));
}

struct MakeComponentFixture : public ::testing::Test{};

TEST_F(MakeComponentFixture, MakeTransform)
{
  components::transform::data data(glm::vec3(1, 2, 3), glm::vec3(4, 5, 6), glm::vec3(7, 8, 9));
  components::transform::const_data const_data;

  const ast::component_facade<components::transform> uut(data, const_data);

  const component_facade<components::transform> expected(data, const_data);
  ASSERT_EQ(component(expected), make_component(uut));
}

