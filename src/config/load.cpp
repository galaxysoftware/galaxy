#include "config/load.h"

#include <yaml-cpp/yaml.h>

namespace gxy {

auto load(const boost::filesystem::path &config) -> ast::scene
{
  const auto yaml(YAML::LoadFile(config.string()));

  return parse<ast::scene>(yaml);
}

} // namespace gxy

