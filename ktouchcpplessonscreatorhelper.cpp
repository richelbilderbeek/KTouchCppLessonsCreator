#include "ktouchcpplessonscreatorhelper.h"

#include <set>
#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "testtimer.h"
#include "trace.h"

ribi::ktclc::helper::helper() noexcept
{
  #ifndef NDEBUG
  test();
  #endif
}

int ribi::ktclc::helper::calculate_score(
  const std::string& s,
  const std::string& desired_characters
) const noexcept
{
  //count the number of desired characters in s
  return std::accumulate(
    std::begin(s),
    std::end(s),
    0,
    [desired_characters](const int sum, const char c)
    {
      return sum
        + (helper().is_desired(c,desired_characters) ? 1 : 0)
      ;
    }
  );

}

std::string ribi::ktclc::helper::convert_to_escape(const char c) const noexcept
{
  std::string s;
  switch (c)
  {
    case '<' : s+="&lt;"  ; break;
    case '>' : s+="&gt;"  ; break;
    case '&' : s+="&amp;" ; break;
    case '\'': s+="&apos;"; break;
    case '\"': s+="&quot;"; break;
    default  : s+=c       ; break;
  }
  return s;
}

std::string ribi::ktclc::helper::convert_to_escape(const std::string& s) const noexcept
{
  std::string t;
  //Cannot use std::transform here, as a std::string cannot be back_inserted to a std::string
  for (const auto c: s)
  {
    t += helper().convert_to_escape(c);
  }
  return t;
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
  return "1.1";
}

std::vector<std::string> ribi::ktclc::helper::get_version_history() noexcept
{
  return {
    "2015-02-18: version 1.0: collected function used in KTouchCppLessonsCreator 1.0 in this class"
    "2015-02-18: version 1.1: added convert_to_escape"
  };
}

bool ribi::ktclc::helper::has_forbidden(const std::string& s) const noexcept
{
  const std::set<char> forbidden = { '<', '>', '&', '/', '"', '\'' };

  const auto iter = std::find_if(
    std::begin(s),
    std::end(s),
    [forbidden](const char c)
    {
      return forbidden.count(c) == 1;
    }
  );
  return iter != std::end(s);
}

//Is the character desired
bool ribi::ktclc::helper::is_desired(
  const char c,
  const std::string& desired_characters
) const noexcept
{
  return std::find(
    std::begin(desired_characters),
    std::end(desired_characters),
    c
  ) != std::end(desired_characters);
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
  //does_fit
  {
    assert( h.does_fit("a","a"));
    assert(!h.does_fit("b","a"));
    assert( h.does_fit("a","ab"));
    assert( h.does_fit("b","ab"));
    assert( h.does_fit("a","ba"));
    assert( h.does_fit("b","ba"));
  }
  //has_forbidden
  {
    assert(!h.has_forbidden("static_cast"));
    assert( h.has_forbidden("1 < 2"));
    assert( h.has_forbidden("1 > 2"));
    assert( h.has_forbidden("1 & 2"));
    assert( h.has_forbidden("1 / 2"));
    assert( h.has_forbidden("1 \" 2"));
    assert( h.has_forbidden("1 \' 2"));
  }
  //convert_to_escape
  {
    assert(h.convert_to_escape('a') == "a");
    assert(h.convert_to_escape('A') == "A");
    assert(h.convert_to_escape('!') == "!");
    assert(h.convert_to_escape('<') == "&lt;");
    assert(h.convert_to_escape('>') == "&gt;");
    assert(h.convert_to_escape('&') == "&amp;");
    assert(h.convert_to_escape('\'') == "&apos;");
    assert(h.convert_to_escape('\"') == "&quot;");
  }
  //convert_to_escape
  {
    assert(h.convert_to_escape("a") == "a");
    assert(h.convert_to_escape("A") == "A");
    assert(h.convert_to_escape("!") == "!");
    assert(h.convert_to_escape("<") == "&lt;");
    assert(h.convert_to_escape(">") == "&gt;");
    assert(h.convert_to_escape("&") == "&amp;");
    assert(h.convert_to_escape("\'") == "&apos;");
    assert(h.convert_to_escape("\"") == "&quot;");
  }
  //is_desired
  {
    assert( h.is_desired('a' ,"a"));
    assert( h.is_desired('a' ,"ab"));
    assert(!h.is_desired('a' ,"bc"));
  }
  //calculate_score
  {
    //calculate_score(s,desired)
    assert(h.calculate_score("a","a") == 1);
    assert(h.calculate_score("a","b") == 0);
    assert(h.calculate_score("aa","a") == 2);
    assert(h.calculate_score("aa","b") == 0);
    assert(h.calculate_score("ab","ab") == 2);
    assert(h.calculate_score("ab","abcd") == 2);
    assert(h.calculate_score("abcd","cd") == 2);
    assert(h.calculate_score("" ,"") == 0);
    assert(h.calculate_score("a" ,"") == 0);
    assert(h.calculate_score("" ,"a") == 0);
  }
}
#endif
