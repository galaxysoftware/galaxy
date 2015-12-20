#ifndef COMPONENT_TRANSFORM_H
#define COMPONENT_TRANSFORM_H

#include "component/name.h"
#include "component/empty_data.h"

#include <glm/vec3.hpp>

namespace gxy {
namespace components {

class transform
{
  struct data
  {
    glm::vec3 translate;
    glm::vec3 rotate;
    glm::vec3 scale;
  };

  using const_data = empty_data;
};

template <>
auto name<transform> = "transform";

} // namespace components
} // namespace gxy

#endif // COMPONENT_TRANSFORM_H

