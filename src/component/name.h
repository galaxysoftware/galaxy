#ifndef COMPONENT_NAME_H
#define COMPONENT_NAME_H

#include <string>

namespace gxy {
namespace components {

// Text representation of a component. Used as a key in the config file.
template <typename T>
static std::string name;

} // namespace components
} // namespace gxy

#endif // COMPONENT_NAME_H

