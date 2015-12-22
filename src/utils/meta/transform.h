#ifndef UTILS_META_TRANSFORM_H
#define UTILS_META_TRANSFORM_H

#include "utils/meta/typelist.h"

namespace gxy::meta {

// Metafunction that takes a meta::typelist and transforms each type using Fn.
template<typename List, template<typename> class Fn>
struct transform;

template<typename ...List, template<typename> class Fn>
struct transform<typelist<List...>, Fn>
{
  using type = typelist<Fn<List>...>;
};

template<typename List, template<typename> class Fn>
using transform_t = typename transform<List, Fn>::type;

} // namespace gxy::meta

#endif // UTILS_META_TRANSFORM_H

