#ifndef COMPONENT_COMPONENT_H
#define COMPONENT_COMPONENT_H

#include "components/background.h"
#include "components/transform.h"

#include "utils/meta/typelist.h"

namespace gxy::components {

// List of all of the supported components.
using list = meta::typelist<
  components::background,
  components::transform
>;

} // namespace gxy::components

#endif // COMPONENT_COMPONENT_H

