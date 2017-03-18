#include "ktouchcpplessonscreatorcourse.h"

#include <algorithm>
#include <cassert>
#include <sstream>

#include "ktouchcpplessonscreatorhelper.h"

void ribi_ktclc_course_test() noexcept
{
  //Trigger lessons
  {
    constexpr int rng_seed = 42;
    std::mt19937 rng_engine(rng_seed);
    const lessons a(rng_engine);
    assert(!a.to_xml().empty());
  }
  {
    constexpr int rng_seed = 42;
    const course a(rng_seed);
    assert(!a.to_xml().empty());
  }
}
