#include "ktouchcpplessonscreatorlesson.h"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <set>
#include <sstream>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "ktouchcpplessonscreatorhelper.h"
#include "ktouchcpplessonscreatorwordlist.h"

void ribi_ktclc_lesson_test() noexcept
{
  constexpr int rng_seed = 42;
  std::mt19937 rng_engine(rng_seed);
  const word_list a_word_list("abcdefghijklmnopqrstuvwxyz","ab",rng_engine);
  {
    const lesson a(
      "AB",
      "test title",
      rng_engine,
      a_word_list
    );
    assert(!a.to_xml().empty());
  }
}
