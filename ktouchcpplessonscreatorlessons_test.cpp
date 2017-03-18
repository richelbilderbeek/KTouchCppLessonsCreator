#include "ktouchcpplessonscreatorlessons.h"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <sstream>

#include "ktouchcpplessonscreatorhelper.h"
#include "ktouchcpplessonscreatorwordlist.h"

void ribi::ktclc::lessons::test() noexcept
{
  constexpr int rng_seed = 42;
  std::mt19937 rng_engine(rng_seed);
  const lessons a(rng_engine);
  assert(!a.to_xml().empty());
}
