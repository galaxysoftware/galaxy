#ifndef COMPONENT_TRANSFORM_H
#define COMPONENT_TRANSFORM_H

#include "components/empty_data.h"
#include "components/name.h"

#include "config/parse.h"

#include <glm/vec3.hpp>

namespace gxy {
namespace components {

// The transform component is responsible for describing an entity's position in space.
class transform
{
public:
  struct data
  {
    data(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale);

    glm::vec3 translate;
    glm::vec3 rotate;
    glm::vec3 scale;

    auto operator==(const data &o) const -> bool;
    auto operator!=(const data &o) const -> bool;
  };

  using const_data = empty_data;
};

// Name of node.
template <>
static std::string name<transform> = "transform";

} // namespace components

// Transform a YAML node into component data.
template <>
auto parse<components::transform::data>(const YAML::Node &)
  -> components::transform::data;

template <>
auto parse<components::transform::const_data>(const YAML::Node &)
  -> components::transform::const_data;

} // namespace gxy

#endif // COMPONENT_TRANSFORM_H

