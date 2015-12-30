#include "game/entity.h"

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

} // namespace gxy

