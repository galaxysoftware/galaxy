#ifndef UTILS_META_APPLY_H
#define UTILS_META_APPLY_H

#include "utils/meta/typelist.h"

namespace gxy::meta {

// Metafunction that takes a meta::typelist and applys the types into a new container.
template<template<typename...> class C, typename List>
struct apply;

template<template<typename...> class C, typename...List>
struct apply<C, typelist<List...>>
{
  using type = C<List...>;
};

template<template<typename...> class C, typename List>
using apply_t = typename apply<C, List>::type;

} // namespace gxy::meta

#endif // UTILS_META_APPLY_H

