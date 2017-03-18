#include "ktouchcpplessonscreatorhelper.h"

#include <numeric>
#include <set>
#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

ribi::ktclc::helper::helper() noexcept
{

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


std::vector<std::string> ribi::ktclc::helper::cap_at_sum_length(
  std::vector<std::string> v,
  const int sum_length
) const noexcept
{
  //Keep the first n_characters_per_line chars of words
  const int sz = static_cast<int>(v.size());
  int sum = 0;
  for (int i=0; i!=sz; ++i)
  {
    assert(i >= 0);
    assert(i < static_cast<int>(v.size()));
    sum += static_cast<int>(v[i].size());
    if (sum > sum_length)
    {
      v.resize(i);
      break;
    }
    if (sum == sum_length)
    {
      assert(i + 1 <= static_cast<int>(v.size()));
      v.resize(i + 1);
      break;
    }
  }
  return v;
}

std::string ribi::ktclc::helper::concatenate(const std::vector<std::string>& v,const std::string seperator) const noexcept
{
  std::string result;
  std::for_each(
    std::begin(v),
    std::end(v),
    [&result, seperator](const std::string& s)
    {
      result += (s + seperator);
    }
  );
  //Remove trailing seperator
  assert(result.size() >= seperator.size());
  result.resize(result.size() - seperator.size());

  return result;
}

std::string ribi::ktclc::helper::convert_to_escape(const char c) const noexcept
{
  std::string s;
  switch (c)
  {
    case '<' : s+="\\<"  ; break;
    //case '<' : s+="&lt;"  ; break;
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

std::string ribi::ktclc::helper::enumerate(const std::string& s) const noexcept
{
  if (s.size() <= 1)
  {
    // "" -> ""
    // "A" -> "A"
    return s;
  }
  if (s.size() == 2)
  {
    return s[0] + std::string(" and ") + s[1];
  }
  const int n_commas = s.size() - 2;
  std::string t;
  t += s[0];
  for (int i=0; i!=n_commas; ++i)
  {
    t += std::string(", ") + s[i+1];
  }
  t += " and ";
  t += s.back();
  return t;
}

int ribi::ktclc::helper::get_sum_length(
  const std::vector<std::string>& v
) const noexcept
{
   return std::accumulate(
    std::begin(v),
    std::end(v),
    0,
    [](int& init, const std::string& s)
    {
      return init + static_cast<int>(s.size());
    }
  );
}

std::string ribi::ktclc::helper::get_version() noexcept
{
  return "1.2";
}

std::vector<std::string> ribi::ktclc::helper::get_version_history() noexcept
{
  return {
    "2015-02-18: version 1.0: collected function used in KTouchCppLessonsCreator 1.0 in this class"
    "2015-10-31: version 1.1: added convert_to_escape"
    "2015-10-31: version 1.2: added is_desired, calculate_score, enumerate, cap_at_sum_length, get_sum_length"
  };
}

bool ribi::ktclc::helper::has_forbidden(const std::string& s) const noexcept
{
  const std::set<char> forbidden = {
    '<',
    '>',
    '&',
    '"',
    '\''
  };

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
