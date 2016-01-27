#include "component/utils/empty_data.h"

#include "config/parse_error.h"

#include "utils/throw_if.h"

#include <yaml-cpp/yaml.h>

namespace gxy {

template <>
auto parse<components::empty_data>(const YAML::Node &node)
  -> components::empty_data
{
  throw_if<parse_error>(! node.IsMap());
  throw_if<parse_error>(node.size() != 0);

  return {};
}

} // namespace gxy

