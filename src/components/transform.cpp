#include "components/transform.h"

#include "config/yaml/vec3.h"

#include <yaml-cpp/yaml.h>

namespace gxy {
namespace components {

transform::data::data(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale)
: translate(std::move(translate)),
  rotate(std::move(rotate)),
  scale(std::move(scale))
{
}

auto transform::data::operator==(const data &o) const -> bool
{
  return translate == o.translate
    && rotate == o.rotate
    && scale == o.scale;
}

auto transform::data::operator!=(const data &o) const -> bool
{
  return ! (*this == o);
}

} // namespace components

template <>
auto parse<components::transform::data>(const YAML::Node &node)
  -> components::transform::data
{
  assert(node.IsMap());
  assert(node.size() == 3);

  return {
    node["translate"].as<glm::vec3>(),
    node["rotate"].as<glm::vec3>(),
    node["scale"].as<glm::vec3>()
  };
}

} // namespace gxy

