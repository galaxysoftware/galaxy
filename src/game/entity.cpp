#include "game/entity.h"

#include "config/ast/entity.h"

#include <boost/range/adaptor/transformed.hpp>

#include <boost/range/iterator_range.hpp>

namespace gxy {

entity::entity(std::string name, std::vector<component> components)
: name(std::move(name)),
  components(std::move(components))
{
}

auto entity::operator==(const entity &o) const -> bool
{
  return name == o.name
    && components == o.components;
}

auto entity::operator!=(const entity &o) const -> bool
{
  return ! (*this == o);
}

auto make_entity(const ast::entity &e) -> entity
{
  using boost::adaptors::transformed;

  auto components(e.components | transformed(make_component));
  return { e.name, boost::copy_range<std::vector<component>>(std::move(components)) };
}

} // namespace gxy

