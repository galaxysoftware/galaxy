#ifndef AST_COMPONENT_H
#define AST_COMPONENT_H

#include "components/list.h"

#include "utils/meta/apply.h"
#include "utils/meta/transform.h"

#include <eggs/variant.hpp>

namespace gxy::ast {

// A representation of a component in an initial state. Useful for building up a scene tree
// in an AST as stated by a configuration.
template <typename T>
class component_facade
{
public:
  typename T::data data;
  typename T::const_data const_data;
};

// An ast::component can be any of our defined components.
using component = meta::apply_t<eggs::variant,
  meta::transform_t<components::list, component_facade>>;

} // namespace gxy::ast

#endif // AST_COMPONENT_H

