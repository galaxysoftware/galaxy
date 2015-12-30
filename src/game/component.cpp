#include "game/component.h"

namespace gxy {

namespace {

class make_component_visitor
{
public:
  template <typename T>
  auto operator()(const T &) -> component;
};

template <typename T>
auto make_component_visitor::operator()(const T &component_data) -> component
{
  using type = typename T::type;
  return { component_facade<type>(component_data.data, component_data.const_data) };
}

} // unnamed namespace

auto make_component(const ast::component &c) -> component
{
  return eggs::variants::apply(make_component_visitor(), c);
}

} // namespace gxy

