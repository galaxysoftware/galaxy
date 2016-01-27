#include "components/background.h"

#include "config/yaml/vec3.h"

#include "config/parse_error.h"

#include "utils/throw_if.h"

#include <yaml-cpp/yaml.h>

namespace gxy {
namespace components {

background::const_data::const_data(glm::vec3 colour)
: colour(std::move(colour))
{
}

auto background::const_data::operator==(const const_data &o) const -> bool
{
  return colour == o.colour;
}

auto background::const_data::operator!=(const const_data &o) const -> bool
{
  return ! (*this == o);
}

} // namespace components

template <>
auto parse<components::background::const_data>(const YAML::Node &node)
  -> components::background::const_data
{
  throw_if<parse_error>(! node.IsMap());
  throw_if<parse_error>(node.size() != 1);

  return { node["colour"].as<glm::vec3>() };
}

} // namespace gxy

