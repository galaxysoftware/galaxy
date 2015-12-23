#include "load/ast/component.h"

using namespace gxy;

struct stub_component
{
  using data = int;
  using const_data = bool;
};

using uut = ast::component_facade<stub_component>;

// Check that the types of our data has successfully propagated into the facade.
static_assert(std::is_same<decltype(uut().data), int>{});
static_assert(std::is_same<decltype(uut().const_data), bool>{});

// All existing components should be accessible in our ast::component variant.
using expected = eggs::variant<
  ast::component_facade<components::transform>
>;

static_assert(std::is_same<expected, ast::component>{});

int main()
{
  return 0;
}

