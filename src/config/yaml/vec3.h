#ifndef CONFIG_YAML_VEC3_H
#define CONFIG_YAML_VEC3_H

#include <glm/vec3.hpp>

#include <yaml-cpp/yaml.h>

namespace YAML {

// YAML parsing support for glm::vec3.
template <>
struct convert<glm::vec3>
{
  static auto decode(const Node &node, glm::vec3 &vec) -> bool;
};

// Definition.

inline
auto convert<glm::vec3>::decode(const Node &node, glm::vec3 &vec) -> bool
{
  if (! node.IsSequence() || node.size() != 3) {
    return false;
  }

  vec.x = node[0].as<float>();
  vec.y = node[1].as<float>();
  vec.z = node[2].as<float>();

  return true;
}

} // namespace YAML

#endif // CONFIG_YAML_VEC3_H
