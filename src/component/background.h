#ifndef COMPONENTS_BACKGROUND_H
#define COMPONENTS_BACKGROUND_H

#include "component/name.h"

#include "component/utils/empty_data.h"

#include "config/parse.h"

#include <glm/vec3.hpp>

namespace gxy {
namespace components {

// The background component is responsible for providing a solid colour behind the scene.
class background
{
public:
  using data = empty_data;

  struct const_data
  {
    const_data(glm::vec3 colour);

    glm::vec3 colour;

    auto operator==(const const_data &o) const -> bool;
    auto operator!=(const const_data &o) const -> bool;
  };

};

// Name of node.
template <>
static std::string name<background> = "background";

} // namespace components

// Transform a YAML node into component data.
template <>
auto parse<components::background::const_data>(const YAML::Node &)
  -> components::background::const_data;

} // namespace gxy

#endif // COMPONENTS_BACKGROUND_H

