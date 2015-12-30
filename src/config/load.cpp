#include "config/load.h"

#include <yaml-cpp/yaml.h>

namespace gxy {

auto load(const boost::filesystem::path &config)
  -> std::vector<ast::entity>
{
  const auto yaml(YAML::LoadFile(config.string()));

  assert(yaml["entities"]);
  assert(yaml["entities"].IsSequence());

  std::vector<ast::entity> entities;
  entities.reserve(yaml["entities"].size());

  for (const auto &entity : yaml["entities"]) {
    entities.push_back(parse<ast::entity>(entity));
  }

  return entities;
}

} // namespace gxy

