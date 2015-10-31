#include "ktouchcpplessonscreatorhelper.h"

#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "testtimer.h"

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

std::string ribi::ktclc::helper::get_version() noexcept
{
  return "1.0";
}

std::vector<std::string> ribi::ktclc::helper::get_version_history() noexcept
{
  return {
    "2015-02-18: version 1.0: collected function used in KTouchCppLessonsCreator 1.0 in this class"
  };
}

#ifndef NDEBUG
void ribi::ktclc::helper::test() noexcept
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  const test_timer my_test_timer(__func__,__FILE__,1.0);
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