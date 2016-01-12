#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "config/ast/scene.h"

#include "game/entity.h"

#include <vector>

namespace gxy {

// A scene is just a collection of entities.
using scene = std::vector<entity>;

// Factory function to create a scene from it's AST representation.
auto make_scene(const ast::scene &) -> scene;

} // namespace gxy

#endif // GAME_SCENE_H

