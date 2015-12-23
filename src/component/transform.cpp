#include "component/transform.h"

namespace gxy::components {

transform::data::data(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale)
: translate(std::move(translate)),
  rotate(std::move(rotate)),
  scale(std::move(scale))
{
}

auto transform::data::operator==(const data &o) const -> bool
{
  return translate == o.translate
    && rotate == o.rotate
    && scale == o.scale;
}

auto transform::data::operator!=(const data &o) const -> bool
{
  return ! (*this == o);
}

} // namespace gxy::components

