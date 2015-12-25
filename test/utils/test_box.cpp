#include "utils/box.h"

#include <type_traits>

using namespace gxy;

struct not_default_constructible
{
  not_default_constructible() = delete;
};

static_assert(std::is_default_constructible<box<not_default_constructible>>{});

struct uncopyable
{
  uncopyable(const uncopyable &) = delete;
  uncopyable &operator=(const uncopyable &) = delete;
};

static_assert(std::is_copy_constructible<box<uncopyable>>{});

// Check type is as expected.
static_assert(std::is_same<int, box<int>::type>{});

auto main() -> int
{
  return 0;
}

