#include "game/scene.h"

#include <boost/range/adaptor/transformed.hpp>

#include <boost/range/iterator_range.hpp>

namespace gxy {

auto make_scene(const ast::scene &s) -> scene
{
  return boost::copy_range<scene>(s | boost::adaptors::transformed(make_entity));
}

} // namespace gxy

