#ifndef AST_ENTITY_H
#define AST_ENTITY_H

#include "ast/component.h"

#include <string>
#include <vector>

namespace gxy::ast {

// A representation of an entity in the AST. Basically consists of a name and some components.
class entity
{
public:
  std::string name;
  std::vector<component> components;
};

} // namespace gxy::ast

#endif // AST_ENTITY_H

