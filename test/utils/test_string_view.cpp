#include "utils/string_view.h"

static_assert(std::is_same<std::experimental::string_view, gxy::string_view>{});

auto main() -> int
{
  return 0;
}

