#ifndef COMPONENT_PARSE_H
#define COMPONENT_PARSE_H

namespace YAML {

class Node;

} // namespace YAML

namespace gxy {
namespace components {

// Create a component from it's YAML form.
template <typename T>
auto parse(const YAML::Node &) -> T;

} // namespace components
} // namespace gxy

#endif // COMPONENT_PARSE_H

