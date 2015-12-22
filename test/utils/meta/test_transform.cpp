#include "utils/meta/transform.h"

#include <string>

using namespace gxy;

using empty_list = meta::typelist<>;
using single_list = meta::typelist<int>;
using multi_list = meta::typelist<int, std::string>;

template <typename T>
struct box{};

template <typename List>
using uut = meta::transform_t<List, box>;

static_assert(std::is_same<uut<empty_list>, meta::typelist<>>::value);
static_assert(std::is_same<uut<single_list>, meta::typelist<box<int>>>::value);
static_assert(std::is_same<uut<multi_list>, meta::typelist<box<int>, box<std::string>>>::value);

int main()
{
  return 0;
}


