#include "utils/meta/apply.h"

#include <string>

using namespace gxy;

using empty_list = meta::typelist<>;
using single_list = meta::typelist<int>;
using multi_list = meta::typelist<int, std::string>;

template <typename List>
using uut = typename meta::apply<std::tuple, List>::type;

static_assert(std::is_same<uut<empty_list>, std::tuple<>>::value);
static_assert(std::is_same<uut<single_list>, std::tuple<int>>::value);
static_assert(std::is_same<uut<multi_list>, std::tuple<int, std::string>>::value);

int main()
{
  return 0;
}

