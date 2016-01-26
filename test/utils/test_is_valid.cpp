#include "utils/is_valid.h"

struct has_type
{
  using type = int;
};

struct no_type{};

auto has_type_test(is_valid([](auto x) -> decltype((void) typename decltype(x)::type{}) {}));

static_assert(has_type_test(has_type{}), "");
static_assert(! has_type_test(no_type{}), "");

struct has_member
{
  auto member() -> int;
};

struct no_member{};

auto has_member_test(is_valid([](auto &&x) -> decltype(x.member()) {}));

static_assert(has_member_test(has_member{}), "");
static_assert(! has_member_test(no_member{}), "");

auto main() -> int
{
  return 0;
}

