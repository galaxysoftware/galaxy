#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "game/component.h"

#include <string>
#include <vector>

namespace gxy {

namespace ast {

class entity;

} // namespace ast

// An entity in the game.
class entity
{
public:
  entity(std::string name, std::vector<component> components);

  auto operator==(const entity &o) const -> bool;
  auto operator!=(const entity &o) const -> bool;

  std::string name;
  std::vector<component> components;
};

// Factory function to create one from an AST representation.
auto make_entity(const ast::entity &) -> entity;

} // namespace gxy

#endif // GAME_ENTITY_H

