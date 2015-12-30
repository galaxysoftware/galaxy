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
  component_facade<components::transform>
>;

static_assert(std::is_same<expected, component>{});

