#ifndef COMPONENT_NAME_H
#define COMPONENT_NAME_H

#include "utils/string_view.h"

namespace gxy {
namespace components {

// Text representation of a component. Used as a key in the config file.
template <typename T>
static gxy::string_view name;

} // namespace components
} // namespace gxy

#endif // COMPONENT_NAME_H

