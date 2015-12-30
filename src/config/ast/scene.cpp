#include "config/ast/scene.h"

#include <yaml-cpp/yaml.h>

namespace gxy {

template <>
auto parse<ast::scene>(const YAML::Node &node) -> ast::scene
{
  assert(node["entities"]);
  assert(node["entities"].IsSequence());

  ast::scene scene;
  scene.reserve(node["entities"].size());

  for (const auto &entity : node["entities"]) {
    scene.push_back(parse<ast::entity>(entity));
  }

  return scene;
}

} // namespace gxy

