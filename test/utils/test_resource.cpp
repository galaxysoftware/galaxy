#include "utils/resource.h"

using namespace gxy;

static_assert(std::is_same<resource<int>, std::unique_ptr<int, void(*)(int*)>>{});

auto main() -> int
{
  return 0;
}

