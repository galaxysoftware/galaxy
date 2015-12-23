#ifndef COMPONENT_TRANSFORM_H
#define COMPONENT_TRANSFORM_H

#include "component/empty_data.h"
#include "component/name.h"

#include <glm/vec3.hpp>

namespace gxy::components {

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
static auto name<transform> = "transform";

} // namespace gxy::components

#endif // COMPONENT_TRANSFORM_H

