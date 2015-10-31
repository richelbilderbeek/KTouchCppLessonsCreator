#include "ktouchcpplessonscreatorhelper.h"

#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

ribi::ktclc::helper::helper() noexcept
{
  #ifndef NDEBUG
  test();
  #endif
}

std::string ribi::ktclc::helper::create_uuid() const noexcept
{
  std::stringstream s;
  s << "{" << boost::uuids::random_generator()() << "}";
  return s.str();
}

bool ribi::ktclc::helper::does_fit(const std::string& s, const std::string all) const noexcept
{
  const std::string t = sort(s);
  const std::string u = sort(all);
  std::string overlap;
  std::set_intersection(
    std::begin(t),
    std::end(t),
    std::begin(u),
    std::end(u),
    std::back_inserter(overlap)
  );
  return overlap.size() == s.size();
}

#ifndef NDEBUG
void ribi::ktclc::helper::test() noexcept
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  const helper h;
  //DoesFit
  {
    assert( h.does_fit("a","a"));
    assert(!h.does_fit("b","a"));
    assert( h.does_fit("a","ab"));
    assert( h.does_fit("b","ab"));
    assert( h.does_fit("a","ba"));
    assert( h.does_fit("b","ba"));
  }
}
#endif
