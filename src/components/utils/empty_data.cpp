#include "components/utils/empty_data.h"

#include <yaml-cpp/yaml.h>

namespace gxy {

template <>
auto parse<components::empty_data>(const YAML::Node &node)
  -> components::empty_data
{
  assert(node.size() == 0);
  return {};
}

} // namespace gxy

