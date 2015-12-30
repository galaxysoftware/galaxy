#ifndef CONFIG_PARSE_H
#define CONFIG_PARSE_H

namespace YAML {

class Node;

} // namespace YAML

namespace gxy {

// Create a component from it's YAML form.
template <typename T>
auto parse(const YAML::Node &) -> T;

} // namespace gxy

#endif // CONFIG_PARSE_H

